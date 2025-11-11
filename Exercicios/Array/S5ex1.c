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
	
	int comp = 0, troca = 0;
	if(esc == 'a'){
		for(int i = n; i > 0; i--){
			//Bubble Sort
			for(int j = 0; j < i-1; j++){
				if(vet[j] > vet[j+1]){
					int temp = vet[j+1];
					vet[j+1] = vet[j];
					vet[j] = temp;
					troca++;
				}
				comp++;
			}
		}
	}else if(esc == 'b'){
		//Selection Sort
		for(int i = n; i > 0; i--){
			int maior = 0;
			for(int j = 1; j < i; j++){
				if(vet[j] > vet[maior]){
					maior = j;
				}
				comp++;
			}	
			int temp = vet[maior];
			vet[maior] = vet[i-1];
			vet[i-1] = temp;
			if(maior != i-1)
				troca++;
		}
	}else if(esc == 'c'){
		//Insertion Sort
		for(int i = 1; i < n; i++){
			int temp = vet[i];
			int j = i-1;
			while(j >= 0 && temp<vet[j]){
				vet[j+1] = vet[j];
				j--;
				comp++;
				troca++;
			}
			comp++;
			vet[j + 1] = temp;
			if(vet[i] != temp){
				troca++;
			}
			/*for(int j = i-1; j >= 0; j--){
				if(temp < vet[j]){
					vet[j+1] = vet[j];
					troca++;
					comp++;
					if(!j){
						vet[j] = temp;
						troca++;
					}
				}else{
					vet[j+1] = temp;
					if(temp < vet[i])
						troca++;
					comp++;
					break;
				}
			}8*/
			
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
