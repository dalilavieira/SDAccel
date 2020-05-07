#!/bin/bash

mkdir arf_100
mkdir conv3_100
mkdir cosine1_100
mkdir cosine2_100
mkdir Cplx8_100
mkdir ewf_100
mkdir feedback_100
mkdir FilterRGB_100
mkdir fir1_100
mkdir fir2_100
mkdir Fir16_100
mkdir h2v2_100
mkdir horner_100
mkdir interpolate_100
mkdir k4n4op_100
mkdir mac_100
mkdir motion_100
mkdir mults1_100
mkdir simple_100

for counter in $(seq 1 100); do
	name=res_$counter 
	#arf
	g++ gera.cpp 
	./a.out 6
	echo $counter 
	iverilog -o hello placement_1hop_arf.v
	vvp hello > arf_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#conv3
	g++ gera.cpp 
	./a.out 6
	echo $counter 
	iverilog -o hello placement_1hop_conv3.v
	vvp hello > conv3_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#cosine1
	g++ gera.cpp 
	./a.out 9
	echo $counter 
	iverilog -o hello placement_1hop_cosine1.v
	vvp hello > cosine1_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#cosine2
	g++ gera.cpp 
	./a.out 9
	echo $counter 
	iverilog -o hello placement_1hop_cosine2.v
	vvp hello > cosine2_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#Cplx8
	g++ gera.cpp 
	./a.out 9
	echo $counter 
	iverilog -o hello placement_1hop_Cplx8.v
	vvp hello > Cplx8_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#ewf
	g++ gera.cpp 
	./a.out 9
	echo $counter 
	iverilog -o hello placement_1hop_ewf.v
	vvp hello > ewf_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#feedback_points
	g++ gera.cpp 
	./a.out 8
	echo $counter 
	iverilog -o hello placement_1hop_feedback.v
	vvp hello > feedback_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#filterRGB
	g++ gera.cpp 
	./a.out 10
	echo $counter 
	iverilog -o hello placement_1hop_FilterRGB.v
	vvp hello > FilterRGB_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#fir1
	g++ gera.cpp 
	./a.out 7
	echo $counter 
	iverilog -o hello placement_1hop_fir1.v
	vvp hello > fir1_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#fir2
	g++ gera.cpp 
	./a.out 7
	echo $counter 
	iverilog -o hello placement_1hop_fir2.v
	vvp hello > fir2_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#Fir16
	g++ gera.cpp 
	./a.out 9
	echo $counter 
	iverilog -o hello placement_1hop_fir16.v
	vvp hello > Fir16_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#h2v2
	g++ gera.cpp 
	./a.out 11
	echo $counter 
	iverilog -o hello placement_1hop_h2v2.v
	vvp hello > h2v2_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#horner
	g++ gera.cpp 
	./a.out 5
	echo $counter 
	iverilog -o hello placement_1hop_horner.v
	vvp hello > horner_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#interpolate
	g++ gera.cpp 
	./a.out 11
	echo $counter 
	iverilog -o hello placement_1hop_interpolate.v
	vvp hello > interpolate_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#k4n4op
	g++ gera.cpp 
	./a.out 8
	echo $counter 
	iverilog -o hello placement_1hop_k4n4op.v
	vvp hello > k4n4op_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#mac
	g++ gera.cpp 
	./a.out 4
	echo $counter 
	iverilog -o hello placement_1hop_mac.v
	vvp hello > mac_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#motion
	g++ gera.cpp 
	./a.out 6
	echo $counter 
	iverilog -o hello placement_1hop_motion.v
	vvp hello > motion_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#mults1
	g++ gera.cpp 
	./a.out 6
	echo $counter 
	iverilog -o hello placement_1hop_mults1.v
	vvp hello > mults1_100/$name
done

for counter in $(seq 1 100); do
	name=res_$counter 
	#simple
	g++ gera.cpp 
	./a.out 4
	echo $counter 
	iverilog -o hello placement_1hop_simple.v
	vvp hello > simple_100/$name
done
