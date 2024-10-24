#!/bin/bash
make
# for i in {1..16}; do ./nqueens 24 1 > out$i.log& done; wait; for i in $(ls -1 out*.log); do echo $i; cat $i; rm $i; done

for i in $(seq 1 $1); do
    ./nqueens 24 1 > out$i.log&
done

wait

for i in $(ls out*.log); do
    echo $i:
    cat $i
    rm $i
done