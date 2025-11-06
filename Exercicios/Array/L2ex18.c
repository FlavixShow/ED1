#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

int main(){
	//h-index
	srand(time(NULL));
	
	int n;
	
	scanf(" %i", &n);
	
	int vet[n];
	
	printf("[");
	for(int i = 0; i < n; i++){
		vet[i] = rand() % n;
		printf(" %i", vet[i]);
	}
	printf(" ]");
	for(int i = 0; i < n; i++){
		for(int j = (i+1); j < n; j++){
			if(vet[i] < vet[j]){
				int temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp; 
			}
		}
	}
	int h = 0;
	for(int i = 0; i < n; i++){
		if(h > vet[i]){
			break;
		}
		h++;
	}
	printf("\n\n");
	printf("h-index: %i", h);
	printf("\n\n");
	printf("[");
	int cont = 0;
	for(int i = 0; i < n; i++){
		if(vet[i] >= h){
			cont++;
			printf(" %i", vet[i]);
		}
	}
	printf(" ]");
	printf("\n\n");
	printf("Existem %i artigos com %i ou mais citações.", cont, h);
}
