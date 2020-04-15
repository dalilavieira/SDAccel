#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <iostream>
#include <chrono>
#include <omp.h>
#define d_size 8

using namespace std::chrono;

int main(){

    double pixel_value;
    double pixel_value2;
    double valor;
    int x, y, i, j;
    double total = 0;

    unsigned short image1[d_size][d_size];
    unsigned short image2[d_size][d_size];

    for(int j=0; j<d_size; j++) {
        image1[0][j] = j;
        image1[1][j] = 7;
        image1[2][j] = 3;
        image1[3][j] = 9;
        image1[4][j] = 5;
        image1[5][j] = 1;
        image1[6][j] = 6;
        image1[7][j] = 10;
    }


    high_resolution_clock::time_point s;
    duration<double> diff = {};
    s = high_resolution_clock::now();
    
    #pragma omp parallel
    #pragma omp for
        for (j = 1; j < d_size- 1; j++) {
            for (i = 1; i < d_size - 1; i++) {
     
            image2[j][i] = sqrt((image1[j-1][i-1] + 2*image1[j][i-1] + image1[j+1][i-1] - image1[j-1][i+1] - 2*image1[j][i+1] - image1[j+1][i+1])
* (image1[j-1][i-1] + 2*image1[j][i-1] + image1[j+1][i-1] - image1[j-1][i+1] - 2*image1[j][i+1] - image1[j+1][i+1]) 
+ (image1[j-1][i-1] + 2*image1[j-1][i] + image1[j-1][i+1] - image1[j+1][i-1] - 2*image1[j+1][i] - image1[j+1][i+1]) * (image1[j-1][i-1] + 2*image1[j-1][i] + image1[j-1][i+1] - image1[j+1][i-1] - 2*image1[j+1][i] - image1[j+1][i+1])); 

            }
        }

    for (j = 1; j < d_size- 1; j++)
        for (i = 1; i < d_size - 1; i++)
            std::cout << image2[j][i] << " ";

        diff = high_resolution_clock::now() - s;
        double cpuExecTime = diff.count() * 1000;

        total += cpuExecTime;

    std::cout << "Exec " << total << std::endl;

    return 0;
}
