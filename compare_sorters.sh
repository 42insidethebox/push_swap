#!/bin/bash

RED='\033[0;31m'
GRN='\033[0;32m'
YEL='\033[1;33m'
NC='\033[0m'

echo -e "${YEL}=== 🧠 PUSH_SWAP SORT COMPARISON ===${NC}"

for size in 10 100 500; do
	echo -e "\n🔢 ${GRN}Testing size: $size${NC}"
	ARG=$(seq $size | shuf | tr '\n' ' ')

	# Run RADIX Sort
	echo -e "🔁 Radix Sort:"
	if [ -x ./push_swap_radix ]; then
		./push_swap_radix $ARG > radix_ops.txt
		RADIX=$(wc -l < radix_ops.txt)
		echo -e "   ${YEL}$RADIX ops${NC}"
	else
		echo -e "   ${RED}Binary ./push_swap_radix not found!${NC}"
		RADIX=999999
	fi

	# Run CHUNK Sort
	echo -e "🔁 Chunk Sort:"
	if [ -x ./push_swap ]; then
		./push_swap $ARG > chunk_ops.txt
		CHUNK=$(wc -l < chunk_ops.txt)
		echo -e "   ${YEL}$CHUNK ops${NC}"
	else
		echo -e "   ${RED}Binary ./push_swap not found!${NC}"
		CHUNK=999999
	fi

	# Print result
	DIFF=$((RADIX - CHUNK))
	if [ "$DIFF" -eq 0 ]; then
		echo -e "📋 Result: Δ = ${GRN}$DIFF ops${NC} 🎯"
	elif [ "$DIFF" -gt 0 ]; then
		echo -e "📋 Result: Radix is worse by ${RED}$DIFF ops${NC} 💥"
	else
		echo -e "📋 Result: Chunk is worse by ${RED}$((-DIFF)) ops${NC} 💥"
	fi

	# Show diff of top 5 lines
	echo -e "📊 Diff (first 5 lines):"
	diff <(head -n 5 radix_ops.txt) <(head -n 5 chunk_ops.txt) || true
	echo "----------------------------------------------"
done
