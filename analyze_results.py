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

    # Try to match both old (batch_size=) and new formats (sequential=/concurrent=)
    config_match = re.search(r'(?:batch_size|sequential|concurrent)=(\d+)', content)

    # Extract mode from filename (e.g., report_balanced_0_concurrent_c128.md)
    mode_match = re.search(r'_(sequential|concurrent)_', filepath)
    mode = mode_match.group(1) if mode_match else "sequential"  # default to sequential for old reports

    group = group_match.group(1) if group_match else "unknown"
    # Remove mode suffix from group name if present
    group = re.sub(r'_(sequential|concurrent)$', '', group)

    config_value = int(config_match.group(1)) if config_match else 0

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
        'config_value': config_value,  # batch_size or max_concurrent
        'mode': mode,  # sequential or concurrent
        'schedulers': schedulers,
        'per_wl_slowdown': per_wl_slowdown
    }


def analyze_fairness(reports):
    """Analyze fairness across workloads."""
    print("\n" + "="*80)
    print("FAIRNESS ANALYSIS")
    print("="*80)

    for config_val in [32, 128, 512]:
        for mode in ['sequential', 'concurrent']:
            mode_reports = [r for r in reports if r['config_value'] == config_val and r['mode'] == mode]

            if not mode_reports:
                continue

            print(f"\n### Mode: {mode.upper()} | Config Value = {config_val}")

            batch_reports = mode_reports

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

    # Group by config value and mode
    for config_val in [32, 128, 512]:
        for mode in ['sequential', 'concurrent']:
            mode_reports = [r for r in reports if r['config_value'] == config_val and r['mode'] == mode]

            if not mode_reports:
                continue

            batch_reports = mode_reports

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
            config_label = f"batch_size={config_val}" if mode == "sequential" else f"max_concurrent={config_val}"
            fig, axes = plt.subplots(2, 2, figsize=(14, 10))
            fig.suptitle(f'GPU Scheduler Comparison ({mode.upper()}, {config_label})', fontsize=16)

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
            ax.set_ylim([0.6, 1.0])
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

            output_file = f'reports/visualization_{mode}_{config_val}.png'
            plt.savefig(output_file, dpi=150, bbox_inches='tight')
            print(f"✓ Saved: {output_file}")
            plt.close()

    # Create combined comparison across config values for each mode
    for mode in ['sequential', 'concurrent']:
        mode_reports = [r for r in reports if r['mode'] == mode]

        if not mode_reports:
            continue

        fig, axes = plt.subplots(1, 3, figsize=(18, 5))
        config_param = "Batch Size" if mode == "sequential" else "Max Concurrent"
        fig.suptitle(f'Impact of {config_param} on Scheduler Performance ({mode.upper()})', fontsize=16)

        config_values = [32, 128, 512]
        schedulers = ['FIFO', 'Priority', 'HighFanout', 'CriticalPath', 'LevelAware', 'Hybrid']

        # Collect data for each scheduler across config values
        for sched_idx, sched in enumerate(schedulers):
            wait_by_config = []
            throughput_by_config = []
            makespan_by_config = []

            for config_val in config_values:
                config_reports = [r for r in mode_reports if r['config_value'] == config_val]
                waits = [r['schedulers'][sched]['avg_wait'] for r in config_reports if sched in r['schedulers']]
                throughputs = [r['schedulers'][sched]['throughput'] for r in config_reports if sched in r['schedulers']]
                makespans = [r['schedulers'][sched]['makespan'] for r in config_reports if sched in r['schedulers']]

                wait_by_config.append(np.mean(waits) if waits else 0)
                throughput_by_config.append(np.mean(throughputs) if throughputs else 0)
                makespan_by_config.append(np.mean(makespans) if makespans else 0)

            # Plot
            axes[0].plot(config_values, wait_by_config, marker='o', label=sched, linewidth=2)
            axes[1].plot(config_values, throughput_by_config, marker='o', label=sched, linewidth=2)
            axes[2].plot(config_values, makespan_by_config, marker='o', label=sched, linewidth=2)

        axes[0].set_xlabel(config_param)
        axes[0].set_ylabel('Avg Wait Time (ms)')
        axes[0].set_title(f'Wait Time vs {config_param}')
        axes[0].set_xticks(config_values)
        axes[0].legend()
        axes[0].grid(alpha=0.3)
        axes[0].spines['top'].set_visible(False)
        axes[0].spines['right'].set_visible(False)

        axes[1].set_xlabel(config_param)
        axes[1].set_ylabel('Throughput (tasks/s)')
        axes[1].set_title(f'Throughput vs {config_param}')
        axes[1].set_xticks(config_values)
        axes[1].legend()
        axes[1].grid(alpha=0.3)
        axes[1].spines['top'].set_visible(False)
        axes[1].spines['right'].set_visible(False)

        axes[2].set_xlabel(config_param)
        axes[2].set_ylabel('Makespan (ms)')
        axes[2].set_title(f'Makespan vs {config_param}')
        axes[2].set_xticks(config_values)
        axes[2].legend()
        axes[2].grid(alpha=0.3)
        axes[2].spines['top'].set_visible(False)
        axes[2].spines['right'].set_visible(False)

        plt.tight_layout()
        output_file = f'reports/config_impact_{mode}.png'
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
    print("Generated visualization files in reports/")
    print("Fairness analysis printed above.\n")


if __name__ == '__main__':
    main()
