#!/bin/bash

for counter in $(seq 0 100); do
    cp listas/qsplineout/qspline_$counter"ea"*  dados/qspline/eaData.txt
    cp listas/qsplineout/qspline_$counter"eb"*  dados/qspline/ebData.txt
   # mkdir $counter

    iverilog -o hello random_placement_qspline.v
    vvp hello

    #for ct in $(seq 0 9); do
     #   g++ geraMain.cpp
      #  ./a.out 
       # iverilog -o hello Main.v
       # vvp hello > $counter/$ct
      #  g++ -O3 -D PRINT -D DEBUG place_no_constraints.cpp
     #   ./a.out < lista.in > $counter/$ct
    #done

done

