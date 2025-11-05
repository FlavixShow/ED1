#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//O jeito certo//
	
	int tamVet;
	do{
		printf("Insira o tamanho do vetor: ");
		scanf("%i", &tamVet);
	}while(tamVet%4);
	
	int vet[tamVet];
	
	//define os valores e imprime o vetor normal;
	for(int i = 0; i < tamVet; i++){
		vet[i] = 1 + rand() % 20;
		printf("%02i ", vet[i]);
		if(!((i+1)%10))
			printf("| ");
	}
	printf("\n\n");
	
	//imprime o vetor com as metades trocadas;
	for(int i = 0; i < tamVet/2; i++){
		int troca = vet[i];
		vet[i] = vet[i + tamVet/2];
		vet[i + tamVet/2] = troca;
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
			int troca = vet[j+tamVet/2*i];
			vet[j+tamVet/2*i] = vet[j+tamVet/2*i + tamVet/4];
			vet[(j+20*i) + tamVet/4] = troca;
		}
	}
	for(int i = 0; i < tamVet; i++){
		printf("%02i ", vet[i]);
		if(!((i+1)%10))
			printf("| ");
	}
}
