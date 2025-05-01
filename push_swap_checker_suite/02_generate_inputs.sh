#!/bin/bash

OUTPUT_FILE=inputs.txt
: > $OUTPUT_FILE

generate() {
  size=$1
  count=$2
  for ((i=0; i<$count; i++)); do
    seq $size | awk 'BEGIN{srand()}{a[NR]=$0} END{for(i=1;i<=NR;i++){j=int(rand()*NR)+1;tmp=a[i];a[i]=a[j];a[j]=tmp}} END{for(i=1;i<=NR;i++) printf "%s ", a[i]; print ""}'
  done
}

echo "🔧 Generating inputs..."
generate 10 3 >> $OUTPUT_FILE
generate 50 2 >> $OUTPUT_FILE
generate 100 2 >> $OUTPUT_FILE
generate 250 2 >> $OUTPUT_FILE
generate 500 1 >> $OUTPUT_FILE

echo "✅ Saved to $OUTPUT_FILE"
