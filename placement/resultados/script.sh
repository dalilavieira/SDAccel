#!/bin/bash

for counter in $(seq 1 10); do
	name=res_$counter 
	g++ gera.cpp
	echo $counter 
	#iverilog -o hello placement.v
	#vvp hello > $name
done
