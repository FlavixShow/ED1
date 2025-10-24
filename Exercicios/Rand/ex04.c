#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int x, num, cont = 0;
	
	printf("Digite X: ");
	scanf("%i", &x);
	
	srand(time(NULL));
	do{
		num = rand() % (x + 1);
		
		for(int i = 0; i < x; i++){
			if(num % (i+1) == 0){
				cont++;
			}
		}
		if(cont <= 2){
			printf("Número primo: %i", num);
			break;
		}
		printf("%i\n", num);
		cont = 0;
	}while(1);
}
