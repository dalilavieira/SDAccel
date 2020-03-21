#!/bin/bash

for counter in $(seq 1 100); do
	name=res_$counter 
	g++ gera.cpp
	./a.out
	echo $counter 
	iverilog -o hello random_placement.v
	vvp hello > 100/$name
done
