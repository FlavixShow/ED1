#include <stdlib.h>
#include <stdio.h>

int potencia(int base, int exp){
	int resultado = base;
	for(int i = 0; i < exp-1; i++){
		resultado = resultado*base;
	}
	return resultado;
}


int main(){
	
	int x, n;
	printf("Base: ");
	scanf(" %i", &x);
	printf("Expoente: ");
	scanf(" %i", &n);
	printf("Resultado: %i", potencia(x, n));	
}
