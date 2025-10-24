#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float n1, n2, n3, media, maior;
	
	printf("Notas: ");
	scanf("%f %f %f", &n1, &n2, &n3);
	
	maior = n1;
	media = (n1*4 + 3*(n2 + n3))/10;
	
	if (n2 > maior){
		media = (n2*4 + 3*(n1 + n3))/10;
		maior = n2;
	}
	
	if (n3 > maior)
		media = (n3*4 + 3*(n1 + n2))/10;
	
	printf("Média ponderada: %.2f", media);
}
