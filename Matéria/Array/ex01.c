#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int vet[100] = {0};
	int x, cont = 0;
	
	srand(time(NULL));
	
	printf("Digite um valor X: ");
	scanf("%i", &x);
	
	// está fora para que todos os valores de X usarem os mesmos valores
	for(int i = 0; i < 100; i++)
		vet[i] = 1 + rand() % 19;
		
	for(int j = x; j > 0; j--){
		for(int i = 0; i < 100; i++){
			if(vet[i] == j){
				printf("%i*\n", vet[i]);
				cont++;
				continue;
			}
			printf("%i\n", vet[i]);
		}
		printf("\nO número %i apareceu %i vezes.\n\n", x--, cont);
		cont = 0;
	}
	
}
