#include <stdio.h>
#include <stdlib.h>

int main(){

	unsigned int a, b, c;
	
	printf("Tamanho das retas: ");
	scanf("%u %u %u", &a, &b, &c);
	
	printf((a + b > c && a + c > b && b + c > a)? "Triângulo." : "Não é triângulo.");
	
}
