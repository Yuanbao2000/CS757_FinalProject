import argparse
import matplotlib.pyplot as plt
from matplotlib.patches import Patch


def main():
    parser = argparse.ArgumentParser(
        description="生成 scheduling 图共用的一行横向 legend"
    )
    parser.add_argument(
        "--output",
        default="legend.png",
        help="输出 legend 图片名，默认 legend.png"
    )
    parser.add_argument(
        "--figsize",
        default="7.0,0.35",
        help='图片尺寸，单位 inch。默认 "7.0,0.35"'
    )
    parser.add_argument(
        "--dpi",
        type=int,
        default=600,
        help="输出 dpi，默认 600"
    )

    args = parser.parse_args()

    w, h = [float(x.strip()) for x in args.figsize.split(",")]

    colors_nonblocking = ["#D6EAF8", "#A9CCE3", "#5499C7"]
    colors_blocking    = ["#D5E8C2", "#A9D18E", "#6AA84F"]

    handles = [
        Patch(facecolor=colors_nonblocking[0], label="BatchNonBlocking, BatchSize=32"),
        Patch(facecolor=colors_nonblocking[1], label="BatchNonBlocking, BatchSize=128"),
        Patch(facecolor=colors_nonblocking[2], label="BatchNonBlocking, BatchSize=512"),
        Patch(facecolor=colors_blocking[0], label="BatchBlocking, BatchSize=32"),
        Patch(facecolor=colors_blocking[1], label="BatchBlocking, BatchSize=128"),
        Patch(facecolor=colors_blocking[2], label="BatchBlocking, BatchSize=512"),
    ]

    fig = plt.figure(figsize=(w, h))
    ax = fig.add_subplot(111)
    ax.axis("off")

    ax.legend(
        handles=handles,
        loc="center",
        ncol=6,
        frameon=False,
        fontsize=6.5,
        handlelength=1.0,
        handletextpad=0.35,
        columnspacing=0.75,
        borderaxespad=0.0,
    )

    plt.savefig(args.output, dpi=args.dpi, bbox_inches="tight", pad_inches=0.01)
    print(f"legend 已保存到: {args.output}")


if __name__ == "__main__":
    main()
