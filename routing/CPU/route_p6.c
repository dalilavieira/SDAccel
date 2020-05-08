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
	100 99
99 97
99 98
98 96
96 92
92 87
87 82
82 75
75 66
75 70
70 60
60 49
49 36
36 23
23 9
9 2
66 58
66 56
56 44
44 31
31 18
18 4
4 1
58 45
58 48
48 35
35 22
22 7
7 2
45 33
45 31
33 20
33 27
27 14
14 2
20 5
5 1
97 95
97 94
95 91
91 86
86 81
81 74
74 65
65 55
55 43
43 30
30 17
17 3
3 0
94 93
94 90
93 88
88 83
83 76
83 79
79 71
71 62
62 51
51 38
38 27
38 25
25 12
12 2
76 69
76 67
67 56
69 57
69 61
61 50
50 37
37 27
37 24
24 10
10 2
57 44
57 46
46 34
46 31
34 21
21 8
21 6
8 2
6 1
90 89
90 86
89 85
89 84
85 80
80 73
73 64
64 54
54 40
54 41
40 27
41 28
28 14
28 16
16 2
84 77
84 78
77 67
78 68
78 72
72 63
63 53
53 42
53 40
42 29
29 15
15 2
68 59
68 56
59 52
59 47
47 32
32 19
19 4
19 11
11 2
52 40
52 39
39 26
26 13
13 2
     

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




