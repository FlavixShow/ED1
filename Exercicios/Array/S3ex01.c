#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int vet[100] = {0};
	int x, cont = 0;
	
	srand(time(NULL));
	for(int i = 0; i < 100; i++)
		vet[i] = 1 + rand() % 20;
	
	do{
		printf("Digite um valor X: ");
		scanf("%i", &x);
			
		for(int i = 0; i < 100; i++){
			if(vet[i] == x){
				printf("%i*\n", vet[i]);
				cont++;
				continue;
			}
			printf("%i\n", vet[i]);
		}
		
		printf("\nO número %i apareceu %i vezes.\n\n", x, cont);
		cont = 0;
	}while(x > 0);
}
