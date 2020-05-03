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
  n_node = 118;
  n_edge = 142;
  n = 11;
  size_offset = 62;
  WALK = 4;
  int state, i, j, k, a, b;
  long long int pos_a_X, pos_a_Y, pos_b_X, pos_b_Y, xi, xj;
  long long int sum_mesh=0, sum_1hop=0, diff_pos_x, diff_pos_y;
  int e_a[n_edge], e_b[n_edge];
  long long int pos_X[n_node], pos_Y[n_node];
  long long int grid[n][n];
  //int seed[32] = {1,0,1,1,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,0,1,1,1,0,0,0,1,1,0,0};
  int seed[32] = {1,0,1,1,0,1,1,0,0,1,0,1,0,1,1,0,1,1,0,0,0,1,1,1,1,0,0,1,0,1,1,1};
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
        e_a[0] = 116; e_b[0] = 117;
        e_a[1] = 113; e_b[1] = 116;
        e_a[2] = 115, e_b[2] = 116;
        e_a[3] = 112; e_b[3] = 115;
        e_a[4] =109; e_b[4] = 112;
        e_a[5] = 105; e_b[5] = 109;
        e_a[6] = 101; e_b[6] = 105;
        e_a[7] = 94; e_b[7] = 101;
        e_a[8] = 85; e_b[8] = 94;
        e_a[9] = 92; e_b[9] = 94;
        e_a[10] = 83; e_b[10] = 92;
        e_a[11] = 72; e_b[11] = 83;
        e_a[12] = 59; e_b[12] = 72;
        e_a[13] = 45; e_b[13] = 59;
        e_a[14] = 26; e_b[14] = 45;
        e_a[15] = 2; e_b[15] = 26;
        e_a[16] = 2; e_b[16] = 24;
        e_a[17] = 11; e_b[17] = 24;
        e_a[18] = 24; e_b[18] = 24;
        e_a[19] = 44; e_b[19] = 58;
        e_a[20] = 58; e_b[20] = 71;
        e_a[21] = 71; e_b[21] = 75;
        e_a[22] = 63; e_b[22] = 75;
        e_a[23] = 50; e_b[23] = 63;
        e_a[24] = 56; e_b[24] = 63;
        e_a[25] = 56; e_b[25] = 69;
        e_a[26] = 56; e_b[26] = 51;
        e_a[27] = 36; e_b[27] = 51;
        e_a[28] = 43; e_b[28] = 36;
        e_a[29] = 13; e_b[29] = 36;
        e_a[30] = 23; e_b[30] = 43;
        e_a[31] = 25; e_b[31] = 43;
        e_a[32] = 12; e_b[32] = 25;
        e_a[33] = 1; e_b[33] = 23;
        e_a[34] = 1; e_b[34] = 21;
        e_a[35] = 1; e_b[35] = 22;
        e_a[36] = 3; e_b[36] = 22;
        e_a[37] = 22; e_b[37] = 35;
        e_a[38] = 6; e_b[38] = 35;
        e_a[39] = 21; e_b[39] = 41;
        e_a[40] = 21; e_b[40] = 42;
        e_a[41] = 28; e_b[41] = 42;
        e_a[42] = 17; e_b[42] = 28;
        e_a[43] = 42; e_b[43] = 57;  
        e_a[44] = 57; e_b[44] = 70;
        e_a[45] = 70; e_b[45] = 82;
        e_a[46] = 73; e_b[46] = 82;
        e_a[47] = 61; e_b[47] = 73;    
        e_a[48] = 61; e_b[48] = 62;
        e_a[49] = 49; e_b[49] = 62;
        e_a[50] = 34; e_b[50] = 49;
        e_a[51] = 4; e_b[51] = 34;
        e_a[52] = 32; e_b[52] = 34;
        e_a[53] = 7; e_b[53] = 32;
        e_a[54] = 62; e_b[54] = 74;
        e_a[55] = 73; e_b[55] = 84;
        e_a[56] = 84; e_b[56] = 93;
        e_a[57] = 91; e_b[57] = 93;
        e_a[58] = 81; e_b[58] = 91;
        e_a[59] = 81; e_b[59] = 90;    
        e_a[60] = 90; e_b[60] = 86;
        e_a[61] = 76; e_b[61] = 86;
        e_a[62] = 64; e_b[62] = 76;
        e_a[63] = 79; e_b[63] = 76;
        e_a[64] = 67; e_b[64] = 79;
        e_a[65] = 54; e_b[65] = 67;
        e_a[66] = 39; e_b[66] = 54;
        e_a[67] = 47; e_b[67] = 54;
        e_a[68] = 47; e_b[68] = 53;
        e_a[69] = 38; e_b[69] = 53;
        e_a[70] = 29; e_b[70] = 38;
        e_a[71] = 16; e_b[71] = 38;
        e_a[72] = 8; e_b[72] = 29;
        e_a[73] = 53; e_b[73] = 66;
        e_a[74] = 66; e_b[74] = 78;
        e_a[75] = 78; e_b[75] = 88;
        e_a[76] = 88; e_b[76] = 97;
        e_a[77] = 79; e_b[77] = 95;
        e_a[78] = 95; e_b[78] = 102;
        e_a[79] = 102; e_b[79] = 106;
        e_a[80] = 106; e_b[80] = 110;
        e_a[81] = 107; e_b[81] = 110;
        e_a[82] = 103; e_b[82] = 107;
        e_a[83] = 108; e_b[83] = 107;
        e_a[84] = 108; e_b[84] = 111;
        e_a[85] = 111; e_b[85] = 114;
        e_a[86] = 104; e_b[86] = 108;
        e_a[87] = 98; e_b[87] = 104;
        e_a[88] = 89; e_b[88] = 98;
        e_a[89] = 80; e_b[89] = 89;
        e_a[90] = 68; e_b[90] = 80;
        e_a[91] = 55; e_b[91] = 68;
        e_a[92] = 40; e_b[92] = 55;
        e_a[93] = 20; e_b[93] = 40;
        e_a[94] = 0; e_b[94] = 20;
        e_a[95] = 100; e_b[95] = 103;  
        e_a[96] = 96; e_b[96] = 103;
        e_a[97] = 87; e_b[97] = 96;
        e_a[98] = 88; e_b[98] = 87;
        e_a[99] = 65; e_b[99] = 77;
        e_a[100] = 52; e_b[100] = 65;
        e_a[101] = 37; e_b[101] = 52;
        e_a[102] = 48; e_b[102] = 37;
        e_a[103] = 15; e_b[103] = 37;
        e_a[104] = 33; e_b[104] = 48;
        e_a[105] = 31; e_b[105] = 48;
        e_a[106] = 14; e_b[106] = 33;
        e_a[107] = 49; e_b[107] = 100;
        e_a[108] = 27; e_b[108] = 39;
        e_a[109] = 18; e_b[109] = 39;
        e_a[110] = 9; e_b[110] = 27;
        e_a[111] = 2; e_b[111] = 25;
        e_a[112] = 2; e_b[112] = 27;
        e_a[113] = 2; e_b[113] = 28;
        e_a[114] = 2; e_b[114] = 29;
        e_a[115] = 2; e_b[115] = 30;
        e_a[116] = 2; e_b[116] = 31;
        e_a[117] = 2; e_b[117] = 32;
        e_a[118] = 2; e_b[118] = 33;
        e_a[119] = 5; e_b[119] = 23;
        e_a[120] = 10; e_b[120] = 26;
        e_a[121] = 19; e_b[121] = 30;
        e_a[122] = 30; e_b[122] = 46;
        e_a[123] = 31; e_b[123] = 47;
        e_a[124] = 35; e_b[124] = 50;
        e_a[125] = 41; e_b[125] = 56;
        e_a[126] = 26; e_b[126] = 60;
        e_a[127] = 47; e_b[127] = 50;
        e_a[128] = 47; e_b[128] = 61;
        e_a[129] = 51; e_b[129] = 64;
        e_a[130] = 60; e_b[130] = 73;
        e_a[131] = 61; e_b[131] = 52;
		e_a[132] = 69; e_b[132] = 81;
		e_a[133] = 69; e_b[133] = 64;
		e_a[134] = 75; e_b[134] = 85;
		e_a[135] = 81; e_b[135] = 85;
		e_a[136] = 82; e_b[136] = 91;
		e_a[137] = 86; e_b[137] = 95;
		e_a[138] = 90; e_b[138] = 99;
		e_a[139] = 93; e_b[139] = 100;
		e_a[140] = 110; e_b[140] = 113;
		e_a[141] = 114; e_b[141] = 113;

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
