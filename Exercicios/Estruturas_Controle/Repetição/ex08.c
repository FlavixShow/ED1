#include <stdio.h>

int main(){

	int cont = 5;
	int con = 0;
	
	for (int i = 0; i < 8; i++){
		if(i < 5){
			for (int k = 0; k < cont; k++){
					printf(" ");
			}
			
			for (int j = 0; j < i; j++){
				printf("* ");
			}
		}else{
			for(int k = 0; k < con+2; k++){
				printf(" ");
			}
			for(int j = 3; j > con; j--){
				printf("* ");
			}
		}
		
		printf("\n");
		cont--;
		if(i > 4){
			con++;
		}
	}
}
