#include <iostream>
#include <chrono>
#include <omp.h>
#define d_size 10

using namespace std::chrono;

int main(){
	int A;
	int data_in[d_size];
	int data_out[d_size];
	
//	std::cin >> d_size;
	data_in[0] = 0;
	
	for(int i=1; i<d_size; i++)
		data_in[i] = i+11;
	
	high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
	
	#pragma omp parallel
	#pragma omp for
	
	for(int i=0; i<d_size; i++){
		data_out[i] = data_in[i]; 
	}
	
	for(int i=0; i<d_size; i++)
		std::cout << data_out[i] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec Time: " << cpuExecTime << std::endl;
 
}
