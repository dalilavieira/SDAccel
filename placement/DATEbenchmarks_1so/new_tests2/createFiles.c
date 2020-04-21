#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char** argv){
	FILE *arq, *eA, *eB;
	int n_edges, n_nodes, i, e_a, e_b, n;
	int cont=0;
	char aux;
	arq = fopen(argv[1],"r");
	eA = fopen("eaData.txt","w");
	eB = fopen("ebData.txt","w");
	fscanf(arq,"%d %d",&n_nodes, &n_edges);
	fscanf(arq,"%c",&aux);
	for(i=0;i<n_edges;i++){
		fscanf(arq,"%d %d", &e_a, &e_b);
		if(e_a == e_b){
			i--;
			n_edges--;
		}
		else{
			fprintf(eA,"%X\n",e_a);
			fprintf(eB,"%X\n",e_b);
			cont++;
		}
	}
	printf("n_edge = %d\n", n_edges);
	fclose(arq);
	n = ceil(sqrt(n_edges));
	n = pow(2,n);
	for(i=0;i<(n-cont);i++){
		fprintf(eA,"0\n");
		fprintf(eB,"0\n");
	}
	fclose(eA);
	fclose(eB);
	return 0;
}