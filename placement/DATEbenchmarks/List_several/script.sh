#!/bin/bash

mkdir RES_chebyshev

for counter in $(seq 0 1); do
	var="chebyshevout/chebyshev_"$counter"ea"
	cp $var* dados/chebyshev/eaData.txt 
	
	var="chebyshevout/chebyshev_"$counter"eb"
	cp $var* dados/chebyshev/ebData.txt 

	for counter in $(seq 1 2); do
		name=res_$counter 
		#chebyshev
		g++ gera.cpp 
		./a.out 3 #TROCAR
		echo $counter 
		iverilog -o hello random_placement_cheb.v
		vvp hello #> RES_chebyshev/$name
	done
done

