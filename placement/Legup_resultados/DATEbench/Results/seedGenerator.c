#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

long long int convBin(int *vet, int TAM){
	long long int num = 0;
	int	i, j;
	j = TAM-1;
	for(i=0;i<TAM;i++){
		num += pow(2,j)*vet[i];
		j--;
	}
	return num;
}

int main(){
	srand(time(NULL));
	int seed[32], i;
	printf("Seed: {");
	for(i=0;i<32;i++){
		seed[i] = rand() % 2;
		if(i != 31)
			printf("%d,", seed[i]);
		else
			printf("%d", seed[i]);
	}
	printf("}\n");
	printf("Seed: %lld\n", convBin(seed,32));
	return 0;
}