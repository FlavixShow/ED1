#include <stdio.h>

int main(){
	int cont = 0;
	for (int i = 5; i > 0; i--){
		for (int j = 0; j < i; j++){
			printf("* ");
		}
		printf("\n");
		cont++;
	}
	
}
