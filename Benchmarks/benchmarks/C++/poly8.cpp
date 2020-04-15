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
	int out[d_size];
	int n15,n32;
	
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

		out[i] = (((in3[i] - in3[i])*in2[i] + 50+in3[i]* 138) * in2[i] - (in3[i]*46 - 171) * in1[i] + (((in2[i] + 90)*155*in2[i] + (38 + in3[i]*123))*in2[i] +  200+ (in3[i]* 168 - 171)*in3[i]) * in2[i] + (in2[i]*77 - 171)*in3[i]) * in2[i] + (in3[i] -171)*in3[i];
		
}
		
	for(int i=0; i<d_size; i++)
		std::cout << out[i] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec " << cpuExecTime << std::endl;
 
}
