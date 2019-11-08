#include <iostream>
#include <chrono>
#include <omp.h>
#define d_size 500

using namespace std::chrono;

int main(){

    int num_clusters, num_dim;
    int data_in[d_size][d_size];
	int data_out[d_size];
    int centroids[d_size];

    high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();

    for (int i = 0; i < d_size; i++){
        for (int j = 0; j < d_size; j++)
            data_in[i][j] = (unsigned short) (random() % 1024);
        centroids[i] = (unsigned short) (random() % 1024);
    }

#pragma omp parallel
#pragma omp for

        for (int i = 0; i < d_size; i++) {
            unsigned short min = UINT16_MAX, min_id = 0;
            for (unsigned short c = 0; c < num_clusters; c++) {
                unsigned short sum = 0;
                for (int j = 0; j < num_dim; j++) {
                    sum += data_in[j][i] - centroids[c * num_dim + j];
                }
                if (sum <= min) {
                    min = sum;
                    min_id = c;
                }
            }
            data_out[i] = min_id;
        }
    

    diff = high_resolution_clock::now() - s;
    double cpuExecTime = diff.count() * 1000;
    std::cout << "Exec " << cpuExecTime << std::endl;

    return 0;

}

