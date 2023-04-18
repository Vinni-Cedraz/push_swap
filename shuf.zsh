#!/bin/bash
INT_MAX=2147483647
INT_MIN=-2147483647
size=$1
if ! [[ $size =~ ^[0-9]+$ ]]; then
  echo "Usage: $0 <array_size>"
  exit 1
fi

if (( $size < 1 )); then
  echo "Array size must be at least 1"
  exit 1
fi
if (( $size <= 3 )); then
  max_operations=2
elif (( $size <= 5 )); then
  max_operations=12
elif (( $size <= 100 )); then
  max_operations=700
else
  max_operations=5500
fi
array=()
declare -A hash_table
while (( ${#hash_table[@]} < $(( $size * 10 )) )); do
  while (( ${#array[@]} < $size )); do
    num=$((RANDOM % ($INT_MAX - $INT_MIN + 1) + $INT_MIN))
    if ! [[ ${array[*]} =~ $num ]]; then
      array+=($num)
    fi
  done
  hash=$(echo "${array[@]}" | md5sum | awk '{print $1}')
  counter=0
  while [[ -n "${hash_table[$hash]}" ]] && [[ "${hash_table[$hash]}" != "${array[*]}" ]]; do
    (( counter++ ))
    hash=$(echo "${array[@]}" | md5sum | awk '{print $1}')
    hash=$(( ($hash + $counter) % ($size * 10) ))
  done
  if [[ ${hash_table[$hash]} != "${array[@]}" ]]; then
    output=$(./push_swap "${array[@]}" | wc -l &)
    if (( $output > $max_operations )); then
      echo "Failed with array: ${array[@]}"
      echo "Output: $output"
      exit 1
    fi
    hash_table["$hash"]="${array[@]}"
  fi
  array=()
done
echo "Approved for SEVERAL possible unique combinations of arrays of size $size"
exit 0
