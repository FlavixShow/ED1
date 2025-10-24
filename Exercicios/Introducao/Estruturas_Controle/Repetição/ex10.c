#include <stdio.h>

int main(){
	
	for(int i = 0; i < 6; i++){
		if(i == 0 || i == 5){
			for(int j = 0; j < 5; j++){
				printf("* ");
			}
		}else{
			for(int k = 0; k < 9; k++){
				if(k == 0 || k == 8){
					printf("*");
				}else{
					printf(" ");
				}
			}
		}
		printf("\n");
	}

}
