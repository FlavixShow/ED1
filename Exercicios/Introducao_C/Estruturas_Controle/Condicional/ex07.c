#include <stdio.h>
#include <math.h>

int main(){
	
	int delta, a, b, c;
	
	printf("Valores a, b e c: ");
	scanf("%i %i %i", &a, &b, &c);	
	
	delta = (b*b) - 4*a*c;
	if(delta < 0){
		printf("Não há raizes reais.");
	}else{
		printf("X1 == %.2f\n", (-b + sqrt(delta))/(2*a));
		printf("X2 == %.2f", (-b - sqrt(delta))/(2*a));
	}
}
