#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int n, soma = 0;
	
	printf("Insira o valor de N: ");
	scanf("%i", &n);
	
	int matriz[n][n];
	
	srand(time(NULL));
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				matriz[i][j] = 0;
				continue;
			}
			matriz[i][j] = 1 + rand() % 5;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				for(int k = 0; k < n; k++)
					soma += matriz[i][k] + matriz[k][j];
					
				matriz[i][j] = soma;
				soma = 0;
			}
		printf("%02i\t", matriz[i][j]);
		}
		printf("\n\n");
	}
	


}
