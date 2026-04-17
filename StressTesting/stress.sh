#!/bin/bash

for ((i=1;;i++))
do
    echo "Test $i"

    ./gen > input.txt
    ./../Code1 < input.txt > out1.txt
    ./brute < input.txt > out2.txt

    diff out1.txt out2.txt

    if [ $? -ne 0 ]
    then
        echo "Mismatch found!"
        cat input.txt
        break
    fi
done
