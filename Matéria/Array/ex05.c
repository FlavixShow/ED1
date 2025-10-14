#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	
	int x, n;
	
	printf("Valores de X e N: ");
	scanf("%i %i", &x, &n);
	printf("\n");
	int tab[n][n];
	
	srand(time(NULL));
	
	printf("(Indice -> Valor)\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			tab[i][j] = 1 + rand() % x;
			printf("%i%i -> %02i\t", i+1, j+1, tab[i][j]);
		}
		printf("\n\n");
	}
	
}
