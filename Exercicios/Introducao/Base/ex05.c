#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char a, b;
	
	printf("Insira dois caracteres numéricos '0-9': ");
	scanf("%c %c", &a, &b);

	printf("%c x %c == %i", a, b, ('0' - a)*('0' - b));

}

