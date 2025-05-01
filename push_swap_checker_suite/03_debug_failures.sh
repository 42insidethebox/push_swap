#!/bin/bash

KO_LOGS=$(ls push_swap_ko_*.log 2>/dev/null)

if [ -z "$KO_LOGS" ]; then
  echo "No KO logs found. Run 01_check_ok.sh first."
  exit 1
fi

for file in $KO_LOGS; do
  echo "🕵️ Debugging $file"
  ID=$(echo $file | grep -o '[0-9]\+')
  INPUT=$(sed -n "${ID}p" inputs.txt)

  echo "📥 Input: $INPUT"
  echo "📤 Operations:"
  cat $file
  echo "🧪 Verifying manually..."
  ./checker_linux $INPUT < $file
  echo "-------------------------"
done
