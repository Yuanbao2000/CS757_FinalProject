#!/bin/bash
for config in configs/*.json; do
    echo "\n\nRunning $config..."
    ./cmake-build-debug/gpu_scheduler --config "$config"
done
