import argparse
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


def resolve_column(df, column_arg):
    """
    支持两种写法：
    1. 列字母，如 A / D / F
    2. 列名，如 'Makespan (ms)'
    """
    column_arg = column_arg.strip()

    if column_arg.isalpha():
        col = column_arg.upper()
        idx = 0
        for ch in col:
            idx = idx * 26 + (ord(ch) - ord("A") + 1)
        idx -= 1

        if idx < 0 or idx >= len(df.columns):
            raise ValueError(f"列字母 {column_arg} 超出 CSV 范围")
        return idx

    if column_arg not in df.columns:
        raise ValueError(
            f"找不到列名: {column_arg}\n当前列名有: {list(df.columns)}"
        )
    return df.columns.get_loc(column_arg)


def parse_yrange(yrange_str):
    """
    解析形如 "0.4-1.6" 或 "0.4,1.6" 的 y 轴范围。
    """
    if yrange_str is None:
        return None

    s = yrange_str.strip()

    if "," in s:
        parts = s.split(",")
    else:
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


def parse_figsize(figsize_str):
    """
    解析形如 "3.1,2.1" 的 figure size。
    """
    if figsize_str is None:
        return (3.2, 2.25)

    parts = figsize_str.split(",")
    if len(parts) != 2:
        raise ValueError('figsize 格式错误，应该写成类似 "3.2,2.25"')

    return (float(parts[0].strip()), float(parts[1].strip()))


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

    return [v / baseline for v in group_values]


def main():
    parser = argparse.ArgumentParser(
        description="从 CSV 指定列第2行开始读取24个值，按 BatchNonBlocking-32 做 current/baseline 归一化后生成无图例柱状图"
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
    parser.add_argument(
        "--figsize",
        default="3.2,2.25",
        help='图片尺寸，单位 inch。默认 "3.2,2.25"，适合一整行放三张图'
    )
    parser.add_argument(
        "--dpi",
        type=int,
        default=600,
        help="输出图片 dpi，默认 600"
    )

    args = parser.parse_args()

    df = pd.read_csv(args.csv_file)
    df.columns = df.columns.str.strip()

    col_idx = resolve_column(df, args.column)

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
    # 画图参数：紧凑版，适合两栏论文一整行放三张
    # =========================
    bar_width = 0.13
    group_gap = 1.0

    colors_nonblocking = ["#D6EAF8", "#A9CCE3", "#5499C7"]
    colors_blocking    = ["#D5E8C2", "#A9D18E", "#6AA84F"]

    figsize = parse_figsize(args.figsize)
    fig, ax = plt.subplots(figsize=figsize)
    num_bars_per_group = 6

    x_centers = np.arange(len(methods)) * group_gap

    for i, method in enumerate(methods):
        center = x_centers[i]
        offsets = (np.arange(num_bars_per_group) - (num_bars_per_group - 1) / 2) * bar_width

        values_group = data[method]["BatchNonBlocking"] + data[method]["BatchBlocking"]
        colors_group = colors_nonblocking + colors_blocking

        ax.bar(
            center + offsets,
            values_group,
            width=bar_width * 0.92,
            color=colors_group,
            edgecolor="white",
            linewidth=0.45
        )

    ax.axhline(1.0, color="gray", linestyle="--", linewidth=0.75, alpha=0.75)

    ax.set_xticks(x_centers)
    ax.set_xticklabels(methods, fontsize=7, fontweight="bold")

    ax.set_ylabel(args.ylabel, fontsize=7)
    ax.set_title(args.title, fontsize=8.5, fontweight="bold", pad=3)

    ax.grid(axis="y", alpha=0.23, linewidth=0.5)
    ax.set_axisbelow(True)

    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)

    ax.tick_params(axis="y", labelsize=6)
    ax.tick_params(axis="x", labelsize=7, pad=1)

    yrange = parse_yrange(args.yrange)
    if yrange is not None:
        ax.set_ylim(yrange[0], yrange[1])
    else:
        ymin = min(plotted_values_all)
        ymax = max(plotted_values_all)
        ymin = min(ymin, 1.0)
        ymax = max(ymax, 1.0)

        lower = ymin - 0.12 * (ymax - ymin)
        upper = ymax + 0.12 * (ymax - ymin)
        if lower < 0:
            lower = 0
        if lower > 0.9:
            lower = 0.9
        ax.set_ylim(lower, upper)

    # 不画 legend。legend 单独用 make_scheduling_legend.py 生成。
    plt.tight_layout(pad=0.4)
    plt.savefig(args.output, dpi=args.dpi, bbox_inches="tight", pad_inches=0.015)
    print(f"图像已保存到: {args.output}")
    print("归一化方式: current/baseline")
    print("说明: 图中不包含 legend；请用 plot_scheduling_legend.py 单独生成 legend.png。")


if __name__ == "__main__":
    main()
