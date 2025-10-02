#include <stdio.h>
#include <stdlib.h>

int main(){

	int n1, n2;
	
	printf("Números: ");
	scanf("%i %i", &n1, &n2);
	
	printf((n1 % n2 == 0)||(n2 % n1 == 0)? "Multiplos." : "Não multiplos.");
	
}
