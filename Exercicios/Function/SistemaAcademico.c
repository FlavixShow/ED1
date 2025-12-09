#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//REVISÃO FINAL PARA A PROVA #02
//---- SISTEMA ACADÊMICO -------

//1 - CADASTRAR ALUNO
	//MATRICULA(I: AUTOINCREMENTO) 
	//NOME(S)

//2 - CADASTRAR DISCIPLINA
	//CODIGO(I: AUTOINCREMENTO)
	//NOME(S)
	//PERIODO(I)
	//MATRICULAS(I[50])

//3 - MATRICULAR ALUNO
	//MATRICULAR UM ALUNO EM UMA DETERMINADA DISCIPLINA
	//BUSCAR DISCIPLINA E ALUNO ATRAVÉS DE NOMES.
	//SOMENTE 1 MATRICULA POR ALUNO/DISCIPLINA (VALIDAR!)

//4 - CANCELAR MATRICULA (EXCLUIR MATRICULA)
	//EXCLUIR A MATRICULA DE UM DETERMINADO ALUNO 
	//EM UMA DISCIPLINA.

//5 - FAZER CHAMADA
	//SOLICITAR NOME DE DISCIPLINA.
	//LISTAR (EM ORDEM ALFABETICA) OS NOMES DOS ALUNOS
	//MATRICULADOS.
	//NÃO É NECESSÁRIO SALVAR DADOS. APENAS LISTAGEM.

//6 - HISTORICO DO ALUNO
	//SOLICITAR NOME DO ALUNO.
	//LISTAR TODAS AS DISCIPLINAS MATRICULADAS
	//(EM ORDEM DE PERIODO)
	//NÃO É NECESSÁRIO SALVAR DADOS. APENAS LISTAGEM.

typedef struct{
	int matricula;
	char nome[100];
}Aluno;

typedef struct{
	int codigo;
	char nome[100];
	int periodo;
	int alunos[50]; //recebe número de matrícula do aluno
	int contAlunos;
}Disciplina;

typedef struct{
	Aluno alunos[100];
	int cont;
}DsAlunos;

typedef struct{
	Disciplina disciplinas[100];
	int cont;
}DsDisc;

#define STR " %[^\n]s"
#define INT " %i"
void input(char tipo[], char texto[], void* variavel){
	printf("%s", texto);
	scanf(tipo, variavel);
}

void alert(char texto[]){
	printf("%s Pressione ENTER...", texto);
	while(getchar() != '\n');
	getchar();
	system("clear");
}

DsAlunos criarDsAlunos(){
	DsAlunos alunos;
	alunos.cont = 0;
	return alunos;
}

DsDisc criarDsDisc(){
	DsDisc disc;
	disc.cont = 0;
	return disc;
}

int interface(){
	int esc;
	do{
		printf("=======SISTEMA ACADÊMICO=======\n");
		printf("1 - Cadastrar Aluno\n");
		printf("2 - Cadastrar Disciplina\n");
		printf("3 - Matricular Aluno\n");
		printf("4 - Cancelar Matrícula\n");
		printf("5 - Fazer Chamada\n");
		printf("6 - Histórico do Aluno\n");
		printf("0 - Encerrar Programa\n");
		input(INT, "Escolha a ação: ", &esc);
		if(esc < 0 || esc > 6)
			alert("Ação inválida.");
			
		system("clear");
	}while(esc < 0 || esc > 6);
	return esc;
}

void cadastrarAluno(DsAlunos* dsAlunos){
	printf("=CADASTRAR ALUNO=\n");
	dsAlunos->alunos[dsAlunos->cont].matricula = dsAlunos->cont + 1;
	input(STR, "Digite o nome do aluno: ", dsAlunos->alunos[dsAlunos->cont].nome);
	dsAlunos->cont += 1;
	alert("Aluno cadastrado.");
}
void cadastrarDisc(DsDisc* dsDisc){
	printf("=CADASTRAR DISCIPLINA=\n");
	dsDisc->disciplinas[dsDisc->cont].codigo = dsDisc->cont + 1;
	input(STR, "Digite o nome da matéria: ", dsDisc->disciplinas[dsDisc->cont].nome);
	int per;
	do{
		input(INT, "Digite o período: ", &per);
		if(per < 1)
			printf("Inválido.");
	}while(per < 1);
	dsDisc->disciplinas[dsDisc->cont].periodo = per;
	dsDisc->disciplinas[dsDisc->cont].contAlunos = 0;
	dsDisc->cont += 1;
	alert("Disciplina cadastrada.");
}

int verificaAluno(char nome[], DsAlunos dsAlunos){
	for(int i = 0; i < dsAlunos.cont; i++){
		if(!strcmp(nome, dsAlunos.alunos[i].nome)){
			return i;
		}
	}
	return -1;
}
int verificaDisc(char nome[], DsDisc dsDisc){
	for(int i = 0; i < dsDisc.cont; i++){
		if(!strcmp(nome, dsDisc.disciplinas[i].nome)){
			return i;
		}
	}
	return -1;
}

void matricularAluno(DsAlunos* dsAlunos, DsDisc* dsDisc){
	printf("=MATRICULAR ALUNO EM DISCIPLINA=\n");
	char aluno[100];
	input(STR, "Nome do aluno: ", &aluno);
	int idxA = verificaAluno(aluno, *dsAlunos);
	if(idxA == -1){
		alert("Aluno inexistente.");
		return;
	}
	char disciplina[100];
	input(STR, "Disciplina: ", &disciplina);
	int idxD = verificaDisc(disciplina, *dsDisc);
	if(idxD == -1){
		alert("Disciplina inexistente.");
		return;
	}
	
	for(int i = 0; i < dsDisc->disciplinas[idxD].contAlunos; i++)
		if(dsAlunos->alunos[idxA].matricula == dsDisc->disciplinas[idxD].alunos[i]){
			alert("Aluno já matriculado.");
			return;
		}
	
	dsDisc->disciplinas[idxD].alunos[dsDisc->disciplinas[idxD].contAlunos] = dsAlunos->alunos[idxA].matricula;
	dsDisc->disciplinas[idxD].contAlunos += 1;
	alert("Aluno matriculado");
}

void cancelarMatricula(DsAlunos* dsAlunos, DsDisc* dsDisc){
	printf("=CANCELAR MATRICULA DE ALUNO EM DISCIPLINA=\n");
	char aluno[100];
	input(STR, "Nome do aluno: ", &aluno);
	int idxA = verificaAluno(aluno, *dsAlunos);
	if(idxA == -1){
		alert("Aluno inexistente.");
		return;
	}
	char disciplina[100];
	input(STR, "Disciplina: ", &disciplina);
	int idxD = verificaDisc(disciplina, *dsDisc);
	if(idxD == -1){
		alert("Disciplina inexistente.");
		return;
	}
	
	for(int i = 0; i < dsDisc->disciplinas[idxD].contAlunos; i++){
		if(dsAlunos->alunos[idxA].matricula == dsDisc->disciplinas[idxD].alunos[i]){
			for(int j = i; j < dsDisc->disciplinas[idxD].contAlunos - 1; j++){
				dsDisc->disciplinas[idxD].alunos[j] = dsDisc->disciplinas[idxD].alunos[j+1];
			}
		}
	}
	dsDisc->disciplinas[idxD].contAlunos -= 1;
	alert("Aluno Desmatriculado.");
}

void ordenaLista(Aluno* lista, int cont){	
	for(int i = 1; i < cont; i++){
		Aluno temp = lista[i];
		int j = i - 1;
		while(j >= 0 && strcmp(temp.nome, lista[j].nome) < 0){
			lista[j + 1] = lista[j];
			j--;
		}
		lista[j + 1] = temp;
	}

}

void ordenaListaMat(Disciplina* lista, int cont){	
	for(int i = 1; i < cont; i++){
		Disciplina temp = lista[i];
		int j = i - 1;
		while(j >= 0 && temp.periodo < lista[j].periodo){
			lista[j + 1] = lista[j];
			j--;
		}
		lista[j + 1] = temp;
	}
}

void chamada(DsAlunos dsAlunos, DsDisc dsDisc){
	printf("=CHAMADA=\n");
	char disc[100];
	input(STR, "Disciplina: ", &disc);
	int idxD = verificaDisc(disc, dsDisc);
	if(idxD == -1){
		alert("Disciplina inexistente.");
		return;
	}
	
	system("clear");
	printf("=CHAMADA=\n");
	Aluno lista[dsDisc.disciplinas[idxD].contAlunos];
	for(int i = 0; i < dsDisc.disciplinas[idxD].contAlunos; i++){
		for(int j = 0; j < dsAlunos.cont; j++){
			if(dsDisc.disciplinas[idxD].alunos[i] == dsAlunos.alunos[j].matricula)
				lista[i] = dsAlunos.alunos[j];
		}
	}
	ordenaLista(lista, dsDisc.disciplinas[idxD].contAlunos);
	
	printf("Nº Mat - Nome\n");
	for(int i = 0; i < dsDisc.disciplinas[idxD].contAlunos; i++){
		printf("%i - %s\n", lista[i].matricula, lista[i].nome);
	}
	alert("Listado.");
}

void historico(DsAlunos dsAlunos, DsDisc dsDisc){
	printf("=HISTÓRICO=\n");
	char nome[100];
	input(STR, "Nome do aluno: ", &nome);
	int idxA = verificaAluno(nome, dsAlunos);
	if(idxA == -1){
		alert("Aluno inexistente.");
		return;
	}
	system("clear");
	printf("=HISTÓRICO=\n");
	
	Disciplina lista[dsDisc.cont];
	int cont = 0;
	for(int i = 0; i < dsDisc.cont; i++){
		for(int j = 0; j < dsDisc.disciplinas[i].contAlunos; j++){
			if(dsAlunos.alunos[idxA].matricula == dsDisc.disciplinas[i].alunos[j]){
				lista[i] = dsDisc.disciplinas[i];
				cont++;
			}
		}
	}
	ordenaListaMat(lista, cont);
	
	printf("Período - Nome\n");
	for(int i = 0; i < cont; i++){
		printf("%i - %s\n", lista[i].periodo, lista[i].nome);
	}
	alert("Listado.");
}

int main(){
	DsAlunos dsAlunos = criarDsAlunos();
	DsDisc dsDisciplinas = criarDsDisc();
	
	do{
		switch(interface()){
			case 1: cadastrarAluno(&dsAlunos);
			break;
			case 2: cadastrarDisc(&dsDisciplinas);
			break;
			case 3: matricularAluno(&dsAlunos, &dsDisciplinas);
			break;
			case 4: cancelarMatricula(&dsAlunos, &dsDisciplinas);
			break;
			case 5: chamada(dsAlunos, dsDisciplinas);
			break;
			case 6: historico(dsAlunos, dsDisciplinas);
			break;
			case 0: printf("FIM DO PROGRAMA"); return 0;
			break;
		}
	}while(1);
}
