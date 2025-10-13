#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int vet[100] = {0};
	int x, cont = 0;
	
	srand(time(NULL));
	
	printf("Digite um valor X: ");
	scanf("%i", &x);
	
	for(int i = 0; i < 100; i++){
		vet[i] = 1 + rand() % 19;
		if(vet[i] == x){
			printf("%i\n", vet[i]);
			cont++;
			continue;
		}
		printf("%i\n", vet[i]);
	}
	printf("\nO número %i apareceu %i vezes.", x, cont);
}
