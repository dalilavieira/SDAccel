#include <stdio.h>
#include <stdlib.h>
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

void sum(int *vet, int TAM){
	int i, overflow;
	for(i=TAM-1;i>=0;i--){
		if(i==TAM-1){
			if(vet[i] == 0){
				vet[i] = 1;
				overflow = 0;
				break;
			}
			else{
				vet[i] = 0;
				overflow = 1;
			}
		}
		else{
			if(vet[i] == 0 && overflow == 1){
				vet[i] = 1;
				overflow = 0;
				break;
			}
			else{
				vet[i] = 0;
				overflow = 1;
			}
		}
	}
}	

long long int rng(int *seed){
	long long int num;
	int i, j, outbitLFSR;
	int LFSR_reg[43], LFSR_varLFSR[43];
	int CASR_reg[37], CASR_varCASR[37], CASR_outCASR[37];
	for(i=0;i<4;i++){
		CASR_varCASR[i] = 0;
	}
	j=0;
	for(i=4;i<37;i++){
		CASR_varCASR[i] = seed[j];
		j++;
	}
	for(i=0;i<10;i++){
		LFSR_varLFSR[i] = 0;
	}
	j=0;
	for(i=10;i<43;i++){
		LFSR_varLFSR[i] = seed[j];
		j++;
	}
	CASR_outCASR[0] = CASR_varCASR[1]^CASR_varCASR[36];
    CASR_outCASR[1] = CASR_varCASR[2]^CASR_varCASR[0];
    CASR_outCASR[2] = CASR_varCASR[3]^CASR_varCASR[1];
    CASR_outCASR[3] = CASR_varCASR[4]^CASR_varCASR[2];
    CASR_outCASR[4] = CASR_varCASR[5]^CASR_varCASR[3];
    CASR_outCASR[5] = CASR_varCASR[6]^CASR_varCASR[4];
    CASR_outCASR[6] = CASR_varCASR[7]^CASR_varCASR[5];
    CASR_outCASR[7] = CASR_varCASR[8]^CASR_varCASR[6];
    CASR_outCASR[8] = CASR_varCASR[9]^CASR_varCASR[7];
    CASR_outCASR[9] = CASR_varCASR[10]^CASR_varCASR[9]^CASR_varCASR[8];
    CASR_outCASR[10] = CASR_varCASR[11]^CASR_varCASR[9];
    CASR_outCASR[11] = CASR_varCASR[12]^CASR_varCASR[10];
    CASR_outCASR[12] = CASR_varCASR[13]^CASR_varCASR[11];
    CASR_outCASR[13] = CASR_varCASR[14]^CASR_varCASR[12];
    CASR_outCASR[14] = CASR_varCASR[15]^CASR_varCASR[13];
    CASR_outCASR[15] = CASR_varCASR[16]^CASR_varCASR[14];
    CASR_outCASR[16] = CASR_varCASR[17]^CASR_varCASR[15];
    CASR_outCASR[17] = CASR_varCASR[18]^CASR_varCASR[16];
    CASR_outCASR[18] = CASR_varCASR[19]^CASR_varCASR[17];
    CASR_outCASR[19] = CASR_varCASR[20]^CASR_varCASR[18];
    CASR_outCASR[20] = CASR_varCASR[21]^CASR_varCASR[19];
    CASR_outCASR[21] = CASR_varCASR[22]^CASR_varCASR[20];
    CASR_outCASR[22] = CASR_varCASR[23]^CASR_varCASR[21];
    CASR_outCASR[23] = CASR_varCASR[24]^CASR_varCASR[22];
    CASR_outCASR[24] = CASR_varCASR[25]^CASR_varCASR[23];
    CASR_outCASR[25] = CASR_varCASR[26]^CASR_varCASR[24];
    CASR_outCASR[26] = CASR_varCASR[27]^CASR_varCASR[25];
    CASR_outCASR[27] = CASR_varCASR[28]^CASR_varCASR[26];
    CASR_outCASR[28] = CASR_varCASR[29]^CASR_varCASR[27];
    CASR_outCASR[29] = CASR_varCASR[30]^CASR_varCASR[28];
    CASR_outCASR[30] = CASR_varCASR[31]^CASR_varCASR[29];
    CASR_outCASR[31] = CASR_varCASR[32]^CASR_varCASR[30];
    CASR_outCASR[32] = CASR_varCASR[33]^CASR_varCASR[31];
    CASR_outCASR[33] = CASR_varCASR[34]^CASR_varCASR[32];
    CASR_outCASR[34] = CASR_varCASR[35]^CASR_varCASR[33];
    CASR_outCASR[35] = CASR_varCASR[36]^CASR_varCASR[34];
    CASR_outCASR[36] = CASR_varCASR[0]^CASR_varCASR[35];
	for(i=0;i<37;i++){
		CASR_reg[i] = CASR_outCASR[i];
	}
	outbitLFSR = LFSR_varLFSR[0];
	LFSR_varLFSR[0] = LFSR_varLFSR[1];
    LFSR_varLFSR[1] = LFSR_varLFSR[2]^outbitLFSR;
    LFSR_varLFSR[2] = LFSR_varLFSR[3];
    LFSR_varLFSR[3] = LFSR_varLFSR[4];
    LFSR_varLFSR[4] = LFSR_varLFSR[5];
    LFSR_varLFSR[5] = LFSR_varLFSR[6];
    LFSR_varLFSR[6] = LFSR_varLFSR[7];
    LFSR_varLFSR[7] = LFSR_varLFSR[8];
    LFSR_varLFSR[8] = LFSR_varLFSR[9];
    LFSR_varLFSR[9] = LFSR_varLFSR[10];
    LFSR_varLFSR[10] = LFSR_varLFSR[11];
    LFSR_varLFSR[11] = LFSR_varLFSR[12];
    LFSR_varLFSR[12] = LFSR_varLFSR[13];
    LFSR_varLFSR[13] = LFSR_varLFSR[14];
    LFSR_varLFSR[14] = LFSR_varLFSR[15];
    LFSR_varLFSR[15] = LFSR_varLFSR[16];
    LFSR_varLFSR[16] = LFSR_varLFSR[17];
    LFSR_varLFSR[17] = LFSR_varLFSR[18];
    LFSR_varLFSR[18] = LFSR_varLFSR[19];
    LFSR_varLFSR[19] = LFSR_varLFSR[20];
    LFSR_varLFSR[20] = LFSR_varLFSR[21];
    LFSR_varLFSR[21] = LFSR_varLFSR[22];
    LFSR_varLFSR[22] = LFSR_varLFSR[23]^outbitLFSR;
    LFSR_varLFSR[23] = LFSR_varLFSR[24];
    LFSR_varLFSR[24] = LFSR_varLFSR[25];
    LFSR_varLFSR[25] = LFSR_varLFSR[26];
    LFSR_varLFSR[26] = LFSR_varLFSR[27];
    LFSR_varLFSR[27] = LFSR_varLFSR[28];
    LFSR_varLFSR[28] = LFSR_varLFSR[29];
    LFSR_varLFSR[29] = LFSR_varLFSR[30];
    LFSR_varLFSR[30] = LFSR_varLFSR[31];
    LFSR_varLFSR[31] = LFSR_varLFSR[32];
    LFSR_varLFSR[32] = LFSR_varLFSR[33];
    LFSR_varLFSR[33] = LFSR_varLFSR[34];
    LFSR_varLFSR[34] = LFSR_varLFSR[35];
    LFSR_varLFSR[35] = LFSR_varLFSR[36];
    LFSR_varLFSR[36] = LFSR_varLFSR[37];
    LFSR_varLFSR[37] = LFSR_varLFSR[38];
    LFSR_varLFSR[38] = LFSR_varLFSR[39];
    LFSR_varLFSR[39] = LFSR_varLFSR[40];
    LFSR_varLFSR[40] = LFSR_varLFSR[41];
    LFSR_varLFSR[41] = LFSR_varLFSR[42]^outbitLFSR;
    LFSR_varLFSR[42] = LFSR_varLFSR[0];
	for(i=0;i<43;i++){
		LFSR_reg[i] = LFSR_varLFSR[i];
	}
	num = convBin(LFSR_reg,43)^convBin(CASR_reg,37);
	if(num < 0){
		num *= -1;
	}
	return num;
}

int main(){
  int n_node, n_edge, n, size_offset, WALK;
  n_node = 46;
  n_edge = 52;
  n = 7;
  size_offset = 62;
  WALK = 4;
  int state, i, j, k, a, b;
  long long int pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, xi, xj;
  long long int sum_mesh=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  long long int pos_X[n_node], pos_Y[n_node];
  long long int grid[n][n];
  //int seed[32] = {1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0};
  int seed[32] = {0,0,1,1,0,1,0,0,1,0,1,1,0,0,0,1,1,1,0,1,1,0,1,1,1,0,1,1,1,1,1,0};
  long long int opcX0[62] = {0, 0, 1, 0,-1,-1, 1, 1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  long long int opcX1[62] = {0,-1, 0, 1, 0,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  long long int opcX2[62] = {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  long long int opcX3[62] = {0,-1, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};

  long long int opcY0[62] = {0, 1, 0,-1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
   2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  long long int opcY1[62] = {0, 0, 1, 0,-1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  long long int opcY2[62] = {0,-1, 0, 1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  long long int opcY3[62] = {0, 0, 0,-1, 1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};

  state = 0;
  while(state != 5){
    switch(state){
      case 0:
        e_a[0] = 24; e_b[0] = 34;
        e_a[1] = 40; e_b[1] = 24;
        e_a[2] = 11; e_b[2] = 24;
        e_a[3] = 43; e_b[3] = 40;
        e_a[4] = 33; e_b[4] = 40;
        e_a[5] = 39; e_b[5] = 43;
        e_a[6] = 45; e_b[6] = 33;
        e_a[7] = 23; e_b[7] = 33;
        e_a[8] = 32; e_b[8] =39;
        e_a[9] = 44; e_b[9] = 45;
        e_a[10] = 38; e_b[10] = 23;
        e_a[11] = 10; e_b[11] = 23;
        e_a[12] = 41; e_b[12] = 32;
        e_a[13] = 22; e_b[13] = 32;
        e_a[14] = 42; e_b[14] = 44;
        e_a[15] = 37; e_b[15] = 38;
        e_a[16] = 31; e_b[16] = 38;
        e_a[17] = 35; e_b[17] = 41;
        e_a[18] = 29; e_b[18] = 22;
        e_a[19] = 9; e_b[19] = 22;
        e_a[20] = 36; e_b[20] = 42;
        e_a[21] = 30; e_b[21] = 37;
        e_a[22] = 21; e_b[22] = 31;
        e_a[23] = 27; e_b[23] = 35;
        e_a[24] = 26; e_b[24] = 29;
        e_a[25] = 19; e_b[25] = 29;
        e_a[26] = 28; e_b[26] = 36;
        e_a[27] = 20; e_b[27] = 30;
        e_a[28] = 25; e_b[28] = 21;
        e_a[29] = 8; e_b[29] = 21;
        e_a[30] = 16; e_b[30] = 27;
        e_a[31] = 15; e_b[31] = 26;
        e_a[32] = 13; e_b[32] = 19;
        e_a[33] = 6; e_b[33] = 19;
        e_a[34] = 18; e_b[34] = 28;
        e_a[35] = 12; e_b[35] = 20;
        e_a[36] = 7; e_b[36] = 20;
        e_a[37] = 14; e_b[37] = 25;
        e_a[38] = 17; e_b[38] = 25;
        e_a[39] = 0; e_b[39] = 16;
        e_a[40] = 3; e_b[40] = 13;
        e_a[41] = 1; e_b[41] = 18;
        e_a[42] = 2; e_b[42] = 12;
        e_a[43] = 4; e_b[43] = 14;
        e_a[44] = 5; e_b[44] = 17;
        e_a[45] = 0; e_b[45] = 12;
        e_a[46] = 0; e_b[46] = 13;
        e_a[47] = 0; e_b[47] = 14;
        e_a[48] = 0; e_b[48] = 15;
        e_a[49] = 1; e_b[49] = 17;
        e_a[50] = 27; e_b[50] = 30;
        e_a[51] = 36; e_b[51] = 31;

        for(i=0; i<n; i++){
          for(j=0; j<n; j++){
            grid[i][j] = -1;
          }
        }
        for(i=0; i<n_node; i++){
          pos_X[i] = -1;
          pos_Y[i] = -1;
        }
        a = e_a[0];
		pos_X[a] = rng(seed) % n;
		sum(seed,32);
        pos_Y[a] = rng(seed) % n;
		sum(seed,32);
        grid[pos_X[a]][pos_Y[a]] = a;
        i=0;
        j=0;
        state = 1;
        break;
      case 1:
        if(i == n_edge){
          state = 4;
          i=0;
          break;
        }
        a = e_a[i];
        b = e_b[i];
        pos_a_X = pos_X[a];
        pos_a_Y = pos_Y[a];
        pos_b_X = pos_X[b];
        pos_b_Y = pos_Y[b];
        if(i==0){
          state = 3;
        }
        else{
          state = 2;
        }
        break;
      case 2://Posição X de a
        if(pos_a_X != -1){
          state = 3;
          j=0;
          break;
        }
        k = rng(seed) % WALK;
		sum(seed,32);
        if (pos_b_X == -1) {
          if(k == 0){
            xi = (rng(seed) % n) + opcX0[j];
			sum(seed,32);
            xj = (rng(seed) % n) + opcY0[j];
			sum(seed,32);
          }
          else if(k == 1){
            xi = (rng(seed) % n) + opcX1[j];
			sum(seed,32);
            xj = (rng(seed) % n) + opcY1[j];
			sum(seed,32);
          }
          else if(k == 2){
            xi = (rng(seed) % n) + opcX2[j];
			sum(seed,32);
            xj = (rng(seed) % n) + opcY2[j];
			sum(seed,32);
          }
          else{
            xi = (rng(seed) % n) + opcX3[j];
			sum(seed,32);
            xj = (rng(seed) % n) + opcY3[j];
			sum(seed,32);
          }
        }
        else {
          if(k == 0){
            xi = pos_b_X + opcX0[j];
            xj = pos_b_Y + opcY0[j];
          }
          else if(k == 1){
            xi = pos_b_X + opcX1[j];
            xj = pos_b_Y + opcY1[j];
          }
          else if(k == 2){
            xi = pos_b_X + opcX2[j];
            xj = pos_b_Y + opcY2[j];
          }
          else{
            xi = pos_b_X + opcX3[j];
            xj = pos_b_Y + opcY3[j];
          }
        }
        j++;
        if(grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0){
          grid[xi][xj] = a;
          pos_X[a] = xi;
          pos_Y[a] = xj;
          pos_a_X = xi;
          pos_a_Y = xj;
        }
        else if(j >= size_offset){
          printf("No solution\n");
          return 0;
        }
        if(pos_a_X == -1){
          state = 2;
        }
        else{
          state = 3;
          j=0;
        }
        break;
      case 3://Posição X de b
        if(pos_b_X != -1){
          state = 1;
          j=0;
          i++;
          break;
        }
        k = rng(seed) % WALK;
		sum(seed,32);
        if(k == 0){
          xi = pos_a_X + opcX0[j];
          xj = pos_a_Y + opcY0[j];
        }
        else if(k == 1){
          xi = pos_a_X + opcX1[j];
          xj = pos_a_Y + opcY1[j];
        }
        else if(k == 2){
          xi = pos_a_X + opcX2[j];
          xj = pos_a_Y + opcY2[j];
        }
        else{
          xi = pos_a_X + opcX3[j];
          xj = pos_a_Y + opcY3[j];
        }
        j++;
        if(grid[xi][xj] == -1 && xi < n && xi >= 0 && xj < n && xj >= 0){
          grid[xi][xj] = b;
          pos_b_X = xi;
          pos_b_Y = xj;
          pos_X[b] = xi;
          pos_Y[b] = xj;
          state = 1;
          j=0;
          i++;
          break;
        }
        else if(j >= size_offset){
          printf("No solution\n");
          return 0;
        }
        if(pos_b_X == -1){
          state = 3;
        }
        else{
          state = 1;
          j=0;
          i++;
        }
        break;
      case 4://Evaluation
        if(i == n_edge){
          state = 5;
          break;
        }
        a = e_a[i];
        b = e_b[i];
        diff_pos_x = pos_X[a]-pos_X[b];
        if(diff_pos_x < 0){
          diff_pos_x *= -1;
        }
        diff_pos_y = pos_Y[a]-pos_Y[b];
        if(diff_pos_y < 0){
          diff_pos_y *= -1;
        }
        sum_mesh += diff_pos_x + diff_pos_y - 1;
        sum_1hop += (diff_pos_x/2 + diff_pos_x%2) + (diff_pos_y/2 + diff_pos_y%2) - 1;
        i++;
        break;
    }
  }
  //Exibindo o grid:
  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      printf("%3lld ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\nEvaluation = %lld\nEvaluation 1-hop = %lld\n", sum_mesh, sum_1hop);
  return 1;
}
