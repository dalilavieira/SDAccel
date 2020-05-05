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
  n_node = 72;
  n_edge = 88;
  n = 9;
  size_offset = 62;
  WALK = 4;
  int state, i, j, k, a, b;
  int pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, xi, xj;
  int sum_mesh=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  int pos_X[n_node], pos_Y[n_node];
  int grid[n][n];
  int seed = 1310511248;
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
        e_a[0] = 70; e_b[0] = 71;
        e_a[1] = 69; e_b[1] = 70;
        e_a[2] = 68, e_b[2] = 70;
        e_a[3] = 65; e_b[3] = 68;
        e_a[4] = 67; e_b[4] = 68;
        e_a[5] = 63; e_b[5] = 67;
        e_a[6] = 64; e_b[6] = 67;
        e_a[7] = 58; e_b[7] = 64;
        e_a[8] = 59; e_b[8] = 64;
        e_a[9] = 53; e_b[9] = 59;
        e_a[10] = 52; e_b[10] = 59;
        e_a[11] = 41; e_b[11] = 52;
        e_a[12] = 40; e_b[12] = 52;
        e_a[13] = 24; e_b[13] = 40;
        e_a[14] = 23; e_b[14] = 40;
        e_a[15] = 5; e_b[15] = 23;
        e_a[16] = 5; e_b[16] = 18;
        e_a[17] = 1; e_b[17] = 18;
        e_a[18] = 1; e_b[18] = 11;
        e_a[19] = 4; e_b[19] = 11;
        e_a[20] = 11; e_b[20] = 31;
        e_a[21] = 13; e_b[21] = 31;
        e_a[22] = 31; e_b[22] = 46;
        e_a[23] = 33; e_b[23] = 46;
        e_a[24] = 14; e_b[24] = 33;
        e_a[25] = 46; e_b[25] = 56;
        e_a[26] = 47; e_b[26] = 56;
        e_a[27] = 32; e_b[27] = 47;
        e_a[28] = 12; e_b[28] = 32;
        e_a[29] = 56; e_b[29] = 62;
        e_a[30] = 62; e_b[30] = 66;
        e_a[31] = 18; e_b[31] = 37;
        e_a[32] = 37; e_b[32] = 50;
        e_a[33] = 39; e_b[33] = 50;
        e_a[34] = 32; e_b[34] = 39;
        e_a[35] = 32; e_b[35] = 30;
        e_a[36] = 10; e_b[36] = 30;
        e_a[37] = 0; e_b[37] = 10;
        e_a[38] = 8; e_b[38] = 10;
        e_a[39] = 30; e_b[39] = 45;
        e_a[40] = 36; e_b[40] = 45;
        e_a[41] = 17; e_b[41] = 36;
        e_a[42] = 45; e_b[42] = 55;
        e_a[43] = 48; e_b[43] = 55;
        e_a[44] = 34; e_b[44] = 48;
        e_a[45] = 15; e_b[45] = 34;
        e_a[46] = 55; e_b[46] = 61;
        e_a[47] = 19; e_b[47] = 22;
        e_a[48] = 25; e_b[48] = 41;
        e_a[49] = 42; e_b[49] = 53;
        e_a[50] = 26; e_b[50] = 42;
        e_a[51] = 60; e_b[51] = 63;
        e_a[52] = 57; e_b[52] = 63;
        e_a[53] = 49; e_b[53] = 57;
        e_a[54] = 51; e_b[54] = 57;
        e_a[55] = 44; e_b[55] = 61;
        e_a[56] = 38; e_b[56] = 51;
        e_a[57] = 29; e_b[57] = 38;
        e_a[58] = 20; e_b[58] = 38;
        e_a[59] = 2; e_b[59] = 20;
        e_a[60] = 9; e_b[60] = 20;
        e_a[61] = 28; e_b[61] = 44;
        e_a[62] = 35; e_b[62] = 49;
        e_a[63] = 16; e_b[63] = 35;
        e_a[64] = 54; e_b[64] = 60;
        e_a[65] = 43; e_b[65] = 54;
        e_a[66] = 27; e_b[66] = 43;
        e_a[67] = 1; e_b[67] = 12;
        e_a[68] = 1; e_b[68] = 13;
        e_a[69] = 1; e_b[69] = 14;
        e_a[70] = 1; e_b[70] = 15;
        e_a[71] = 1; e_b[71] = 16;
        e_a[72] = 1; e_b[72] = 17;
        e_a[73] = 1; e_b[73] = 19;
        e_a[74] = 3; e_b[74] = 21;
        e_a[75] = 5; e_b[75] = 22;
        e_a[76] = 5; e_b[76] = 24;
        e_a[77] = 5; e_b[77] = 25;
        e_a[78] = 5; e_b[78] = 26;
        e_a[79] = 5; e_b[79] = 27;
        e_a[80] = 5; e_b[80] = 28;
        e_a[81] = 5; e_b[81] = 29;
        e_a[82] = 6; e_b[82] = 23;
        e_a[83] = 7; e_b[83] = 21;
        e_a[84] = 21; e_b[84] = 39;
        e_a[85] = 50; e_b[85] = 58;
        e_a[86] = 61; e_b[86] = 65;
        e_a[87] = 66; e_b[87] = 69;

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
