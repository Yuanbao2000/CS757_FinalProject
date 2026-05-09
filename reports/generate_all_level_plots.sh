#!/bin/bash

shopt -s nullglob

csv_files=( report_*.csv )

if [ ${#csv_files[@]} -eq 0 ]; then
    echo "当前目录下没有找到 report_*.csv 文件。"
    exit 1
fi

for f in "${csv_files[@]}"; do
    base="${f%.csv}"

    echo "正在处理: $f"

    python plot_from_csv_2.py "$f" \
        --output "${base}_level_summary.png"

    echo "完成: ${base}_level_summary.png"
    echo "-----------------------------"
done

echo "全部 CSV 处理完成。"
