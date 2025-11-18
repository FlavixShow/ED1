#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef	struct{
	char rua[100];
	int numero;
	char bairro[100];
	char cidade[100];
}Endereco;

typedef	struct{
	char nome[100];
	char cpf[12];
	int idade;
	float altura,peso;
	Endereco residencia;
}Pessoa;

//FAÇA UM PROGRAMA QUE LEIA OS DADOS DE ATÉ 10 PESSOAS
//FINALIZE COM O NOME "EXIT".
//APÓS A FASE DE CADASTRO, REALIZE A IMPRESSAO
//DE TODAS AS PESSOAS CADASTRADAS ORDENADAS PELO NOME.

int main(){
	Pessoa pessoas[10];
	int cont = 0;
	
	for(int i = 0; i < 10; i++){
		printf("<<<Dados pessoais da %iº pessoa>>>\n\n", i+1);
		
		printf("Nome ('exit' para sair): ");
		scanf(" %[^\n]s", pessoas[i].nome);
		if(!strcmp(pessoas[i].nome, "exit")){
			system("clear");
			break;		
		}
		cont++;
		printf("CPF: ");
		scanf(" %[^\n]s", pessoas[i].cpf);
		printf("Idade: ");
		scanf(" %i", &pessoas[i].idade);
		printf("Altura: ");
		scanf(" %f", &pessoas[i].altura);
		printf("Peso: ");
		scanf(" %f", &pessoas[i].peso);
		printf("\n");
		printf("<Endereço da %iº pessoa>\n\n", i+1);
		
		printf("Rua: ");
		scanf(" %[^\n]s", pessoas[i].residencia.rua);
		printf("Número: ");
		scanf(" %i", &pessoas[i].residencia.numero);
		printf("Bairro: ");
		scanf(" %[^\n]s", pessoas[i].residencia.bairro);
		printf("Cidade: ");
		scanf(" %[^\n]s", pessoas[i].residencia.cidade);
		
		system("clear");
	}
	
	for(int i = 1; i < cont; i++){
		int j = i - 1;
		Pessoa temp = pessoas[i];
		
		while(j >= 0 && strcmp(temp.nome, pessoas[j].nome) < 0){
			pessoas[j + 1] = pessoas[j];
			j--;
		}
		
		pessoas[j + 1] = temp;
	}
	
	for(int i = 0; i < cont; i++){
		printf("Dados pessoais - Nome: %s, CPF: %s, Idade: %i, Altura: %.2f, Peso: %.2f\n", pessoas[i].nome, pessoas[i].cpf, pessoas[i].idade, pessoas[i].altura, pessoas[i].peso);
		printf("Endereço - Rua: %s, Número: %i, Bairro: %s, Cidade: %s", pessoas[i].residencia.rua, pessoas[i].residencia.numero, pessoas[i].residencia.bairro, pessoas[i].residencia.cidade);
		printf("\n\n");
	}	
}
