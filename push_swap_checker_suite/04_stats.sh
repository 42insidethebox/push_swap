#!/bin/bash

total=$(grep -c "" inputs.txt)
kos=$(ls push_swap_ko_*.log 2>/dev/null | wc -l)

echo "📊 Total tests: $total"
echo "❌ KO: $kos"
echo "✅ OK: $((total - kos))"
