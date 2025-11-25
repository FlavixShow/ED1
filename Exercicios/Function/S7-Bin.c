#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int bits_um(int n){
	int cont = 0;
	while(n){
		if(n % 2){
			cont++;
		}
		n = n/2;
	}
	return cont;
}

int pot(int x, int n){
	int resultado = x;
	for(int i = 0; i < n-1; i++){
		resultado = resultado*x;
	}
	if(!n)
		resultado = 1;
	return resultado;
}

int bin(int n){
	int cont = 0;
	int bin = 0;
	while(n){
		int um = 0;
		if(n % 2){
			um = 1;
		}
		n = n/2;
		bin += pot(10, cont)*um;
		cont++;
	}
	return bin;
}

int main(){
	srand(time(NULL));
	
	bin(10);
	
	int n, x;
	printf("Insira N: ");
	scanf(" %i", &n);
	printf("Insira X: ");
	scanf(" %i", &x);
	
	int num[n];
	
	for(int i = 0; i < n; i++){
		num[i] = rand() % (x+1);
		for(int j = 1; j <= i; j++){
				int temp = num[j];
				int k = j-1;
				
				while(k >= 0 && bits_um(temp) > bits_um(num[k])){
					num[k+1] = num[k];
					k--;
				}
				num[k+1] = temp;
		}
	}
	for(int i = 0; i < n; i++){
		printf("Decimal: %i, Binário: %i\n", num[i], bin(num[i]));
	}
}
