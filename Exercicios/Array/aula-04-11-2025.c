#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

#define SIMULACOES 100000

int main(){
	int n;
	
	do{
		srand(time(NULL));	
		printf(" ");
		scanf(" %i", &n);
		
		if(n <= 0)
			break;
		
		int vetor[n];
		
		
		int repete = 0, nRep = 0;
		for(int i = 0; i < SIMULACOES; i++){
			for(int j = 0; j < n; j++){
				vetor[j] = rand() % (2*n + 1);
				printf(" %i", vetor[j]);
			}
			printf("\n\n");
			repete = 0;
			for(int j = 0; j < n; j++){
				for(int k = (j+1); k < n; k++){
					if(vetor[j] == vetor[k]){
						repete = 1;
						break;
					}
				}
				if(repete){
					break;
				}
			}
			if(!repete)
				nRep++;
		}
		printf(" %i", nRep);
		printf(" %.1f%c", (float) nRep*100/SIMULACOES, '%');
		printf("\n\n");
	}while(1);
	printf(" FIM");
	
	//Quanto maior n menos sequências não repetitivas, ou seja, a porcentagem diminue;
	//Quanto menor n mais sequências não repetitivas, ou seja, a porcentagem aumenta;
	
	//com nenhuma casa decimal o mínimo em que a porcentagem atinge 100% é 1
	
	//com nenhuma casa decimal o mínimo em que a porcentagem zera é 22
	//com uma casa decimal o mínimo em que a porcentagem zera é 27
	//com duas casas decimais o mínimo em que a porcentagem zera é 33
}
