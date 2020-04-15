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
	int A;
	int in1[d_size];
	int in2[d_size];
	int in3[d_size];
	int data_out[d_size];
	
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
		data_out[i] = (unsigned short) in3[i] + 9*pot(in3[i],2) + pot(in1[i],2) + 43*in1[i] + 6*in1[i]*in3[i] + 43*in2[i] + 6*in2[i]*in3[i] + pot(in2[i],2) + 2*in1[i]*in2[i];
          
	}
	
	for(int i=0; i<d_size; i++)
		std::cout << data_out[i] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec " << cpuExecTime << std::endl;
 
}
