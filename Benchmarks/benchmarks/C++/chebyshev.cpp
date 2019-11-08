#include <iostream>
#include <chrono>
#include <omp.h>
//#define d_size 250000
#define d_size 10

using namespace std::chrono;

int main(){
	int A;
	int data_in[d_size];
	int data_out[d_size];
	
//	std::cin >> d_size;

	//for(int i=0; i<d_size; i++)
		//data_in[i] = (unsigned short) (random() % 1024);
		
	data_in[0] = 1;
	data_in[1] = 2;
	data_in[2] = 3;
	data_in[3] = 3;
	data_in[4] = 2;
	data_in[5] = 4;
	data_in[6] = 6;
	data_in[7] = 2;
	data_in[8] = 1;
	data_in[9] = 1;
	//data_in[10] = 3;
	
	high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
	
	#pragma omp parallel
	#pragma omp for
	
	for(int i=0; i<d_size; i++){
		data_out[i] = data_in[i] * (data_in[i] * (data_in[i] * ((data_in[i] * 16 * data_in[i]) - 20)) + 5);
		//std::cout << << std::endl;
	}
	
	for(int i=0; i<d_size; i++)
		std::cout << data_out[i] << std::endl;
	
	diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    
    std::cout << "Exec " << cpuExecTime << std::endl;
 
}
