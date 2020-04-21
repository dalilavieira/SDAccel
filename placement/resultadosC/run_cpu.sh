GRAPH=('accumulate' 'cap' 'conv2' 'conv3' 'mac' 'mac2' 'matrixmultiply' 'mults1'
       'mults2' 'nomem1' 'simple' 'sum' 'twoloops1' 'twoloops2')

g++ -O3 -D MEASURE_TIME -D PRINT cpu/place_no_constraints.cpp
for ((i=0; i < ${#GRAPH[@]}; i++)) do
       echo "--- "${GRAPH[i]}" ---"
	./a.out < list/balanced/${GRAPH[i]}.in
done

rm a.out
