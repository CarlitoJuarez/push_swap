#!/bin/bash


i=1000;
j=0;



while [ $i -gt 0 ]; do
    ARG=$(./gen_nums)
    sleep 1;
    j=$(./push_swap $ARG | wc -l)
    if [ $j -gt 700 ]; then
        echo "TO BIG $j"
    else
        echo "THIS: $j"
    fi
    ((i--))
done

