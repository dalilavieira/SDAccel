#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 121
#define TAM 11

int minDistance(int dist[], int sptSet[]) 
{ 
	
	// Initialize min value 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (sptSet[v] == 0 && 
				dist[v] <= min) 
			min = dist[v], min_index = v; 

	return min_index; 
} 

void dijkstra(int graph[V][V], int src, int dest, int * parent) 
{ 
	int dist[V]; 
	int sptSet[V]; 

	for (int i = 0; i < V; i++) 
	{ 
		parent[src] = -1; 
		dist[i] = INT_MAX; 
		sptSet[i] = 0; 
	} 

	dist[src] = 0; 
 
	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minDistance(dist, sptSet); 

		sptSet[u] = 1; 
 
		for (int v = 0; v < V; v++) 
			if (!sptSet[v] && graph[u][v] && 
				dist[u] + graph[u][v] < dist[v]) 
			{ 
				parent[v] = u; 
				dist[v] = dist[u] + graph[u][v]; 
			} 
	} 

	// print the constructed 
	// distance array 
	//printSolution(dist, V, parent, dest); 
} 

int main(){
	int FLAG = 0;
	int parent[V];

	int i,j;
	int m[V][V];

	int edges = 142;
	//E1
	int e_a[edges];
	int e_b[edges];
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
     

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {255,  255,   78,   88,   20,   40,  102,  111, 114,  115,  116,   11,
		255,   53,   66,   97,   95,   55,  106,  108,  110,  112,  113,   24,
		16,   38,   64,   76,   86,   68,  107,  104,  105,  109,   58,   44,   
		51,   29,    8,   79,   90,   80,   89,   98,  101,   71,   75,   63,   
		36,   13,   18,   67,  100,  103,   83,   92,   94,   85,   81,   50,   
		43,   23,   39,   54,   87,   96,   72,   93,   91,   56,   69,   47,   
		25,   12,   27,   65,   77,   45,   59,  99,   84,  41,   31,   35,  
		255,    5,    9,   52,    2,   26,   62,   74,    1,   21,    6,    3,  
		255,  255,   48,   37,   61,   10,   49,   70,   82,   57,   42,   22,  
		255,  255,   33,   15,    7,   32,   34,    4,   73,   60,   28,   17,  
		255,  255,   14,  255,  255,  255,  255,  255,  255,   46,   30};


	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				printf("%d\n", i);
			}
		}
	}
	printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
				printf("%d\n", i);
			}
		}
	}	


	for(i=0; i<V; i++){
		indice_e[i] = 0;
		indice_s[i] = 0;
		for(j=0; j<V; j++){
			m[i][j] = 0;
			//printf("%d",m);
		}
	}

	for(i=0; i<TAM; i++){
		for(j=0; j<TAM; j++){
			if(i<TAM-1 & j<TAM-1){
				m[i*TAM+j][i*TAM+(j+1)] = 1; 
				m[i*TAM+(j+1)][i*TAM+j] = 1; 
				m[i*TAM+j][(i+1)*TAM+j] = 1; 
				m[(i+1)*TAM+j][i*TAM+j] = 1; 
			}else if(i<TAM-1){
				m[i*TAM+j][(i+1)*TAM+j] = 1; 
				m[(i+1)*TAM+j][i*TAM+j] = 1; 
			}else if(j<TAM-1){
				m[i*TAM+j][i*TAM+(j+1)] = 1; 
				m[i*TAM+(j+1)][i*TAM+j] = 1; 
			}
		}
	}

	for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	/*dijkstra(m, 0, 5, parent); 
	printPath(parent, 5); 
	printf("\n");
        printf("%d\n",PTAM);*/

	for(i=0; i<edges; i++){
		A = a[i];
		B = b[i];
		printf("%d ",A);
		dijkstra(m, A, B, parent);
		//printPath(parent, B);
		printf("\n");
		
		j = 0;
		while(1){
			if(j ==0 ){
				destino = B;
			}else{
				destino = origem;
			}

			origem = parent[destino];
			if(origem == -1)
				break;

			printf("origem=%d dest=%d\n",origem,destino);

			if(indice_s[origem]<4 & indice_e[destino]<4){
				entradas[destino][indice_e[destino]] = origem;
				saidas[origem][indice_s[origem]] = destino;
				indice_e[destino] += 1;
				indice_s[origem] +=1;
			}else{
				printf("DEU RUIM\n");
				FLAG = 1;
				//exit(1);
				break;
			}	
			j++;		
		}
		if(FLAG == 1)
			break;
		printf("\n");
	}

	for(i=0; i<V; i++){
		printf("entradas do PE%d: ",i);
		for(j=0; j<indice_e[i]; j++){
			printf("%d ", entradas[i][j]);
		}
		printf("\n");
	}	
	printf("\n");
	printf("\n");

	for(i=0; i<V; i++){
		printf("saidas do PE%d: ",i);
		for(j=0; j<indice_s[i]; j++){
			printf("%d ", saidas[i][j]);
		}
		printf("\n");
	}
	printf("\n");

}




