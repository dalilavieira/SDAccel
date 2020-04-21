#!/bin/bash

for counter in $(seq 0 101); do
	cd chebyshev_$counter
	for ct in $(seq 0 9); do
		name="log_"$ct"_"$counter
		mv "log_"$ct* $name 
	done
	cd ..
done

