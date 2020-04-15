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
	int in1[d_size], in2[d_size], in3[d_size], in4[d_size], in5[d_size], in6[d_size], in7[d_size], out[d_size], i;
	
	
//	std::cin >> d_size;

	for(int i=0; i<d_size; i++){
		in1[i] = 1;
		in2[i] = 1;
		in3[i] = 1;
		in4[i] = 1;
		in5[i] = 1;
		in6[i] = 1;
		in7[i] = 1;
	}
	
	high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
	
	#pragma omp parallel
	#pragma omp for
	
	for(int i=0; i<d_size; i++){
		out[i] = pot(in2[i],4)*in1[i] + 4*pot(in6[i],3)*in2[i]*in7[i] + 6*pot(in2[i],2)*pot(in6[i],2)*in3[i] + pot(in6[i],4)*in5[i] + 4*pot(in2[i],3)*in6[i]*in3[i];
	
	}
	
	for(int i=0; i<d_size; i++)
		std::cout << out[i] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec " << cpuExecTime << std::endl;
 
}
