#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 64
#define TAM 8

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

	int edges = 71;
	//E1
	int e_a[edges];
	int e_b[edges];
e_a[0] = 54; e_b[0] = 56;
        e_a[1] = 58; e_b[1] = 54;
        e_a[2] = 51, e_b[2] = 54;
        e_a[3] = 52; e_b[3] = 51;
        e_a[4] = 48; e_b[4] = 51;
        e_a[5] = 43; e_b[5] = 48;
        e_a[6] = 42; e_b[6] = 48;
        e_a[7] = 30; e_b[7] = 42;
        e_a[8] = 41; e_b[8] = 30;
        e_a[9] = 13; e_b[9] = 30;
        e_a[10] = 47; e_b[10] = 41;
        e_a[11] = 28; e_b[11] = 41;
        e_a[12] = 37; e_b[12] = 28;
        e_a[13] = 11; e_b[13] = 28;
        e_a[14] = 25; e_b[14] = 37;
        e_a[15] = 25; e_b[15] = 38;
        e_a[16] = 23; e_b[16] = 38;
        e_a[17] = 2; e_b[17] = 23;
        e_a[18] = 2; e_b[18] = 20;
        e_a[19] = 3; e_b[19] = 20;
        e_a[20] = 38; e_b[20] = 29;
        e_a[21] = 12; e_b[21] = 29;
        e_a[22] = 29; e_b[22] = 34;
        e_a[23] = 17; e_b[23] = 34;
        e_a[24] = 0; e_b[24] = 17;
        e_a[25] = 0; e_b[25] = 15;
        e_a[26] = 0; e_b[26] = 16;
        e_a[27] = 27; e_b[27] = 16;
        e_a[28] = 22; e_b[28] =27;
        e_a[29] = 10; e_b[29] = 27;
        e_a[30] = 6; e_b[30] = 22;
        e_a[31] = 16; e_b[31] = 33;
        e_a[32] = 40; e_b[32] = 33;
        e_a[33] = 39; e_b[33] = 40;
        e_a[34] = 33; e_b[34] = 31;
        e_a[35] = 14; e_b[35] = 31;
        e_a[36] = 15; e_b[36] = 32;
        e_a[37] = 32; e_b[37] = 44;
        e_a[38] = 44; e_b[38] = 49;
        e_a[39] = 45; e_b[39] = 49;
        e_a[40] = 57; e_b[40] = 58;
        e_a[41] = 55; e_b[41] = 57;
        e_a[42] = 53; e_b[42] = 55;
        e_a[43] = 50; e_b[43] = 53;
        e_a[44] = 46; e_b[44] = 50;
        e_a[45] = 36; e_b[45] = 46;
        e_a[46] = 19; e_b[46] = 36;
        e_a[47] = 1; e_b[47] = 19;
        e_a[48] = 1; e_b[48] = 18;
        e_a[49] = 8; e_b[49] = 18;
        e_a[50] = 18; e_b[50] = 35;
        e_a[51] = 24; e_b[51] = 35;
        e_a[52] = 7; e_b[52] = 24;
        e_a[53] = 2; e_b[53] = 21;
        e_a[54] = 2; e_b[54] = 22;
        e_a[55] = 2; e_b[55] = 24;
        e_a[56] = 2; e_b[56] = 25;
        e_a[57] = 4; e_b[57] = 23;
        e_a[58] = 5; e_b[58] = 21;
        e_a[59] = 9; e_b[59] = 26;
        e_a[60] = 20; e_b[60] = 37;
        e_a[61] = 21; e_b[61] = 26;
        e_a[62] = 25; e_b[62] = 39;
        e_a[63] = 26; e_b[63] = 40;
        e_a[64] = 31; e_b[64] = 43;
        e_a[65] = 32; e_b[65] = 45;
        e_a[66] = 34; e_b[66] = 44;
        e_a[67] = 35; e_b[67] = 17;
        e_a[68] = 39; e_b[68] = 47;
        e_a[69] = 45; e_b[69] = 43;
        e_a[70] = 49; e_b[70] = 52;

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {58,  57,  21,  23,  29,  39,  12,  33,  54,  56,  55,  38,
   		2,  20,   3,  40,  51,  52,  53,  25,  34,  17,   0,  16,
  		48,  43,  50,  37,  11,  31,  15,  22,  255,  42,   4, 28,
 		 46,  14,   6,  27,  13,  30,  41,  47,  36,  44,  32,  10,
 		 255,   7,  24,  35,  19,  49,  255,  255,  255,  255,   8,  18,
   		1,  45,  255,  255};

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




