#!/bin/bash

ARG=$(gshuf -i 1-100 -n 500)
i=500;
j=0;

while [ $i -gt 0 ]; do
    j=$(./push_swap "$ARG" | wc -l)
    if [ $j -gt 700 ]; then
        echo "TO BIG"
    fi
    ((i--))
done

