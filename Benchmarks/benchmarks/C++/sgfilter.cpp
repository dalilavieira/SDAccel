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
	int a, in1[d_size], in2[d_size], out[d_size], i;
	
//	std::cin >> d_size;

	for(int i=0; i<d_size; i++){
		in1[i] = 1;
		in2[i] = 1;
	}
	
	high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
	
	#pragma omp parallel
	#pragma omp for
	
	for(int i=0; i<d_size; i++){
		// (unsigned short) converter
		out[i] =  in1[i]* (in1[i] * (in1[i] * (-984) - 46)  - 46) + in2[i] * (in1[i]* (in1[i] * 92 - 39) + in2[i]* (in1[i] * (-76) + 7* in2[i]  + 7) + 7) - 75;
	}
	
	for(int i=0; i<d_size; i++)
		std::cout << out[i] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec " << cpuExecTime << std::endl;
 
}
