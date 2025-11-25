#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int primo(int x){
	while(1){
		int cont = 0;
		for(int i = x; i > 0; i--){
			if(!(x % i)){
				cont++;
			}
		}
		if(cont == 2)
			return x;
		x++;
	}
}

int main(){
	
	srand(time(NULL));
	
	int n;
	
	printf("Valor de N: ");
	scanf(" %i", &n);
	
	int num[n];
	
	for(int i = 0; i < n; i++){
		num[i] = 1 + rand() % 100;
		printf("Primo próximo ou igual a %i: %i\n", num[i], primo(num[i]));
	}

}
