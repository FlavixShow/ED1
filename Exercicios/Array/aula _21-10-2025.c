#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	/*
	leia o nome de N alunos
	e a quantidade de provas da disciplina
	
	preencha aleatoriamente a nota de cada prova
	de cada aluno. (as provas possuem mesma nota).
	
	ao final imprima: 
	a) quadro de notas (alunos e notas)
	b) Nota final de cada aluno na disciplina
	c) quem foi aprovado (soma >= 60)
	d) quem ficou de final (40 <= soma < 60)
	e) quem ficou acima da média.
	*/
	srand(time(NULL));
	
	int quantAlun, quantProv, soma = 0;
	
	printf("Quant. de alunos: ");
	scanf(" %i", &quantAlun);
	printf("Quant. de provas: ");
	scanf(" %i", &quantProv);
	
	char nomes[quantAlun][100];
	//mais um espaço para a soma
	int notas[quantAlun][quantProv + 1];

	for(int i = 0; i < quantAlun; i++){
		printf("Nome do %iº aluno: ", i+1);
		scanf(" %[^\n]s", nomes[i]);
	}
	
	for(int i = 0; i < quantAlun; i++){
		notas[i][quantProv] = 0;
		for(int j = 0; j < quantProv; j++){
			notas[i][j] = 1 + rand() % (100/quantProv);
			soma += notas[i][j];
			notas[i][quantProv] += notas[i][j];
		}
	}
	system("clear");
	for(int i = 0; i < quantAlun; i++){
		printf("Aluno: %s|", nomes[i]);
		printf("\tNotas: ");
		for(int j = 0; j < quantProv + 1; j++){
			if(j == quantProv)
				printf(" Final: ");
			printf(" %02i|", notas[i][j]);
		}
		if(notas[i][quantProv] >= 60){
			printf(" Situação final: Aprovado");
			printf("\n\n");
			continue;
		}
		if(notas[i][quantProv] >= 40 && notas[i][quantProv] < 60){
			printf(" Situação final: Prova Final");
			printf("\n\n");
			continue;
		}
		if(notas[i][quantProv] < 40){
			printf(" Situação final: Reprovado");
			printf("\n\n");
		}
	}
	printf("Alunos acima da média [%i]:", soma/quantAlun);
	for(int i = 0; i < quantAlun; i++){
		if(notas[i][quantProv] > soma/quantAlun){
			printf(" %s|", nomes[i]);
		}
	}
}
