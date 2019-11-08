#include <iostream>
#include <chrono>
#include <omp.h>
#define d_size 10

using namespace std::chrono;

int pot(int num, int exp)
{
	int i=0, res=1;
	for(i=0; i < exp; i++)
		res = res*num;
	return res;
}


int main(){
	int in1[d_size];
	int out[d_size];
	int in2[d_size];
	int in3[d_size];
	int n33, n4, n27, n8;
	
//	std::cin >> d_size;

	for(int i=0; i<d_size; i++){
		in1[i] = 1;
		in2[i] = 1;
		in3[i] = 1;
	}
	
	high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
	
	#pragma omp parallel
	#pragma omp for
	
	for(int i=0; i<d_size; i++){
		
		out[i] = 8*in3[i]*216*(in2[i],2) + 8*in3[i]*pot(in2[i],3) + 124416*in3[i]*in2[i] + 2985984*in3[i] - in1[i]* ((6*in2[i] + 4*in3[i] -432)*in3[i]*(in2[i],2) - 414*pot(in2[i],3) - 20736*in3[i]*in2[i] - in3[i]*(3456*in2[i] - 1492992) - ((in3[i] - 32)*(in2[i],3)+ pot(in3[i],2)*(in2[i],2) - 72*in3[i]*(in2[i],2) - 2592*in3[i]*in2[i] + 87*pot(in3[i],2)*in2[i] + pot(in3[i],3) - 864*pot(in3[i],2) - 186624*in3[i])*in1[i]);
			
	}
	
	for(int i=0; i<d_size; i++)
		std::cout << out[1] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec " << cpuExecTime << std::endl;
 
}
