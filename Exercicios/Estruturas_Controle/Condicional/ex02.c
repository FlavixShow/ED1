#include <stdio.h>
#include <stdlib.h>

int main(){
	
	float altura, peso, imc;

	printf("Altura em centímetros: ");
	scanf("%f", &altura);
	printf("Peso: ");
	scanf("%f", &peso);

	imc = peso / ((altura/100)*(altura/100));
	
	if(imc < 18.5){
		printf("Abaixo do peso.");
	}else if(imc >= 18.5 && imc < 25){
		printf("Peso normal.");
	}else if(imc >= 25 && imc < 30){
		printf("Acima do peso.");
	}else{
		printf("Obeso.");
	}
}

