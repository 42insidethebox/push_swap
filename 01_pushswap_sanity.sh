#!/bin/bash

RED='\033[0;31m'        # ❌
GREEN='\033[0;32m'      # ✅
YELLOW='\033[1;33m'     # ⚠️
BLUE='\033[1;34m'       # ℹ️
NC='\033[0m'            # Reset

echo -e "${BLUE}🔍 Running sanity checks on push_swap...${NC}"

total=0
fail=0

function run_test() {
  ((total++))
  ARG="$1"
  DESC="$2"
  EXPECTED="$3"
  THRESHOLD="$4"

  OUTPUT=$(./push_swap $ARG | ./checker_Mac $ARG)
  OPS=$(./push_swap $ARG | wc -l)

  if [[ "$OUTPUT" == "OK" && "$OPS" -le $THRESHOLD ]]; then
    echo -e "${GREEN}✅ [$DESC] OK | Ops: $OPS${NC}"
  elif [[ "$OUTPUT" == "OK" ]]; then
    echo -e "${YELLOW}⚠️ [$DESC] OK but ops = $OPS (over $THRESHOLD)${NC}"
  else
    echo -e "${RED}❌ [$DESC] Failed | Output: $OUTPUT${NC}"
    ((fail++))
  fi
}

# 💡 Basic Tests
run_test "3 2 1" "Tiny reverse sorted"  "OK" 3
run_test "$(shuf -i 1-100 -n 30 | tr '\n' ' ')" "Mid Random (30)" "OK" 400
run_test "$(shuf -i 1-1000 -n 500 | tr '\n' ' ')" "Large Random (500)" "OK" 7500

# 🔁 Random loop
for i in {1..5}; do
  run_test "$(shuf -i 1-1000 -n 100 | tr '\n' ' ')" "Random test $i (100)" "OK" 1300
done

# 🔥 Edge Cases
echo -e "${BLUE}⚙️  Testing error handling cases:${NC}"

./push_swap "1 2 3 1" 2>/dev/null && echo -e "${RED}❌ Duplicate test failed${NC}" || echo -e "${GREEN}✅ Duplicate detected${NC}"
./push_swap "abc 123" 2>/dev/null && echo -e "${RED}❌ Invalid input test failed${NC}" || echo -e "${GREEN}✅ Invalid input detected${NC}"
./push_swap "2147483648" 2>/dev/null && echo -e "${RED}❌ Overflow test failed${NC}" || echo -e "${GREEN}✅ Overflow detected${NC}"

echo -e "${BLUE}📊 Summary: $((total - fail)) passed / $total total${NC}"

if [ $fail -eq 0 ]; then
  echo -e "${GREEN}🎉 ALL TESTS PASSED${NC}"
else
  echo -e "${RED}❌ $fail TESTS FAILED${NC}"
fi
