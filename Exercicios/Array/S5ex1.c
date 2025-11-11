#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

int main(){
	srand(time(NULL));
	
	int n;
	
	printf("Número de elementos: ");
	scanf(" %i" , &n);
	
	if(n < 1){
		printf("Inválido.");
		return 0;
	}
	
	int vet[n];
	
	printf("[");
	for(int i = 0; i < n; i++){
		vet[i] = rand() % 100;
		if(i == n-1){
			printf("%i", vet[i]);
			continue;
		}
		printf("%i, ", vet[i]);
	}
	printf("]");
	printf("\n\n");
	
	char esc;
	printf("Escolha o método de ordenação\n(a) - Bubble Sort\n(b) - Selection Sort\n(c) - Insertion Sort\n");
	scanf(" %c", &esc);
	
	int cont = n, comp = 0, troca = 0;
	if(esc == 'a'){
		while(cont){
			//Bubble Sort
			for(int i = 0; i < cont-1; i++){
				if(vet[i] > vet[i+1]){
					int temp = vet[i+1];
					vet[i+1] = vet[i];
					vet[i] = temp;
					troca++;
				}
				comp++;
			}
			cont--;
		}
	}else if(esc == 'b'){
		//Selection Sort
		while(cont){
			int maior = 0;
			for(int i = 1; i < cont; i++){
				if(vet[i] > vet[maior]){
					maior = i;
				}
				comp++;
			}
			cont--;	
			int temp = vet[maior];
			vet[maior] = vet[cont];
			vet[cont] = temp;
			if(maior != cont)
				troca++;
			
		}
	}else if(esc == 'c'){
		//Insertion Sort
		for(int i = 0; i < n; i++){
			int temp = vet[i];
			for(int j = i-1; j >= 0; j--){
				if(temp < vet[j]){
					vet[j+1] = vet[j];
					troca++;
					comp++;
					if(!j){
						vet[0] = temp;
						troca++;
					}
				}else{
					vet[j+1] = temp;
					if(temp < vet[i])
						troca++;
					comp++;
					break;
				}
			}
		}
	}else{
		printf("Inválido.");
		return 0;
	}
	printf("\n\n");
	printf("[");
	for(int i = 0; i < n; i++){
		if(i == n-1){
			printf("%i", vet[i]);
			continue;
		}
		printf("%i, ", vet[i]);
	}
	printf("]");
	printf("\n\n");
	printf("Número de trocas: %i\nNúmero de comparações: %i", troca, comp);
	
	return 0;
}
