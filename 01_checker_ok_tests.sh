#!/bin/bash
echo "=== MINIMAL OK TESTS ==="

# 🧪 Single element
./push_swap "42" | ./checker_Mac "42"

# 🧪 Two elements - already sorted
./push_swap "1 2" | ./checker_Mac "1 2"

# 🧪 Two elements - needs one swap
./push_swap "2 1" | ./checker_Mac "2 1"

# 🧪 Three elements - full permutations
./push_swap "1 2 3" | ./checker_Mac "1 2 3"
./push_swap "3 2 1" | ./checker_Mac "3 2 1"
./push_swap "2 3 1" | ./checker_Mac "2 3 1"
./push_swap "1 3 2" | ./checker_Mac "1 3 2"
./push_swap "2 1 3" | ./checker_Mac "2 1 3"
./push_swap "3 1 2" | ./checker_Mac "3 1 2"

# 🧪 Four to five elements
./push_swap "5 4 3 2 1" | ./checker_Mac "5 4 3 2 1"
./push_swap "1 3 2 4 5" | ./checker_Mac "1 3 2 4 5"

# 🧪 Already sorted large input
ARG=$(seq 1 100 | tr '\n' ' ')
./push_swap $ARG | ./checker_Mac $ARG

# 🧪 Random small input (<= 5)
./push_swap "4 2 3 1" | ./checker_Mac "4 2 3 1"

# 🧪 Random medium input (chunk-safe)
./push_swap "8 4 6 2 1 9 3 7 5 0" | ./checker_Mac "8 4 6 2 1 9 3 7 5 0"

# 🧪 Known tricky input that your sort_three must cover
./push_swap "3 1 2" | ./checker_Mac "3 1 2"
