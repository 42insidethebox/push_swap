#!/bin/bash

# 📌 CONFIG
PUSH_SWAP=./push_swap
CHECKER=./checker
LOG_FILE=push_swap_testlog.txt
VALGRIND=false     # Optional

# 🌈 Colors
GREEN="\033[0;32m"
RED="\033[0;31m"
YELLOW="\033[1;33m"
NC="\033[0m"

# 🔧 Rebuild
make re > /dev/null || { echo -e "${RED}Build failed!${NC}"; exit 1; }

# ✨ Header
echo -e "${YELLOW}=== PUSH_SWAP TEST SUITE ===${NC}" | tee $LOG_FILE
date | tee -a $LOG_FILE
echo -e "Binary: $PUSH_SWAP\n" | tee -a $LOG_FILE

# 🧪 FUNCTION
run_test() {
	local input="$1"
	local label="$2"

	echo -e "🧪 Test: ${YELLOW}$label${NC}" | tee -a $LOG_FILE
	echo -e "📥 Input: $input" | tee -a $LOG_FILE

	ops=$($PUSH_SWAP $input)
	ops_count=$(echo "$ops" | wc -l)
	result=$(echo "$ops" | $CHECKER $input)

	if [ "$result" == "OK" ]; then
		echo -e "✅ Result: ${GREEN}OK${NC} ($ops_count ops)" | tee -a $LOG_FILE
	else
		echo -e "❌ Result: ${RED}KO${NC} ($ops_count ops)" | tee -a $LOG_FILE
	fi

	if [ $ops_count -lt 20 ]; then
		echo -e "📦 Operations:\n$ops" | tee -a $LOG_FILE
	else
		echo -e "📦 Too many ops to show ($ops_count lines)" | tee -a $LOG_FILE
	fi

	if [ "$VALGRIND" = true ]; then
		echo -e "🔬 Valgrind:\n" | tee -a $LOG_FILE
		valgrind --leak-check=full $PUSH_SWAP $input >> $LOG_FILE 2>&1
	fi

	echo "------------------------------------------" | tee -a $LOG_FILE
}

# 🧪 BASIC TESTS
run_test "3 2 1" "reverse 3"
run_test "1 2 3" "already sorted"
run_test "5 4 3 2 1" "reverse 5"
run_test "42 -42 0 7 -7" "mixed signs"

# 🔁 RANDOMS
RAND_10=$(seq 1 10 | sort -R | tr '\n' ' ')
RAND_100=$(seq 1 100 | sort -R | tr '\n' ' ')
RAND_500=$(seq 1 500 | sort -R | tr '\n' ' ')

run_test "$RAND_10" "random 10"
run_test "$RAND_100" "random 100"
run_test "$RAND_500" "random 500"

echo -e "\n✅ ${GREEN}All tests complete.${NC}" | tee -a $LOG_FILE
