#!/bin/bash

for counter in $(seq 0 101); do
    #cp chebyshev/chebyshev_$counter* lista.in
    g++ -D PRINT -D MEASURE_TIME place_no_constraints_random.cpp
    ./a.out cap 10 < sgfilter/sgfilter_$counter.in > $counter
done

