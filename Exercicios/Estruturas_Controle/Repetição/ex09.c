#include <stdio.h>

int main(){
	
	int cont = 0, cont2 = 2;
	
	for(int i = 0; i < 7; i++){
		if(i < 4){
			for(int k = 0; k < cont; k++){
				printf(" ");
			}
			for(int j = 4; j > i; j--){
				printf("* ");
			}
			cont++;
		}else{
			for(int k = 0; k < cont2; k++){
				printf(" ");
			}
			for(int j = 0; j < i-2; j++){
				printf("* ");
			}
			cont2--;
		}
		printf("\n");
	
	}
}
