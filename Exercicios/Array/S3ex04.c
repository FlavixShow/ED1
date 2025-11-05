#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int sort[25] = {0};
	int num, igual;
	
	srand(time(NULL));
	
	printf("Números sorteados: ");
	for(int i = 0; i < 25; i++){
		do{
			num = 1 + rand() % 25;
			for(int j = 0; j < 25; j++){
				if(sort[j] == num){
					igual = 1;
					break;
				}
				igual = 0;
			}
		}while(igual);
		
		sort[i] = num;
		if(i < 15){
			printf("%02i ", sort[i]);
			continue;
		}
		if(i == 15)
			printf("\nNúmeros não sorteados: ");
			
		printf("%02i ", sort[i]);
	}
}
