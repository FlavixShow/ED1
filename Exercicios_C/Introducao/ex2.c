#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a, b, c;
	float media;
	
	printf("Digite três números: ");
	scanf("%d %d %d", &a, &b, &c);
	
	system("clear");
	media = (float)(a + b + c)/3;
	printf("Média: %.3f", media);
}

