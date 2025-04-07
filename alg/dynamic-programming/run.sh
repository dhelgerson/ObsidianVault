#!/bin/bash

for N in {1..99}; do
  for K in $(seq 1 $N); do
    echo $N $K
  done
done | xargs -P 16 -n2 ./nchoosek | tee out.csv
