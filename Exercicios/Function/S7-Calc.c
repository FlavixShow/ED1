#include <stdlib.h>
#include <stdio.h>


int interface(){
	int esc;
	do{
		printf("1-Soma\n2-Subtração\n3-Multiplicação\n4-Divisão\n5-Potência\nEscolha: ");
		scanf(" %i", &esc);
		if(esc < 1 || esc > 5){
			printf("Inválido. Pressione ENTER...");
			while(getchar() != '\n');
			getchar();
			system("clear");
			continue;
		}
		break;
	}while(1);
	return esc;
}

int soma(int x, int n){
	return x + n;
}

int sub(int x, int n){
	return x - n;
}

int mult(int x, int n){
	return x * n;
}

float divi(int x, int n){
	return x/n;
}

int pot(int x, int n){
	int resultado = x;
	for(int i = 0; i < n-1; i++){
		resultado = resultado*x;
	}
	return resultado;
}

int main(){
	int esc = interface();
	int x, n;
	printf("Com quais valores deseja trabalhar?\n1º: ");
	scanf(" %i", &x);
	printf("2º: ");
	scanf(" %i", &n);
	
	if(esc == 1){
		printf("Resultado: %i", soma(x, n));
	}else if(esc == 2){
		printf("Resultado: %i", sub(x, n));
	}else if(esc == 3){
		printf("Resultado: %i", mult(x, n));
	}else if(esc == 4){
		printf("Resultado: %f", divi(x, n));
	}else{
		printf("Resultado: %i", pot(x, n));
	}
}
