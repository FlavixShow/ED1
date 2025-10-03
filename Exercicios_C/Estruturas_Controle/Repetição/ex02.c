#include <stdio.h>

int main(){

	int cont = 5;
	
	for (int i = 0; i < 6; i++){
		for (int k = 0; k < cont; k++){
				printf("  ");
		}
		
		for (int j = 0; j < i; j++){
			printf("* ");
		}
		
		printf("\n");
		cont--;
	}
}
