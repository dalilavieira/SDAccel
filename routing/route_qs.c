#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 81
#define TAM 9

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

	int edges = 88;
	//E1
	int e_a[edges];
	int e_b[edges];

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

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {255,  255,  255,   4,  11,  46,  56,  33,  47,  255,  255,  27,
		  255,   1,  31,  13,  14,  32,   7,  255,  43,   6,  18,  37,
		  62,  50,  12,  21,   3,  54,  17,   5,  36,  66,  39,  16,
		  255,  255,  60,  24,  23,  45,  30,  22,  35,  71,  65,  25,
		  40,  55,   8,  10,  19,  28,  70,  68,  52,  41,  48,  34,
		   0,   9,   2,  69,  67,  63,  42,  61,  15,  49,  44,  20,
		  59,  64,  58,  53,  26,  57,  38,  51,  29};


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




