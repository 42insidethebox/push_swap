#!/bin/bash

LOG_FILE="push_swap_results.log"
PUSH_SWAP_EXEC="./push_swap"
CHECKER_EXEC="./checker"  # Optional if you're using a checker

test_case() {
    ARGS="$@"
    echo "🧪 ./push_swap $ARGS" >> $LOG_FILE
    OUTPUT=$($PUSH_SWAP_EXEC $ARGS)
    OPS_COUNT=$(echo "$OUTPUT" | wc -l)
    echo "$OUTPUT" >> $LOG_FILE
    echo "👉 Operations: $OPS_COUNT" >> $LOG_FILE

    # Optional: checker (if you have one)
    if [ -x "$CHECKER_EXEC" ]; then
        RESULT=$(echo "$OUTPUT" | $CHECKER_EXEC $ARGS)
        echo "✅ Checker says: $RESULT" >> $LOG_FILE
    fi

    echo "------------------------" >> $LOG_FILE
}

# === 🧪 TEST SETS ===

# 5 elements
test_case 5 4 3 2 1
test_case 3 2 5 1 4
test_case 1 2 4 3 5
test_case 1 5 2 4 3

# 6 elements
test_case 6 5 4 3 2 1
test_case 1 4 2 6 3 5
test_case 2 3 5 1 4 6

# 20 elements
test_case 10 9 8 7 6 5 4 3 2 1 11 12 13 14 15 16 17 18 19 20
test_case 3 1 2 4 6 5 7 9 8 10 20 19 18 17 16 15 14 13 12 11

# 50 random (requires `shuf`)
test_case $(shuf -i 1-50)

# 100 random
test_case $(python3 -c "import random; print(' '.join(map(str, random.sample(range(1, 101), 100))))")

echo "✅ All tests appended to $LOG_FILE"
