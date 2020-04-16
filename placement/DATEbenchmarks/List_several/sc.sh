#!/bin/bash

for counter in $(seq 0 99); do
	cd chebyshev_$counter
	for ct in $(seq 0 9); do
		mv "log_"$ct* "log_"$counter"_"$ct
	done
done

