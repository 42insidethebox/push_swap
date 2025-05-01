#!/bin/bash

SIZES=(100 250 500 750 1000)
PUSH_SWAP=./push_swap
CHECKER=./checker_linux

if [ ! -x "$PUSH_SWAP" ] || [ ! -x "$CHECKER" ]; then
    echo "❌ push_swap or checker_linux not found or not executable"
    exit 1
fi

echo "===== 🔍 RADIX LARGE TEST SUITE ====="
echo "Checker path: $CHECKER"
echo "-------------------------------------"

for SIZE in "${SIZES[@]}"; do
    INPUT=$(shuf -i 1-${SIZE} -n ${SIZE} | tr '\n' ' ')
    OPS=$($PUSH_SWAP $INPUT)
    COUNT=$(echo "$OPS" | wc -l)
    RESULT=$(echo "$OPS" | $CHECKER $INPUT)
    echo "🧪 Size: $SIZE"
    echo "👉 Operations: $COUNT"
    echo "✅ Checker: $RESULT"
    echo "------------------------"
done
