import argparse
from pathlib import Path

import pandas as pd
import matplotlib.pyplot as plt


def get_circuit_name(csv_path: Path):
    """
    report_c1355.csv -> circuit1355
    其他文件名 -> 文件名本身
    """
    stem = csv_path.stem
    if stem.startswith("report_c"):
        return "circuit" + stem.replace("report_c", "")
    return stem


def normalize_values(values):
    """
    普通归一化：current / baseline
    baseline = values[0]
    """
    baseline = values[0]
    if baseline == 0:
        raise ValueError("baseline 为 0，无法归一化")
    return [v / baseline for v in values]


def speedup_values(values):
    """
    Makespan speedup：baseline / current
    baseline = values[0]
    """
    baseline = values[0]
    if baseline == 0:
        raise ValueError("baseline 为 0，无法计算 speedup")
    out = []
    for v in values:
        if v == 0:
            raise ValueError("存在值为 0，无法计算 speedup")
        out.append(baseline / v)
    return out


def compute_ylim(values, include_one=True):
    """
    自动设置更适合单栏 1x3 图的 y 轴范围
    """
    ymin = min(values)
    ymax = max(values)

    if include_one:
        ymin = min(ymin, 1.0)
        ymax = max(ymax, 1.0)

    if ymin == ymax:
        if ymax == 0:
            return 0, 1
        return ymin * 0.9, ymax * 1.1

    lower = ymin - 0.12 * (ymax - ymin)
    upper = ymax + 0.12 * (ymax - ymin)

    if include_one and lower > 0.92:
        lower = 0.92
    if lower < 0:
        lower = 0

    return lower, upper


def plot_one_csv(csv_file, output=None):
    csv_path = Path(csv_file)

    df = pd.read_csv(csv_path)
    df.columns = df.columns.str.strip()

    circuit_name = get_circuit_name(csv_path)

    labels = [
        "FIFO\nBatchBlocking\nBatchSize32",
        "Level",
        "Fused\nLevel\n256",
        "Fused\nLevel\n1024",
        "Fused\nLevel\n2048",
    ]

    # Excel 第2/26/27/28/29 行 -> pandas iloc[0/24/25/26/27]
    row_indices = [0, 24, 25, 26, 27]

    if max(row_indices) >= len(df):
        raise ValueError(
            f"{csv_file} 数据行数不够。需要至少 {max(row_indices) + 1} 行数据，"
            f"但当前只有 {len(df)} 行数据。"
        )

    required_columns = [
        "Makespan (ms)",
        "GPU Util (%)",
        "Throughput (gates/s)",
    ]

    for col_name in required_columns:
        if col_name not in df.columns:
            raise ValueError(
                f"CSV 中找不到列: {col_name}\n当前列名有: {list(df.columns)}"
            )

    colors = [
        "#A9CCE3",  # FIFO baseline
        "#F4B6B6",  # Level
        "#D5E8C2",  # Fused 256
        "#A9D18E",  # Fused 1024
        "#6AA84F",  # Fused 2048
    ]

    # 单栏 1x3 推荐参数
    fig, axes = plt.subplots(1, 3, figsize=(7.0, 2.35))
    bar_width = 0.42
    title_fs = 8
    ylabel_fs = 7
    tick_fs = 6
    x_tick_fs = 5.8

    # 1) Makespan -> Speedup
    makespan_raw = df.iloc[row_indices]["Makespan (ms)"].astype(float).tolist()
    makespan_plot = speedup_values(makespan_raw)

    ax = axes[0]
    ax.bar(labels, makespan_plot, color=colors, edgecolor="white", linewidth=0.5, width=bar_width)
    ax.axhline(1.0, color="gray", linestyle="--", linewidth=0.8, alpha=0.8)
    ax.set_title(f"({circuit_name}) Makespan Speedup", fontsize=title_fs, fontweight="bold", pad=3)
    ax.set_ylabel("Normalized Makespan Speedup", fontsize=ylabel_fs)
    ax.grid(axis="y", alpha=0.22, linewidth=0.5)
    ax.set_axisbelow(True)
    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    ax.tick_params(axis="x", labelrotation=0, labelsize=x_tick_fs, pad=1)
    ax.tick_params(axis="y", labelsize=tick_fs)
    ymin, ymax = compute_ylim(makespan_plot, include_one=True)
    ax.set_ylim(ymin, ymax)

    # 2) GPU Util -> Normalized
    gpu_raw = df.iloc[row_indices]["GPU Util (%)"].astype(float).tolist()
    gpu_plot = normalize_values(gpu_raw)

    ax = axes[1]
    ax.bar(labels, gpu_plot, color=colors, edgecolor="white", linewidth=0.5, width=bar_width)
    ax.axhline(1.0, color="gray", linestyle="--", linewidth=0.8, alpha=0.8)
    ax.set_title(f"({circuit_name}) GPU Util", fontsize=title_fs, fontweight="bold", pad=3)
    ax.set_ylabel("Normalized GPU Util (%)", fontsize=ylabel_fs)
    ax.grid(axis="y", alpha=0.22, linewidth=0.5)
    ax.set_axisbelow(True)
    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    ax.tick_params(axis="x", labelrotation=0, labelsize=x_tick_fs, pad=1)
    ax.tick_params(axis="y", labelsize=tick_fs)
    ymin, ymax = compute_ylim(gpu_plot, include_one=True)
    ax.set_ylim(ymin, ymax)

    # 3) Throughput -> Normalized
    throughput_raw = df.iloc[row_indices]["Throughput (gates/s)"].astype(float).tolist()
    throughput_plot = normalize_values(throughput_raw)

    ax = axes[2]
    ax.bar(labels, throughput_plot, color=colors, edgecolor="white", linewidth=0.5, width=bar_width)
    ax.axhline(1.0, color="gray", linestyle="--", linewidth=0.8, alpha=0.8)
    ax.set_title(f"({circuit_name}) Throughput", fontsize=title_fs, fontweight="bold", pad=3)
    ax.set_ylabel("Normalized Throughput (gates/s)", fontsize=ylabel_fs)
    ax.grid(axis="y", alpha=0.22, linewidth=0.5)
    ax.set_axisbelow(True)
    ax.spines["top"].set_visible(False)
    ax.spines["right"].set_visible(False)
    ax.tick_params(axis="x", labelrotation=0, labelsize=x_tick_fs, pad=1)
    ax.tick_params(axis="y", labelsize=tick_fs)
    ymin, ymax = compute_ylim(throughput_plot, include_one=True)
    ax.set_ylim(ymin, ymax)

    plt.tight_layout(w_pad=0.8)

    if output is None:
        output = f"{csv_path.stem}_level_summary_singlecol_1x3.png"

    plt.savefig(output, dpi=600, bbox_inches="tight", pad_inches=0.02)
    print(f"图像已保存到: {output}")


def main():
    parser = argparse.ArgumentParser(
        description="从单个 CSV 生成适合单栏论文的一张 1x3 子图：Makespan Speedup / Normalized GPU Util / Normalized Throughput"
    )
    parser.add_argument("csv_file", help="输入 CSV 文件路径")
    parser.add_argument(
        "--output",
        default=None,
        help="输出图片名。默认是 <csv文件名>_level_summary_singlecol_1x3.png",
    )
    args = parser.parse_args()
    plot_one_csv(csv_file=args.csv_file, output=args.output)


if __name__ == "__main__":
    main()
