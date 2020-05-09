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

	int edges = 85;
	//E1
	int e_a[edges];
	int e_b[edges];

 	  e_a[0] = 68; e_b[0] = 67;
    	  e_a[1] = 67; e_b[1] = 66;
          e_a[2] = 67; e_b[2] = 65;
    	  e_a[3] = 65; e_b[3] = 64;
    	  e_a[4] = 65; e_b[4] = 62;
    	  e_a[5] = 64; e_b[5] = 60;
    	  e_a[6] = 64; e_b[6] = 61;
    	  e_a[7] = 61; e_b[7] = 55;
    	  e_a[8] = 61; e_b[8] = 56;
    	  e_a[9] = 56; e_b[9] = 50;
    	  e_a[10] = 56; e_b[10] = 49;
    	  e_a[11] = 49; e_b[11] = 38;
    	  e_a[12] = 49; e_b[12] = 37;
    	  e_a[13] = 37; e_b[13] = 20;
    	  e_a[14] = 37; e_b[14] = 21;
    	  e_a[15] = 20; e_b[15] = 5;
    	  e_a[16] = 20; e_b[16] = 6;
    	  e_a[17] = 21; e_b[17] = 5;
    	  e_a[18] = 38; e_b[18] = 22;
    	  e_a[19] = 22; e_b[19] = 5;
    	  e_a[20] = 50; e_b[20] = 39;
    	  e_a[21] = 39; e_b[21] = 23;
    	  e_a[22] = 23; e_b[22] = 5;
    	  e_a[23] = 55; e_b[23] = 47;
    	  e_a[24] = 47; e_b[24] = 34;
    	  e_a[25] = 47; e_b[25] = 36;
    	  e_a[26] = 36; e_b[26] = 19;
    	  e_a[27] = 36; e_b[27] = 18;
    	  e_a[28] = 18; e_b[28] = 3;
    	  e_a[29] = 19; e_b[29] = 5;
    	  e_a[30] = 19; e_b[30] = 16;
    	  e_a[31] = 16; e_b[31] = 1;
    	  e_a[32] = 34; e_b[32] = 15;
    	  e_a[33] = 15; e_b[33] = 5;
    	  e_a[34] = 15; e_b[34] = 1;
    	  e_a[35] = 60; e_b[35] = 57;
    	  e_a[36] = 60; e_b[36] = 54;
    	  e_a[37] = 54; e_b[37] = 46;
    	  e_a[38] = 54; e_b[38] = 48;
    	  e_a[39] = 48; e_b[39] = 41;
    	  e_a[40] = 48; e_b[40] = 35;
    	  e_a[41] = 35; e_b[41] = 26;
    	  e_a[42] = 35; e_b[42] = 17;
    	  e_a[43] = 17; e_b[43] = 2;
    	  e_a[44] = 26; e_b[44] = 5;
    	  e_a[45] = 41; e_b[45] = 25;
    	  e_a[46] = 25; e_b[46] = 5;
    	  e_a[47] = 46; e_b[47] = 32;
    	  e_a[48] = 32; e_b[48] = 13;
    	  e_a[49] = 13; e_b[49] = 1;
    	  e_a[50] = 57; e_b[50] = 51;
    	  e_a[51] = 51; e_b[51] = 40;
    	  e_a[52] = 40; e_b[52] = 24;
    	  e_a[53] = 24; e_b[53] = 5;
    	  e_a[54] = 62; e_b[54] = 58;
    	  e_a[55] = 58; e_b[55] = 52;
    	  e_a[56] = 52; e_b[56] = 45;
    	  e_a[57] = 52; e_b[57] = 42;
    	  e_a[58] = 42; e_b[58] = 33;
    	  e_a[59] = 42; e_b[59] = 27;
    	  e_a[60] = 27; e_b[60] = 19;
    	  e_a[61] = 27; e_b[61] = 7;
    	  e_a[62] = 7; e_b[62] = 0;
    	  e_a[63] = 33; e_b[63] = 14;
    	  e_a[64] = 14; e_b[64] = 1;
    	  e_a[65] = 45; e_b[65] = 31;
    	  e_a[66] = 31; e_b[66] = 12;
    	  e_a[67] = 12; e_b[67] = 1;
    	  e_a[68] = 66; e_b[68] = 63;
    	  e_a[69] = 63; e_b[69] = 59;
    	  e_a[70] = 59; e_b[70] = 53;
    	  e_a[71] = 53; e_b[71] = 44;
    	  e_a[72] = 53; e_b[72] = 43;
    	  e_a[73] = 43; e_b[73] = 28;
    	  e_a[74] = 43; e_b[74] = 30;
    	  e_a[75] = 28; e_b[75] = 10;
    	  e_a[76] = 28; e_b[76] = 8;
    	  e_a[77] = 8; e_b[77] = 1;
    	  e_a[78] = 8; e_b[78] = 4;
    	  e_a[79] = 10; e_b[79] = 1;
    	  e_a[80] = 30; e_b[80] = 11;
    	  e_a[81] = 11; e_b[81] = 1;
    	  e_a[82] = 44; e_b[82] = 29;
    	  e_a[83] = 29; e_b[83] = 9;
    	  e_a[84] = 9; e_b[84] = 1;


	int a[edges], b[edges];
	int A, B;

	int origem, destino;

	int entradas[V][4];
	int saidas[V][4];
	int indice_e[V];
	int indice_s[V];

	int grid[] = {  50,   22,   39,  255,  255,  255,   26,  255,  255,   56,   38,   23,   21,   25,   41,   35,  255,
255,   49,   55,   37,   20,    6,   48,   17,    2,  255,   61,   64,   60,    5,   57,   54,   46,   32,   13,   66,   65,   47,
36,   18,    3,  255,  255,  255,   67,   62,   34,   19,   51,   40,   24,  255,  255,   68,   15,   58,   16,    1,  255,  255,
255,  255,   27,   42,   52,   14,  255,  255,  255,  255,  255,    7,   33,   45,    0,   31,   12,  255,  255,  255 };


	//forma vetor de vertices de origem
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_a[j] == grid[i]){
				a[j] = i;
				//printf("%d\n", i);
			}
		}
	}
	//printf("\n");
	for (int j=0; j<edges; j++){
		for (int i=0; i<TAM*TAM; i++){
			if(e_b[j] == grid[i]){
				b[j] = i;
				//printf("%d\n", i);
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

	/*for(i=0; i<V; i++){
		for(j=0; j<V; j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	dijkstra(m, 0, 5, parent);
	printPath(parent, 5); 
	printf("\n");
        printf("%d\n",PTAM);*/

	for(i=0; i<edges; i++){
		A = a[i];
		B = b[i];
		//printf("%d ",A);
		dijkstra(m, A, B, parent);
		//printPath(parent, B);
		//printf("\n");
		
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

			//printf("origem=%d dest=%d\n",origem,destino);

			if(indice_s[origem]<4 & indice_e[destino]<4){
				entradas[destino][indice_e[destino]] = origem;
				saidas[origem][indice_s[origem]] = destino;
				indice_e[destino] += 1;
				indice_s[origem] +=1;
			}else{
				//printf("DEU RUIM\n");
				FLAG = 1;
				//exit(1);
				break;
			}	
			j++;		
		}
		if(FLAG == 1)
			break;
		//printf("\n");
	}

//	for(i=0; i<V; i++){
//		printf("entradas do PE%d: ",i);
//		for(j=0; j<indice_e[i]; j++){
//			printf("%d ", entradas[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//	printf("\n");
//
//	for(i=0; i<V; i++){
//		printf("saidas do PE%d: ",i);
//		for(j=0; j<indice_s[i]; j++){
//			printf("%d ", saidas[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");

}
