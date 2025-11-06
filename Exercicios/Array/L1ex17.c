#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

int main(){
	
	int n, cont = 0;
	
	scanf(" %i", &n);
	
	for(int i = n; i > 0; i--){
		cont = 0;
		for(int j = 1; j <= i; j++){
			if(!(i % j))
				cont++;
		}
		if(cont == 2){
			printf("Primo anterior: %i", i);
			break;
		}
	}
	printf("\n\n");
	while(1){
		n++;
		cont = 0;
		for(int j = 1; j <= n; j++){
			if(!(n % j))
				cont++;
		}
		if(cont == 2){
			printf("Primo posterior: %i", n);
			break;
		}
	}
}
