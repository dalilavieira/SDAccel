#include <iostream>
#include <chrono>
#include <omp.h>
#define d_size 250000

using namespace std::chrono;

int main(){
    unsigned short data_in[3][d_size];
    unsigned short data_out[d_size];

    for(int i=0; i<3; i++)
        for(int j=0; j<d_size; j++)
            data_in[i][j] = (unsigned short) (random() % 1024);

    high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
    
#pragma omp parallel
#pragma omp for
    for (int i = 0; i < d_size; ++i) {
        int pas, pbs, pcs;
        bool test_1, test_2, test_3, test_4;
        pas = data_in[1][i] - data_in[2][i];
        pbs = data_in[0][i] - data_in[2][i];
        pcs = data_in[0][i] | (data_in[1][i] - 2 * data_in[2][i]);
        test_1 = abs(pas) <= abs(pbs);
        test_2 = abs(pas) <= abs(pcs);
        test_4 = abs(pbs) <= abs(pcs);
        test_3 = test_1 && test_2;
        if (test_3) data_out[i] = data_in[0][i];
        else if (test_4) data_out[i] = data_in[1][i];
        else data_out[i] = data_in[2][i];
    }

    for (int i = 0; i < d_size; ++i)
        std::cout << data_out[i] << std::endl;

    diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;

    std::cout << "Exec " << cpuExecTime << std::endl;

    return 0;
}