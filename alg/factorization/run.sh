#!/bin/bash

for N in $(seq 1 $1)
do
	for K in $(seq 1 ${N})
	do
		 echo ${N} ${K}
	done
done | xargs -P$(nproc) -n2 ./nchoosek
