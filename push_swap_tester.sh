#!/bin/bash

# 🧪 OUTPUT FILE
OUTPUT="results_push_swap.txt"
CHECKER="./checker_linux"
PUSH_SWAP="./push_swap"

# 🔁 TEST CASES
TESTS=(
    "1 2 3"
    "3 2 1"
    "2 1 3"
    "3 1 2"
    "1 5 2 4 3"
    "4 3 2 1"
    "5 4 3 2 1"
    "2 3 5 1 4 6"
    "10 9 8 7 6 5 4 3 2 1 11 12 13 14 15 16 17 18 19 20"
    "25 48 4 13 19 2 20 16 26 35 50"
)

# ✨ Start fresh
echo "==== PUSH_SWAP DEFENSE TEST ====" > "$OUTPUT"
echo "Checker path: $CHECKER" >> "$OUTPUT"
echo "--------------------------------" >> "$OUTPUT"

for TEST in "${TESTS[@]}"
do
    echo -e "\n🧪 Input: $TEST" >> "$OUTPUT"
    OPS=$($PUSH_SWAP $TEST)
    COUNT=$(echo "$OPS" | wc -l)
    RESULT=$(echo "$OPS" | $CHECKER $TEST)

    echo "$OPS" >> "$OUTPUT"
    echo "👉 Operations: $COUNT" >> "$OUTPUT"
    echo "✅ Checker: $RESULT" >> "$OUTPUT"
    echo "------------------------" >> "$OUTPUT"
done

# ✅ Finished
echo -e "\n✅ Results saved to $OUTPUT"
