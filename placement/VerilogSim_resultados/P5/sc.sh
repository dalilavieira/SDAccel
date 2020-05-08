#!/bin/bash

for counter in $(seq 0 100); do
    cp listas/poly5out/poly5_$counter"ea"*  dados/poly5/eaData.txt
    cp listas/poly5out/poly5_$counter"eb"*  dados/poly5/ebData.txt
    mkdir $counter

    for ct in $(seq 1 10); do
    	iverilog -o hello random_placement_poly5_$ct.v
    	vvp hello > $counter/$ct


     #   g++ geraMain.cpp
      #  ./a.out 
       # iverilog -o hello Main.v
       # vvp hello > $counter/$ct
      #  g++ -O3 -D PRINT -D DEBUG place_no_constraints.cpp
     #   ./a.out < lista.in > $counter/$ct
    done

done
