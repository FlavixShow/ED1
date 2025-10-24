#include <stdio.h>

int main(){
	int cont = 0;
	for(int i = 0; i < 5; i++){
		for(int k = 0; k < cont; k++){
			printf(" ");
		}
		for(int j = 0; j < 4; j++){
			printf("* ");
		}
		printf("\n");
		cont++;
	}
}
