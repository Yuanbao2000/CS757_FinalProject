#!/bin/bash
# scripts/sweep.sh
# Usage: ./scripts/sweep.sh [runs=10]
# Runs each (circuit, batch_size) combo N times.

## NO USE ##

BINARY="./cmake-build-debug/gpu_scheduler"
RUNS=${1:-10}

CIRCUITS=(
    "benchmark/c432.ckt"
    "benchmark/c1908.ckt"
    "benchmark/c3540.ckt"
    "benchmark/c7552.ckt"
)

BATCH_SIZES=(32 128 512)

for CKT in "${CIRCUITS[@]}"; do
    for BS in "${BATCH_SIZES[@]}"; do
        echo "--- $(basename $CKT .ckt)  batch=$BS ---"
        for RUN in $(seq 1 $RUNS); do
            echo "  run $RUN/$RUNS"
            $BINARY "$CKT" "$BS"
        done
    done
done

echo ""
echo "Success"
