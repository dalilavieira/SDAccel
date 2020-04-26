#!/bin/bash

for counter in $(seq 0 101); do
    cp chebyshev/chebyshev_$counter* lista.in
    mkdir $counter

    for ct in $(seq 0 9); do
        g++ gera.cpp
        ./a.out 5
        g++ -O3 -D PRINT -D DEBUG -D MEASURE_TIME place_no_constraints.cpp
        ./a.out < lista.in > $counter/$ct
    done

done

