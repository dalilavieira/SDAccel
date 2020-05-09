#!/bin/bash

for counter in $(seq 0 100); do
	cd $counter
	for ct in $(seq 1 10); do
		name=$ct"_"$counter
		mv $ct $name 
        #        cat $ct
	done
	cd ..
done

