#!/bin/bash

for counter in $(seq 0 100); do
    cp listas/sgfilterout/sgfilter_$counter"ea"*  dados/sgfilter/eaData.txt
    cp listas/sgfilterout/sgfilter_$counter"eb"*  dados/sgfilter/ebData.txt
    mkdir $counter

    for ct in $(seq 1 10); do
    	iverilog -o hello random_placement_sgfilter_$ct.v
    	vvp hello > $counter/$ct


     #   g++ geraMain.cpp
      #  ./a.out 
       # iverilog -o hello Main.v
       # vvp hello > $counter/$ct
      #  g++ -O3 -D PRINT -D DEBUG place_no_constraints.cpp
     #   ./a.out < lista.in > $counter/$ct
    done

done

