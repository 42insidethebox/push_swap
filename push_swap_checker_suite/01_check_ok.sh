#!/bin/bash
# === 01_check_ok.sh ===
# Tests increasing input sizes through checker and logs failures

CHECKER=../checker_linux
PS=../push_swap
TMP=tmp_out.txt

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

for n in $(seq 5 5 100); do
	ARG=$(seq -1 $((n - 1)) | shuf | tr '\n' ' ')
	echo -e "🔍 Testing size=$n"
	$PS $ARG > $TMP
	RES=$($CHECKER $ARG < $TMP)
	COUNT=$(wc -l < $TMP)
	if [ "$RES" = "OK" ]; then
		echo -e "${GREEN}✅ OK [$COUNT ops]${NC}"
	else
		echo -e "${RED}❌ KO [$COUNT ops] → Input: $ARG${NC}"
	fi
done
