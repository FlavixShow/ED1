#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

int main(){
	srand(10);
	
	int x, y, cont = 0, repete = 0;

	printf("Digite X e Y: ");
	scanf(" %i %i", &x, &y);

	int vetX[x], vetY[y];
	
	do{
		int num = rand() % (x+y+1);
		repete = 0;
		//printf(" n-%i", num);
		for(int i = 0; i < x; i++){
			if(num == vetX[i]){
				repete = 1;
				break;
			}
		}
		if(!repete){
			vetX[cont] = num;
			cont++;
			//printf(" nr-%i", num);
		}
	}while(cont < x);
	//printf("\n\n");
	cont = 0;
	do{
		int num = rand() % (x+y+1);
		repete = 0;
		//printf(" n-%i", num);
		for(int i = 0; i < y; i++){
			if(num == vetY[i]){
				repete = 1;
				break;
			}
		}
		if(!repete){
			vetY[cont] = num;
			//printf(" nr-%i", num);
			cont++;
		}
	}while(cont < y);
	printf("X: ");
	for(int i = 0; i < x; i++)
		printf(" %i", vetX[i]);
	
	printf("\n\n");
	printf("Y: ");
	for(int i = 0; i < y; i++)
		printf(" %i", vetY[i]); 

	printf("\n\n");
	printf("Exclusivos de X: ");
	for(int i = 0; i < x; i++){
		int igual = 0;
		for(int j = 0; j < y; j++){
			if(vetX[i] == vetY[j]){
				igual = 1;
				break;
			}
		}
		if(igual)
			continue;
		printf(" %i", vetX[i]);
		
	}
	printf("\n\n");
	printf("Exclusivos de Y: ");
	for(int i = 0; i < y; i++){
		int igual = 0;
		for(int j = 0; j < x; j++){
			if(vetY[i] == vetX[j]){
				igual = 1;
				break;
			}
		}
		if(igual)
			continue;
		printf(" %i", vetY[i]);
		
	}
	printf("\n\n");
	printf("Tem em ambos: ");
	for(int i = 0; i < x; i++){
		for(int j = 0; j < y; j++){
			if(vetX[i] == vetY[j]){
				printf(" %i", vetX[i]);
				break;
			}
		}
	}
}
