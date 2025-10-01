#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float custo;
	int x, y;
	
	printf("Valor de custo: ");
	scanf("%f", &custo);
	printf("Porcentagem de imposto: ");
	scanf("%i", &x);
	printf("Taxa do distribuidor: ");
	scanf("%i", &y);
	
	printf("Valor final do produto: %.2f", custo * (1 + (float) x/100 + (float) y/100));
}
