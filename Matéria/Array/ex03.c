#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int vet[40];
	int tamVet = 40;
	
	//define os valores e imprime o vetor normal;
	for(int i = 0; i < tamVet; i++){
		//vet[i] = rand() % 2;
		vet[i] = i; //para facilitar o teste
		printf("%02i ", vet[i]);
		if(!((i+1)%10))
			printf("| ");
	}
	printf("\n\n");
	
	//imprime o vetor com as metades trocadas;
	for(int i = 0; i < tamVet/2; i++){
		vet[i] += vet[i + tamVet/2];
		vet[i + tamVet/2] = vet[i] - vet[i + tamVet/2];
		vet[i] -= vet[i + tamVet/2];
	}
	for(int i = 0; i < tamVet; i++){
		printf("%02i ", vet[i]);
		if(!((i+1)%10))
			printf("| ");
	}
	printf("\n\n");
	
	//imprime o vetor com as metades das metades trocadas;
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < tamVet/4; j++){
			vet[j+20*i] += vet[(j+20*i) + tamVet/4];
			vet[(j+20*i) + tamVet/4] = vet[j+20*i] - vet[(j+20*i) + tamVet/4];
			vet[j+20*i] -= vet[(j+20*i) + tamVet/4];
		}
	}
	for(int i = 0; i < tamVet; i++){
		printf("%02i ", vet[i]);
		if(!((i+1)%10))
			printf("| ");
	}
}
