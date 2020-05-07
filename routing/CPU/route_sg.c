#include <stdio.h> 
#include <limits.h> 

//TODO: definir um valor pra INT_MAX, se der problemas cm limits.h
//TODO: fazer flag e remover exit(1)
#define V 49
#define TAM 7

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

	int edges = 52;
	//E1
	int e_a[edges];
	int e_b[edges];
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

	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {35,  41,  32,  39,  43,  40,  24,   9,  22,  10,  23,  33,
		  11,  34,  27,  29,  37,  38,  45,  255,  255,  26,  30,  21,
		  31,  44,   5,  255,  16,  19,  20,  25,  42,  36,  28,  15,
		  13,   8,  12,  14,  18,   1,   0,   6,   7,  17,   3,   2,  4};


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




