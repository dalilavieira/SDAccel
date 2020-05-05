#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*int rng(int seed){
	int num, outbitLFSR;
	int LFSR_reg, CASR_reg;
	CASR_reg = seed;
	LFSR_reg = seed;
	CASR_reg = CASR_reg ^ (CASR_reg-1);
	//printf("CASR_outCASR: %d\n", CASR_reg);
	outbitLFSR = 1;
	LFSR_reg = LFSR_reg ^ outbitLFSR;
	//printf("LFSR_varLFSR: %d\n", LFSR_reg);
	num = LFSR_reg ^ CASR_reg;
	/*if(num < 0){
		num *= -1;
	}
	return num;
}*/


int main(){
	srand(time(NULL));
	int seed, i;
	seed = rand();
	printf("Seed: %d\n", seed);
	//printf("Random Number 1: %lld\n", rng(seed));
	//seed++;
	//printf("Seed: %d\n", seed);
	//printf("Random Number 2: %lld\n", rng(seed));
	return 0;
}