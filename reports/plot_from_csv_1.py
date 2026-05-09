import argparse
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Patch


def resolve_column(df, column_arg):
    """
    支持两种写法：
    1. 列字母，如 A / D / F
    2. 列名，如 'Makespan (ms)'
    """
    column_arg = column_arg.strip()

    # 如果是单个或多个字母，如 A, D, AA
    if column_arg.isalpha():
        col = column_arg.upper()
        idx = 0
        for ch in col:
            idx = idx * 26 + (ord(ch) - ord('A') + 1)
        idx -= 1  # 转成 0-based

        if idx < 0 or idx >= len(df.columns):
            raise ValueError(f"列字母 {column_arg} 超出 CSV 范围")
        return idx

    # 否则当作列名
    if column_arg not in df.columns:
        raise ValueError(
            f"找不到列名: {column_arg}\n当前列名有: {list(df.columns)}"
        )
    return df.columns.get_loc(column_arg)


def parse_yrange(yrange_str):
    """
    解析形如 "0.4-1.6" 的 y 轴范围。
    也支持负数，比如 "-1.0-2.0"。
    """
    if yrange_str is None:
        return None

    s = yrange_str.strip()

    # 优先支持逗号形式，例如 "0.4,1.6"
    if "," in s:
        parts = s.split(",")
    else:
        # 兼容 "0.4-1.6"。这里假设常用输入为非负范围。
        parts = s.split("-")

    if len(parts) != 2:
        raise ValueError('yrange 格式错误，建议写成 "0.4-1.6" 或 "0.4,1.6"')

    try:
        ymin = float(parts[0].strip())
        ymax = float(parts[1].strip())
    except ValueError:
        raise ValueError('yrange 格式错误，建议写成 "0.4-1.6" 或 "0.4,1.6"')

    if ymin >= ymax:
        raise ValueError("yrange 的下界必须小于上界")

    return ymin, ymax


def normalize_group_values(group_values):
    """
    group_values 的顺序来自 CSV：
    [BatchBlocking 32, 128, 512, BatchNonBlocking 32, 128, 512]

    baseline = BatchNonBlocking, BatchSize=32，也就是 group_values[3]

    归一化方式统一为 current / baseline。
    因此：
    - baseline 一定是 1.0
    - Makespan 图里，小于 1 表示更快；大于 1 表示更慢
    - GPU Util / Throughput 图里，大于 1 表示更高；小于 1 表示更低
    """
    baseline = group_values[3]

    if baseline == 0:
        raise ValueError("baseline 为 0，无法计算归一化值")

    normalized = []
    for v in group_values:
        normalized.append(v / baseline)

    return normalized


def main():
    parser = argparse.ArgumentParser(
        description="从 CSV 指定列第2行开始读取24个值，按 BatchNonBlocking-32 做 current/baseline 归一化后生成柱状图"
    )
    parser.add_argument("csv_file", help="输入 CSV 文件路径")
    parser.add_argument(
        "--column",
        required=True,
        help="要读取的列。可传列字母（如 D）或列名（如 'Makespan (ms)'）"
    )
    parser.add_argument(
        "--start-row",
        type=int,
        default=2,
        help="Excel 里的起始行号，默认 2（即从第2行开始读）"
    )
    parser.add_argument(
        "--num-values",
        type=int,
        default=24,
        help="读取多少个值，默认 24。不读取/绘制 Levelization"
    )
    parser.add_argument(
        "--output",
        default="output.png",
        help="输出图片文件名，默认 output.png"
    )
    parser.add_argument(
        "--title",
        default="Normalized Performance",
        help="图标题"
    )
    parser.add_argument(
        "--ylabel",
        default="Normalized value over BatchNonBlocking-32",
        help="Y 轴标题"
    )
    parser.add_argument(
        "--yrange",
        "-yrange",
        default=None,
        help='设置 y 轴范围，例如 "0.4-1.6" 或 "0.4,1.6"'
    )

    args = parser.parse_args()

    # 读取 CSV
    df = pd.read_csv(args.csv_file)
    df.columns = df.columns.str.strip()

    # 找到目标列
    col_idx = resolve_column(df, args.column)

    # CSV 第一行通常是表头。
    # 如果你说“从第2行开始”，那就对应数据区的第1行 => iloc[0]
    start_idx = args.start_row - 2
    end_idx = start_idx + args.num_values

    if start_idx < 0:
        raise ValueError("start-row 不能小于 2，因为默认第1行是表头")

    if end_idx > len(df):
        raise ValueError(
            f"数据不够：你要从第 {args.start_row} 行开始读 {args.num_values} 个值，"
            f"但 CSV 只有 {len(df)} 行数据（不含表头）"
        )

    values = df.iloc[start_idx:end_idx, col_idx].astype(float).tolist()

    if len(values) != 24:
        raise ValueError("当前脚本默认读取 24 个值：4 个 scheduler × 每组 6 个柱子，不读取 Levelization")

    methods = ["FIFO", "FaninPriority", "DepAware", "SJF"]

    # 你的 CSV 顺序通常是：
    # batch_blocking 32/128/512
    # batch_non-blocking 32/128/512
    data = {}
    plotted_values_all = []

    for i, method in enumerate(methods):
        raw_group_values = values[i * 6: (i + 1) * 6]
        normalized_group_values = normalize_group_values(raw_group_values)

        data[method] = {
            "BatchBlocking": normalized_group_values[0:3],
            "BatchNonBlocking": normalized_group_values[3:6],
        }
        plotted_values_all.extend(normalized_group_values)

    # =========================
    # 画图参数
    # =========================
    bar_width = 0.13
    group_gap = 1.0

    # 治愈系颜色
    colors_nonblocking = ["#D6EAF8", "#A9CCE3", "#5499C7"]
    colors_blocking    = ["#D5E8C2", "#A9D18E", "#6AA84F"]

    fig, ax = plt.subplots(figsize=(12, 5))
    num_bars_per_group = 6

    x_centers = np.arange(len(methods)) * group_gap

    for i, method in enumerate(methods):
        center = x_centers[i]
        offsets = (np.arange(num_bars_per_group) - (num_bars_per_group - 1) / 2) * bar_width

        # 图上画成：蓝色 non-blocking 在前，绿色 blocking 在后
        values_group = data[method]["BatchNonBlocking"] + data[method]["BatchBlocking"]
        colors_group = colors_nonblocking + colors_blocking

        ax.bar(
            center + offsets,
            values_group,
            width=bar_width * 0.92,
            color=colors_group,
            edgecolor="white",
            linewidth=0.8
        )

    # baseline = 1 的参考线
    ax.axhline(1.0, color="gray", linestyle="--", linewidth=1, alpha=0.7)

    # X轴
    ax.set_xticks(x_centers)
    ax.set_xticklabels(methods, fontsize=13, fontweight="bold")

    ax.set_ylabel(args.ylabel, fontsize=13)
    ax.set_title(args.title, fontsize=18, fontweight="bold")

    ax.grid(axis="y", alpha=0.25)
    ax.set_axisbelow(True)

    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)

    # y 轴范围：优先使用用户指定的 yrange，否则自动设置
    yrange = parse_yrange(args.yrange)
    if yrange is not None:
        ax.set_ylim(yrange[0], yrange[1])
    else:
        ymax = max(max(plotted_values_all) * 1.15, 1.15)
        ax.set_ylim(0, ymax)

    legend_handles = [
        Patch(facecolor=colors_nonblocking[0], label="BatchNonBlocking, BatchSize=32"),
        Patch(facecolor=colors_nonblocking[1], label="BatchNonBlocking, BatchSize=128"),
        Patch(facecolor=colors_nonblocking[2], label="BatchNonBlocking, BatchSize=512"),
        Patch(facecolor=colors_blocking[0], label="BatchBlocking, BatchSize=32"),
        Patch(facecolor=colors_blocking[1], label="BatchBlocking, BatchSize=128"),
        Patch(facecolor=colors_blocking[2], label="BatchBlocking, BatchSize=512"),
    ]

    ax.legend(
        handles=legend_handles,
        frameon=False,
        bbox_to_anchor=(1.02, 1),
        loc="upper left",
        fontsize=10
    )

    plt.tight_layout()
    plt.savefig(args.output, dpi=300, bbox_inches="tight")
    print(f"图像已保存到: {args.output}")
    print("归一化方式: current/baseline")
    print("说明: Makespan 图中，小于 1 表示更快；GPU Util / Throughput 图中，大于 1 表示更高。")


if __name__ == "__main__":
    main()
