#!/bin/bash

OUTFILE="valgrind_output.txt"
EXE="./push_swap"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes"

echo "" > $OUTFILE

run_test() {
	echo "========== $1 ==========" >> $OUTFILE
	echo "$ $VALGRIND $EXE $2" >> $OUTFILE
	$VALGRIND $EXE $2 >> $OUTFILE 2>&1
	echo "" >> $OUTFILE
}

# ✅ Already sorted - Should exit cleanly
run_test "✅ Already sorted" "1 2 3 4 5"

# 💀 Duplicate values - Should print error, no leak
run_test "💀 Duplicate values" "3 2 1 3"

# 🧬 Non-integer input - Should trigger atoi failure
run_test "🧬 Non-integer input" "3 2 a"

# ⚠️ Integer overflow - Should be caught
run_test "⚠️ Integer overflow" "2147483648"

# 🚀 Big random input - Should run fully
ARG=$(seq 1 500 | sort -R | tr '\n' ' ')
run_test "🚀 Big random input (500 shuffled)" "$ARG"

# 🔁 Mixed split + space - Simulates bonus input format
run_test "🔁 Mixed single string split input" '"3 2 1"'

# 🔄 Lots of args directly
run_test "🔄 Medium direct input" "500 100 300 200 400"

echo "✅ Done! See full results in: $OUTFILE"
