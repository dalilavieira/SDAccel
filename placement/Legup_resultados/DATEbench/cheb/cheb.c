#include <stdio.h>
#include <stdlib.h>

int rng(int seed){
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
	}*/
	return num;
}

int main(){
  int n_node, n_edge, n, size_offset, WALK;
  n_node = 19;
  n_edge = 22;
  n = 5;
  size_offset = 62;
  WALK = 4;
  int state, i, j, k, a, b;
  int pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, xi, xj;
  int sum_mesh=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  int pos_X[n_node], pos_Y[n_node];
  int grid[n][n];
  int seed = 1993114092;
  int opcX0[62] = {0, 0, 1, 0,-1,-1, 1, 1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  int opcX1[62] = {0,-1, 0, 1, 0,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  int opcX2[62] = {0, 0, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};
  int opcX3[62] = {0,-1, 1, 0,-1,-1, 1,  1, -1, 0, 2, 0,-2,-1, 1, 1,-1,-2, 2, 2, -2, 0, 3, 0, 0,-3, 2, 2,-2,
  -2, 1, 3,
  3, 1, -1, -3,-3,-1, 0, 4, 0,-4, 2, 3, 3, 2,-2,-3,-3,-2, 1, 4, 4, 1,-1,-4,-4,-1, 0, 5, 0,-5};

  int opcY0[62] = {0, 1, 0,-1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
   2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  int opcY1[62] = {0, 0, 1, 0,-1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  int opcY2[62] = {0,-1, 0, 1, 0, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};
  int opcY3[62] = {0, 0, 0,-1, 1, 1, 1, -1, -1, 2, 0,-2, 0, 2, 2,-2,-2, 1, 1,-1, -1, 3, 0, 3,-3, 0, 2,-2,-2,
  2, 3, 1,
  -1,-3, -3, -1, 1, 3, 4, 0,-4, 0, 3, 2,-2,-3,-3,-2, 2, 3, 4, 1,-1,-4,-4,-1, 1, 4, 5, 0,-5, 0};

  state = 0;
  while(state != 5){
    switch(state){
      case 0:
        e_a[0] = 11; e_b[0] = 15;
        e_a[1] = 18; e_b[1] = 11;
        e_a[2] = 7; e_b[2] = 11;
        e_a[3] = 17; e_b[3] = 18;
        e_a[4] = 14; e_b[4] = 7;
        e_a[5] = 3; e_b[5] = 7;
        e_a[6] = 16; e_b[6] = 17;
        e_a[7] = 10; e_b[7] = 14;
        e_a[8] = 12; e_b[8] = 16;
        e_a[9] = 13; e_b[9] = 10;
        e_a[10] = 6; e_b[10] = 10;
        e_a[11] = 9; e_b[11] = 12;
        e_a[12] = 8; e_b[12] = 6;
        e_a[13] = 2; e_b[13] = 6;
        e_a[14] = 5; e_b[14] = 9;
        e_a[15] = 4; e_b[15] = 8;
        e_a[16] = 0; e_b[16] = 5;
        e_a[17] = 1; e_b[17] = 4;
        e_a[18] = 0; e_b[18] = 4;
        e_a[19] = 5; e_b[19] = 8;
        e_a[20] = 9; e_b[20] = 13;
        e_a[21] = 16; e_b[21] = 14;

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
		seed = seed + 1;
        pos_Y[a] = rng(seed) % n;
        seed = seed + 1;
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
        seed = seed + 1;
        if (pos_b_X == -1) {
          if(k == 0){
            xi = (rng(seed) % n) + opcX0[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY0[j];
            seed = seed + 1;
          }
          else if(k == 1){
            xi = (rng(seed) % n) + opcX1[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY1[j];
            seed = seed + 1;
          }
          else if(k == 2){
            xi = (rng(seed) % n) + opcX2[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY2[j];
            seed = seed + 1;
          }
          else{
            xi = (rng(seed) % n) + opcX3[j];
            seed = seed + 1;
            xj = (rng(seed) % n) + opcY3[j];
            seed = seed + 1;
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
        seed = seed + 1;
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
      printf("%3d ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\nEvaluation = %d\nEvaluation 1-hop = %d\n", sum_mesh, sum_1hop);
  return 1;
}
