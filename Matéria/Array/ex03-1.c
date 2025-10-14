#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//utilizando 2 vetores
	int vet[40], vet2[40];
	int tamVet = 40;

	for(int i = 0; i < tamVet; i++){
		vet[i] = i;
		printf(" %02i ", vet[i]);
		if(!((i+1)%10))
			printf(" | ");
	}
	printf("\n\n");
	for(int i = 0; i < tamVet; i++){
		if(i < 20){
			vet2[i] = vet[i + 20];
			printf(" %02i ", vet2[i]);
			if(!((i+1)%10))
			printf(" | ");
			continue;
		}
		vet2[i] = vet[i - 20];
		printf(" %02i ", vet2[i]);
		if(!((i+1)%10))
			printf(" | ");

	}
	printf("\n\n");
	for(int j = 0; j < 2; j++){
		for(int i = 0; i < tamVet/2; i++){
			if(i < 10){
				vet[i+20*j] = vet2[(i+20*j) + 10];
				printf(" %02i ", vet[i+20*j]);
				if(!((i+1)%10))
				printf(" | ");
				continue;
			}
			vet[i+20*j] = vet2[(i+20*j - 10)];
			printf(" %02i ", vet[i+20*j]);
			if(!((i+1)%10))
			printf(" | ");
		}
	}
}
