#!/bin/bash

# ─────────────────────────────────────────────────────────────
# 🌈 PUSH_SWAP SANITY + BENCHMARK SUITE v2
# Author: GPT + You
# Purpose: Confidence test for correctness, efficiency & edge handling
# ─────────────────────────────────────────────────────────────

BINARY="./push_swap"
CHECKER="./checker_Mac"
LOG_DIR="./logs"
mkdir -p $LOG_DIR
NOW=$(date +"%Y-%m-%d_%H-%M-%S")
LOG_FILE="$LOG_DIR/testlog_$NOW.log"
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
RESET='\033[0m'
PASS_COUNT=0
TOTAL_COUNT=0

print_test() {
	echo -e "${CYAN}🔹 $1${RESET}"
}

check_case() {
	DESC="$1"
	ARG="$2"
	MAX_OPS="$3"
	((TOTAL_COUNT++))

	START_TIME=$(date +%s%3N)
	OPS=$($BINARY $ARG | tee /tmp/ps_output | wc -l)
	RESULT=$($BINARY $ARG | $CHECKER $ARG)
	END_TIME=$(date +%s%3N)
	ELAPSED_MS=$((END_TIME - START_TIME))

	if [[ "$RESULT" == "OK" && "$OPS" -le "$MAX_OPS" ]]; then
		echo -e "✅ ${GREEN}[$DESC]${RESET} OK | Ops: $(printf '%6d' $OPS) | Time: ${ELAPSED_MS}ms" | tee -a "$LOG_FILE"
		((PASS_COUNT++))
	else
		echo -e "❌ ${RED}[$DESC]${RESET} FAILED | Ops: $(printf '%6d' $OPS) | Result: $RESULT" | tee -a "$LOG_FILE"
	fi
}

run_random() {
	for i in {1..5}; do
		ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
		check_case "Random test $i (100)" "$ARG" 1500
	done
}

check_error_case() {
	((TOTAL_COUNT++))
	DESC="$1"
	ARG="$2"

	if echo "$ARG" | $BINARY >/dev/null 2>&1; then
		echo -e "❌ ${RED}[$DESC]${RESET} should error but didn’t" | tee -a "$LOG_FILE"
	else
		echo -e "✅ ${GREEN}[$DESC]${RESET}" | tee -a "$LOG_FILE"
		((PASS_COUNT++))
	fi
}

# ─────────────────────────────────────────────────────────────
echo -e "${BOLD}🔍 Running sanity + benchmark suite on push_swap...${RESET}"
# ─────────────────────────────────────────────────────────────

check_case "Tiny reverse sorted" "3 2 1" 3
check_case "Mid Random (30)" "$(shuf -i 1-100 -n 30 | tr '\n' ' ')" 700
check_case "Large Random (500)" "$(shuf -i 1-1000 -n 500 | tr '\n' ' ')" 7500
run_random

echo -e "${YELLOW}⚙️  Testing error handling cases:${RESET}"
check_error_case "Duplicate detected" "1 2 3 4 1"
check_error_case "Invalid input detected" "1 2 abc 3"
check_error_case "Overflow detected" "2147483648"

# ─────────────────────────────────────────────────────────────
echo -e "${BOLD}📊 Summary: $PASS_COUNT passed / $TOTAL_COUNT total${RESET}"
if [ "$PASS_COUNT" -eq "$TOTAL_COUNT" ]; then
	echo -e "${GREEN}🎉 ALL TESTS PASSED${RESET}"
else
	echo -e "${RED}🚨 SOME TESTS FAILED${RESET}"
fi
echo -e "📝 Log saved to: ${LOG_FILE}"
# ─────────────────────────────────────────────────────────────
