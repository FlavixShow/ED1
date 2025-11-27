#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INT " %i"
#define STR " %[^\n]s"
#define FLT " %f"


typedef struct{
	int id;
	char nome[100];
	int idade;
	float altura;
}Pessoa;

//função input
void input(char tipo[], char text[],void* dado){
	printf("Insira %s", text);
	scanf(tipo, dado);
}

void invalido(){
	printf("Inválido. Pessione ENTER...");
	while(getchar() != '\n');
	getchar();
	system("clear");
}

int interface(){
	int esc;
	do{
		printf("1 - Cadastrar pessoa\n");
		printf("2 - Ordenar pessoas\n");
		printf("3 - Listar pessoas\n");
		printf("0 - Encerrar programa\n");
		input(INT, "escolha: ", &esc);
	
		if(esc < 0 || esc > 3)
			invalido();
		
		system("clear");
	}while(esc < 0 || esc > 3);
	system("clear");
	return esc;
}

//com ponteiro
void cadastro(Pessoa* pessoa, int* cont){
	*cont += 1;
	pessoa->id = *cont;
	input(STR, "nome: ", pessoa->nome);
	input(INT, "idade: ", &pessoa->idade);
	input(FLT, "altura: ", &pessoa->altura);
	printf("\n");
}

//inverte a proposição caso a ordem seja decrescente
int inverte(int a, int b){
	if(b){
		if(a)
			return 0;
		return 1;
	}
	return a;
	
}

void ordena(Pessoa* pessoas, int cont){
	int tipo;
	int ordem;
	
	do{
		printf("Ordernar por\n1 - Id\n2 - Nome\n3 - Idade\n4 - Altura\n");
		input(INT, "escolha: ", &tipo);
		if(tipo < 1 || tipo > 4)
			invalido();
		
		system("clear");
	}while(tipo < 1 || tipo > 4);
	
	do{
		printf("Ordem\n1 - Crescente\n2 - Decrescente\n");
		input(INT, "escolha: ", &ordem);
		ordem--;
		if(ordem != 0 && ordem != 1)
			invalido();
		
		system("clear");
	}while(ordem != 0 && ordem != 1);
	
	for(int i = 1; i < cont; i++){
		Pessoa temp = pessoas[i];
		int j = i-1;
		switch(tipo){
			case 1: while(j >= 0 && inverte((temp.id < pessoas[j].id), ordem)){
						pessoas[j+1] = pessoas[j];
						j--;
					};
					break;
			case 2: while(j >= 0 && inverte(strcmp(temp.nome, pessoas[j].nome) < 0, ordem)){
						pessoas[j+1] = pessoas[j];
						j--;
					};
					break;
			case 3: while(j >= 0 && inverte(temp.idade < pessoas[j].idade, ordem)){
						pessoas[j+1] = pessoas[j];
						j--;
					};
					break;
			case 4: while(j >= 0 && inverte(temp.altura < pessoas[j].altura, ordem)){
						pessoas[j+1] = pessoas[j];
						j--;
					};
					break;
		}
		pessoas[j+1] = temp;
	}
	system("clear");
}

//sem ponteiro
void lista(Pessoa pessoas[], int cont){
	for(int i = 0; i < cont; i++){
		printf("Id: %i\n", pessoas[i].id);
		printf("Nome: %s\n", pessoas[i].nome);
		printf("Idade: %i\n", pessoas[i].idade);
		printf("Altura: %.2f\n", pessoas[i].altura);
		printf("\n");
	}
}

int main(){
	Pessoa pessoas[100];
	int cont = 0;
	while(1){
		switch(interface()){
			case 0: printf("FIM DO PROGRAMA"); return 0;
				break;
			case 1: cadastro(&pessoas[cont], &cont);
				break;
			case 2: ordena(pessoas, cont);
				break;
			case 3: lista(pessoas, cont);
				break;
		}
	}
	return 0;
}
