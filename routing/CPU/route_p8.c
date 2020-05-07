#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 100
#define TAM 10

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

	int edges = 96;
	//E1
	int e_a[edges];
	int e_b[edges];

	e_a[0] = 77; e_b[0] = 80;
        e_a[1] = 73; e_b[1] = 77;
        e_a[2] = 81, e_b[2] = 77;
        e_a[3] = 69; e_b[3] = 73;
        e_a[4] = 78; e_b[4] = 73;
        e_a[5] = 79; e_b[5] = 81;
        e_a[6] = 65; e_b[6] = 69;
        e_a[7] = 74; e_b[7] = 69;
        e_a[8] = 75; e_b[8] = 78;
        e_a[9] = 76; e_b[9] = 79;
        e_a[10] = 60; e_b[10] = 65;
        e_a[11] = 71; e_b[11] = 65;
        e_a[12] = 70; e_b[12] = 74;
        e_a[13] = 72; e_b[13] = 76;
        e_a[14] = 64; e_b[14] = 60;
        e_a[15] = 53; e_b[15] = 60;
        e_a[16] = 67; e_b[16] = 71;
        e_a[17] = 66; e_b[17] = 70;
        e_a[18] = 68; e_b[18] = 72;
        e_a[19] = 59; e_b[19] = 64;
        e_a[20] = 62; e_b[20] = 64;
        e_a[21] = 51; e_b[21] = 53;
        e_a[22] = 43; e_b[22] = 53;
        e_a[23] = 61; e_b[23] = 66;
        e_a[24] = 63; e_b[24] = 68;
        e_a[25] = 53; e_b[25] = 59;
        e_a[26] = 55; e_b[26] = 59;
        e_a[27] = 56; e_b[27] = 62;
        e_a[28] = 41; e_b[28] = 51;
        e_a[29] = 57; e_b[29] = 51;
        e_a[30] = 30; e_b[30] = 43;
        e_a[31] = 54; e_b[31] = 61;
        e_a[32] = 58; e_b[32] = 63;
        e_a[33] = 42; e_b[33] = 52;
        e_a[34] = 49; e_b[34] = 52;
        e_a[35] = 46; e_b[35] = 55;
        e_a[36] = 48; e_b[36] = 56;
        e_a[37] = 44; e_b[37] = 41;
        e_a[38] = 28; e_b[38] = 41;
        e_a[39] = 47; e_b[39] = 30;         
        e_a[40] = 6; e_b[40] = 30;
        e_a[41] = 45; e_b[41] = 54;
        e_a[42] = 50; e_b[42] = 58;
        e_a[43] = 37; e_b[43] = 42;
        e_a[44] = 29; e_b[44] = 42;
        e_a[45] = 36; e_b[45] = 49;
        e_a[46] = 33; e_b[46] = 46;
        e_a[47] = 35; e_b[47] = 48;
        e_a[48] = 31; e_b[48] = 44;
        e_a[49] = 4; e_b[49] = 28;
        e_a[50] = 40; e_b[50] = 28;
        e_a[51] = 34; e_b[51] = 47;
        e_a[52] = 38; e_b[52] = 47;
        e_a[53] = 32; e_b[53] = 45;
        e_a[54] = 49; e_b[54] = 50;
        e_a[55] = 21; e_b[55] = 37;
        e_a[56] = 18; e_b[56] = 37;
        e_a[57] = 5; e_b[57] = 29;
        e_a[58] = 24; e_b[58] = 29;
        e_a[59] = 26; e_b[59] = 33;
        e_a[60] = 15; e_b[60] = 33;
        e_a[61] = 17; e_b[61] = 35;
        e_a[62] = 19; e_b[62] = 31;
        e_a[63] = 7; e_b[63] = 31;
        e_a[64] = 23; e_b[64] = 40;
        e_a[65] = 25; e_b[65] = 34;
        e_a[66] = 16; e_b[66] = 34;
        e_a[67] = 22; e_b[67] = 38;
        e_a[68] = 20; e_b[68] = 32;
        e_a[69] = 13; e_b[69] = 32;
        e_a[70] = 27; e_b[70] = 29;
        e_a[71] = 1; e_b[71] = 21;
        e_a[72] = 2; e_b[72] = 24;
        e_a[73] = 12; e_b[73] = 26;
        e_a[74] = 0; e_b[74] = 17;
        e_a[75] = 3; e_b[75] = 19;
        e_a[76] = 9; e_b[76] = 23;
        e_a[77] = 11; e_b[77] = 25;
        e_a[78] = 8; e_b[78] = 20;
        e_a[79] = 14; e_b[79] = 27;
        e_a[80] = 1; e_b[80] = 18;
        e_a[81] = 1; e_b[81] = 19;
        e_a[82] = 1; e_b[82] = 20;
        e_a[83] = 2; e_b[83] = 21;
        e_a[84] = 2; e_b[84] = 22;
        e_a[85] = 2; e_b[85] = 23;
        e_a[86] = 2; e_b[86] = 25;
        e_a[87] = 2; e_b[87] = 26;
        e_a[88] = 2; e_b[88] = 27;
        e_a[89] = 10; e_b[89] = 24;
        e_a[90] = 18; e_b[90] = 36;
        e_a[91] = 22; e_b[91] = 39;
        e_a[92] = 38; e_b[92] = 45;
        e_a[93] = 49; e_b[93] = 57;
        e_a[94] = 62; e_b[94] = 67;
        e_a[95] = 71; e_b[95] = 75;

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {1,  255,   1,  21,   5,  24,  255,   2,  255,  255,  255,  255,
		  18,  37,  29,  33,  15,  10,  255,  255,  11,   0,  36,  42,
		  46,  26,   9,  12,  14,  255,   3,  17,  49,  52,  55,  40,
		  23,  13,  27,  255,  19,  35,  56,  59,   4,  45,  54,  61,
		  39,  255,  31,  48,  62,  64,  28,  32,  70,  66,  50,   8,
		  44,   7,  41,  60,  65,  69,  74,  20,  58,  63,  25,  57,
		  51,  53,  71,  73,  77,  80,  72,  68,  38,   6,  43,  67,
		  75,  78,  81,  79,  76,  255,  34,  47,  30,  16,  22,  255,
		  255,  255,  255,  255 };

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




