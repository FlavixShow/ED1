#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

typedef struct{
	char nome[100], cpf[12];
	int idade;
	float peso, altura;
}Pessoa;

int main(){

	Pessoa p;
	
	printf("Nome: ");
	scanf(" %[^\n]s", p.nome);
	printf("CPF: ");
	scanf(" %[^\n]s", p.cpf);
	printf("Idade: ");
	scanf(" %i", &p.idade);
	printf("Peso: ");
	scanf(" %f", &p.peso);
	printf("Altura: ");
	scanf(" %f", &p.altura);
	
	printf("Nome: %s, CPF: %s, Idade: %i, Peso: %.2f, Altura: %.2f", p.nome, p.cpf, p.idade, p.peso, p.altura);
	
}
