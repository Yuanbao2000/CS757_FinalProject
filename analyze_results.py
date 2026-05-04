#!/usr/bin/env python3
"""
Analyze GPU scheduler results and generate visualizations.
Reads markdown reports and creates fairness analysis + charts.
"""

import re
import glob
import numpy as np
import matplotlib.pyplot as plt
from collections import defaultdict

def parse_report(filepath):
    """Parse a markdown report file."""
    with open(filepath, 'r') as f:
        content = f.read()

    # Extract metadata
    group_match = re.search(r'Group: (\w+)', content)
    batch_match = re.search(r'batch_size=(\d+)', content)

    group = group_match.group(1) if group_match else "unknown"
    batch_size = int(batch_match.group(1)) if batch_match else 0

    # Parse summary table (lines after "## Summary")
    summary_section = re.search(r'## Summary\n\n\| Scheduler.*?\n\|---.*?\n(.*?)\n##', content, re.DOTALL)

    schedulers = {}
    if summary_section:
        for line in summary_section.group(1).strip().split('\n'):
            parts = [p.strip() for p in line.split('|')]
            if len(parts) > 12:
                sched_name = parts[1]
                schedulers[sched_name] = {
                    'avg_wait': float(parts[2]),
                    'max_wait': float(parts[3]),
                    'avg_exec': float(parts[4]),
                    'avg_turnaround': float(parts[5]),
                    'makespan': float(parts[6]),
                    'throughput': float(parts[7]),
                    'gpu_util': float(parts[8]),
                    'jains': float(parts[9]),
                }

    # Parse per-workload slowdown
    slowdown_section = re.search(r'## Per-Workload Avg Slowdown\n\n\| Workload.*?\n\|---.*?\n(.*?)\n##', content, re.DOTALL)

    per_wl_slowdown = defaultdict(dict)
    if slowdown_section:
        for line in slowdown_section.group(1).strip().split('\n'):
            parts = [p.strip() for p in line.split('|')]
            if len(parts) > 2:
                wl_id = parts[1]
                for i, sched in enumerate(['FIFO', 'Priority', 'HighFanout', 'CriticalPath', 'LevelAware', 'Hybrid']):
                    if i+2 < len(parts):
                        val = parts[i+2].replace('x', '')
                        per_wl_slowdown[sched][wl_id] = float(val)

    return {
        'group': group,
        'batch_size': batch_size,
        'schedulers': schedulers,
        'per_wl_slowdown': per_wl_slowdown
    }


def analyze_fairness(reports):
    """Analyze fairness across workloads."""
    print("\n" + "="*80)
    print("FAIRNESS ANALYSIS")
    print("="*80)

    for batch_size in [32, 128, 512]:
        print(f"\n### Batch Size = {batch_size}")

        batch_reports = [r for r in reports if r['batch_size'] == batch_size]

        # Aggregate per-workload slowdowns across all groups
        sched_slowdowns = defaultdict(list)

        for report in batch_reports:
            for sched, wl_data in report['per_wl_slowdown'].items():
                for wl_id, slowdown in wl_data.items():
                    sched_slowdowns[sched].append(slowdown)

        # Calculate fairness metrics
        print("\n| Scheduler | Mean Slowdown | Std Dev | Min | Max | Variance |")
        print("|-----------|---------------|---------|-----|-----|----------|")

        for sched in ['FIFO', 'Priority', 'HighFanout', 'CriticalPath', 'LevelAware', 'Hybrid']:
            if sched in sched_slowdowns:
                slowdowns = sched_slowdowns[sched]
                mean = np.mean(slowdowns)
                std = np.std(slowdowns)
                variance = np.var(slowdowns)
                min_s = np.min(slowdowns)
                max_s = np.max(slowdowns)

                print(f"| {sched:13} | {mean:13.2f}x | {std:7.2f}x | {min_s:5.1f}x | {max_s:5.1f}x | {variance:8.1f} |")

        print("\n**Fairness Ranking** (lower variance = fairer):")
        variance_ranking = []
        for sched in ['FIFO', 'Priority', 'HighFanout', 'CriticalPath', 'LevelAware', 'Hybrid']:
            if sched in sched_slowdowns:
                variance = np.var(sched_slowdowns[sched])
                variance_ranking.append((sched, variance))

        variance_ranking.sort(key=lambda x: x[1])
        for i, (sched, var) in enumerate(variance_ranking, 1):
            print(f"  {i}. {sched:15} (variance: {var:8.1f})")


def create_visualizations(reports):
    """Generate visualization charts."""
    print("\n" + "="*80)
    print("GENERATING VISUALIZATIONS")
    print("="*80)

    # Group by batch size
    for batch_size in [32, 128, 512]:
        batch_reports = [r for r in reports if r['batch_size'] == batch_size]

        if not batch_reports:
            continue

        # Aggregate metrics across groups
        sched_metrics = defaultdict(lambda: {'wait': [], 'throughput': [], 'jains': [], 'makespan': []})

        for report in batch_reports:
            for sched, metrics in report['schedulers'].items():
                sched_metrics[sched]['wait'].append(metrics['avg_wait'])
                sched_metrics[sched]['throughput'].append(metrics['throughput'])
                sched_metrics[sched]['jains'].append(metrics['jains'])
                sched_metrics[sched]['makespan'].append(metrics['makespan'])

        # Average across groups
        schedulers = ['FIFO', 'Priority', 'HighFanout', 'CriticalPath', 'LevelAware', 'Hybrid']
        avg_wait = [np.mean(sched_metrics[s]['wait']) for s in schedulers]
        avg_throughput = [np.mean(sched_metrics[s]['throughput']) for s in schedulers]
        avg_jains = [np.mean(sched_metrics[s]['jains']) for s in schedulers]
        avg_makespan = [np.mean(sched_metrics[s]['makespan']) for s in schedulers]

        # Create figure with 4 subplots
        fig, axes = plt.subplots(2, 2, figsize=(14, 10))
        fig.suptitle(f'GPU Scheduler Comparison (batch_size={batch_size})', fontsize=16)

        # 1. Average Wait Time
        ax = axes[0, 0]
        bars = ax.bar(range(len(schedulers)), avg_wait, color=['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b'])
        ax.set_xticks(range(len(schedulers)))
        ax.set_xticklabels(schedulers, rotation=45, ha='right')
        ax.set_ylabel('Avg Wait Time (ms)')
        ax.set_title('Average Wait Time')
        ax.grid(axis='y', alpha=0.3)
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)

        # 2. Throughput
        ax = axes[0, 1]
        bars = ax.bar(range(len(schedulers)), avg_throughput, color=['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b'])
        ax.set_xticks(range(len(schedulers)))
        ax.set_xticklabels(schedulers, rotation=45, ha='right')
        ax.set_ylabel('Throughput (tasks/s)')
        ax.set_title('Throughput')
        ax.grid(axis='y', alpha=0.3)
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)

        # 3. Jain's Fairness Index
        ax = axes[1, 0]
        bars = ax.bar(range(len(schedulers)), avg_jains, color=['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b'])
        ax.set_xticks(range(len(schedulers)))
        ax.set_xticklabels(schedulers, rotation=45, ha='right')
        ax.set_ylabel("Jain's Fairness Index")
        ax.set_title("Fairness")
        ax.set_ylim([0.85, 1.0])
        ax.grid(axis='y', alpha=0.3)
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)

        # 4. Latency vs Throughput Scatter
        ax = axes[1, 1]
        colors = ['#1f77b4', '#ff7f0e', '#2ca02c', '#d62728', '#9467bd', '#8c564b']
        for i, sched in enumerate(schedulers):
            ax.scatter(avg_wait[i], avg_throughput[i], s=200, c=colors[i], label=sched, alpha=0.7)
        ax.set_xlabel('Avg Wait Time (ms)')
        ax.set_ylabel('Throughput (tasks/s)')
        ax.set_title('Latency vs Throughput Tradeoff')
        ax.legend(loc='best')
        ax.grid(alpha=0.3)
        ax.spines['top'].set_visible(False)
        ax.spines['right'].set_visible(False)

        plt.tight_layout()

        output_file = f'reports/visualization_b{batch_size}.png'
        plt.savefig(output_file, dpi=150, bbox_inches='tight')
        print(f"✓ Saved: {output_file}")
        plt.close()

    # Create combined comparison across batch sizes
    fig, axes = plt.subplots(1, 3, figsize=(18, 5))
    fig.suptitle('Impact of Batch Size on Scheduler Performance', fontsize=16)

    batch_sizes = [32, 128, 512]
    schedulers = ['FIFO', 'Priority', 'HighFanout', 'CriticalPath', 'LevelAware', 'Hybrid']

    # Collect data for each scheduler across batch sizes
    for sched_idx, sched in enumerate(schedulers):
        wait_by_batch = []
        throughput_by_batch = []
        makespan_by_batch = []

        for batch_size in batch_sizes:
            batch_reports = [r for r in reports if r['batch_size'] == batch_size]
            waits = [r['schedulers'][sched]['avg_wait'] for r in batch_reports if sched in r['schedulers']]
            throughputs = [r['schedulers'][sched]['throughput'] for r in batch_reports if sched in r['schedulers']]
            makespans = [r['schedulers'][sched]['makespan'] for r in batch_reports if sched in r['schedulers']]

            wait_by_batch.append(np.mean(waits) if waits else 0)
            throughput_by_batch.append(np.mean(throughputs) if throughputs else 0)
            makespan_by_batch.append(np.mean(makespans) if makespans else 0)

        # Plot
        axes[0].plot(batch_sizes, wait_by_batch, marker='o', label=sched, linewidth=2)
        axes[1].plot(batch_sizes, throughput_by_batch, marker='o', label=sched, linewidth=2)
        axes[2].plot(batch_sizes, makespan_by_batch, marker='o', label=sched, linewidth=2)

    axes[0].set_xlabel('Batch Size')
    axes[0].set_ylabel('Avg Wait Time (ms)')
    axes[0].set_title('Wait Time vs Batch Size')
    axes[0].set_xticks(batch_sizes)
    axes[0].legend()
    axes[0].grid(alpha=0.3)
    axes[0].spines['top'].set_visible(False)
    axes[0].spines['right'].set_visible(False)

    axes[1].set_xlabel('Batch Size')
    axes[1].set_ylabel('Throughput (tasks/s)')
    axes[1].set_title('Throughput vs Batch Size')
    axes[1].set_xticks(batch_sizes)
    axes[1].legend()
    axes[1].grid(alpha=0.3)
    axes[1].spines['top'].set_visible(False)
    axes[1].spines['right'].set_visible(False)

    axes[2].set_xlabel('Batch Size')
    axes[2].set_ylabel('Makespan (ms)')
    axes[2].set_title('Makespan vs Batch Size')
    axes[2].set_xticks(batch_sizes)
    axes[2].legend()
    axes[2].grid(alpha=0.3)
    axes[2].spines['top'].set_visible(False)
    axes[2].spines['right'].set_visible(False)

    plt.tight_layout()
    output_file = 'reports/batch_size_impact.png'
    plt.savefig(output_file, dpi=150, bbox_inches='tight')
    print(f"✓ Saved: {output_file}")
    plt.close()


def main():
    # Find all report files
    report_files = glob.glob('reports/report_*.md')

    print(f"Found {len(report_files)} report files")

    # Parse all reports
    reports = []
    for filepath in report_files:
        try:
            report = parse_report(filepath)
            if report['schedulers']:  # Only include if parsing succeeded
                reports.append(report)
        except Exception as e:
            print(f"Warning: Failed to parse {filepath}: {e}")

    print(f"Successfully parsed {len(reports)} reports")

    if not reports:
        print("No reports to analyze!")
        return

    # Perform analyses
    analyze_fairness(reports)
    create_visualizations(reports)

    print("\n" + "="*80)
    print("ANALYSIS COMPLETE!")
    print("="*80)
    print("\nGenerated files:")
    print("  - reports/visualization_b32.png")
    print("  - reports/visualization_b128.png")
    print("  - reports/visualization_b512.png")
    print("  - reports/batch_size_impact.png")
    print("\nFairness analysis printed above.")


if __name__ == '__main__':
    main()
