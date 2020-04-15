#include <iostream>
#include <chrono>
#include <omp.h>
#define d_size 63

using namespace std::chrono;

void runCPU(unsigned short *data_in, unsigned short *data_out, unsigned short *coef, int data_size, int size) {

    high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();

    #pragma omp parallel
    #pragma omp for
    for (int j = 0; j < data_size - size; j++) {
        unsigned short fir = 0;
        for (int k = 0; k < size; ++k) {
            fir += data_in[j + k] * coef[size - 1 - k];
        }
        data_out[j] = fir;
    }

    for (int j = 0; j < data_size ; j++)
		std::cout << data_out[j] << std::endl;

    diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
     std::cout << "Exec " << cpuExecTime << std::endl;
}

int main(){
    unsigned short data_in[d_size];
    unsigned short data_out[d_size];
    unsigned short coef[d_size];
    int size = 4;

    for(int i=0; i<d_size; i++) {
        data_in[i] = i;
        coef[i] = i;
    }
        
    runCPU(data_in, data_out, coef,d_size, size);

    return 0;
		
}


    

