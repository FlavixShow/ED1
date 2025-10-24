#include <stdio.h>
#include <stdlib.h>

int main(){

	char c;
	printf("Insira um caractere de a-z: ");
	scanf("%c", &c);
	
	printf("%c -> %c", c, c-32);

}

