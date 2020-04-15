#!/bin/bash

for counter in $(seq 1 100); do
	name=res_$counter 
	#Fir16
	g++ gera.cpp 
	./a.out 9
	echo $counter 
	iverilog -o hello random_placement_fir16.v
	vvp hello > Fir16_100/$name
done
