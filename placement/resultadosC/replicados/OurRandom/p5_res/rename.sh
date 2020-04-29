#!/bin/bash

for counter in $(seq 0 101); do
	cd $counter
	for ct in $(seq 0 9); do
		name=$ct"_"$counter
		mv $ct $name 
        #        cat $ct
	done
	cd ..
done

