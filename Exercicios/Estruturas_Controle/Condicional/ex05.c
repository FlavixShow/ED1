#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float n1, n2, n3, n4, n5, media, maior, menor;
	
	printf("Notas: ");
	scanf("%f %f %f %f %f", &n1, &n2, &n3, &n4, &n5);
	
	maior = menor = n1;
	
	//verifica o maior;
	if(n2 > maior){
		maior = n2;
	}
	if(n3 > maior){
		maior = n3;
	}
	if(n4 > maior){
		maior = n4;
	}
	if(n5 > maior){
		maior = n5;
	}
	
	//verifica o menor;
	if(n2 < menor){
		menor = n2;
	}
	if(n3 < menor){
		menor = n3;
	}
	if(n4 < menor){
		menor = n4;
	}
	if(n5 < menor){
		menor = n5;
	}
	
	media = (n1+n2+n3+n4+n5-maior-menor)/3;
	printf("Média: %.2f", media);
}
