#!/bin/bash

# 如果当前目录没有 csv，就退出
shopt -s nullglob
csv_files=( *.csv )

if [ ${#csv_files[@]} -eq 0 ]; then
    echo "当前目录下没有找到 CSV 文件。"
    exit 1
fi

for f in "${csv_files[@]}"; do
    base="${f%.csv}"

    # 生成标题里用的 circuit 名
    # 例如 report_c5315.csv -> circuit5315
    if [[ "$base" =~ ^report_c(.+)$ ]]; then
        circuit_name="circuit${BASH_REMATCH[1]}"
    else
        circuit_name="$base"
    fi

    echo "正在处理: $f"

    python3 plot_from_csv_1.py "$f" \
        --column "Makespan (ms)" \
        --output "${base}_scheduling_makespan.png" \
        --title "(${circuit_name}) Makespan" \
	--ylabel "Normalized Makespan (ms)"\
        --yrange "0.4-1.6"

    python3 plot_from_csv_1.py "$f" \
        --column "GPU Util (%)" \
        --output "${base}_scheduling_gpuUtil.png" \
        --title "(${circuit_name}) GPU Util" \
	--ylabel "Normalized GPU Util (%)"

    python3 plot_from_csv_1.py "$f" \
        --column "Throughput (gates/s)" \
        --output "${base}_scheduling_throughput.png" \
        --title "(${circuit_name}) Throughput" \
        --ylabel "Normalized Throughput (gates/s)"\
        --yrange "0.4-1.6"

    echo "完成: $f"
    echo "-----------------------------"
done

echo "全部 CSV 处理完成。"
