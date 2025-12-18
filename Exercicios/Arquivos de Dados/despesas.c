#include <stdlib.h>
#include <stdio.h>

#define STR " %[^\n]s"
#define INT " %i"
#define FLT " %f"
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

enum estado_quitacao{SIM, NAO};

typedef struct{
	int id;
	char descricao[100];
	float valor;	
	char dataVenc[15];
	int quitado;
}Despesa;

FILE* abrirArquivo(char nomeArq[]){
	FILE* arq = fopen(nomeArq, "rb+");
	if(!arq)
		arq = fopen(nomeArq, "wb+");
		
	if(!arq)
		printf("Log: Falha ao abrir arquivo.\n\n");
		
	return arq;
}

int interface(){
	int esc;
	do{
		printf("=CONTROLE DE DESPESAS=\n");
		printf("1 - Cadastrar\n");
		printf("2 - Listar\n");
		printf("3 - Quitar\n");
		printf("4 - Saldo de Despesas\n");
		printf("0 - Encerrar Programa\n");
		input(INT, "Escolha a Ação: ", &esc);
		if((esc < 0 || esc > 4) && esc != 99){
			alert("Ação Inválida.");
		}
		system("clear");
	}while((esc < 0 || esc > 4 )&& esc != 99);
	return esc;
}

void cadastrar(FILE* arq){
	Despesa desp;
	fseek(arq,0,SEEK_END);
	desp.id = ftell(arq)/sizeof(Despesa) + 1;
	printf("=CADASTRAR DESPESA=\n");
	input(STR, "Descrição: ", desp.descricao);
	do{
		input(FLT, "Valor: ", &desp.valor);
		if(desp.valor == 0)
			printf("Valor inválido.");
	}while(desp.valor == 0);
	input(STR, "Data de Vencimento: ", desp.dataVenc);
	desp.quitado = NAO;
	
	fseek(arq, 0, SEEK_END);
	if(fwrite(&desp, sizeof(Despesa), 1, arq)){
		fflush(arq);
		alert("Despesa Cadastrada.");
		return;
	}
	alert("Despesa Não Cadastrada, Tente Novamente.");
}

void listar(FILE* arq){
	Despesa desp;
	fseek(arq, 0, SEEK_SET);
	while(fread(&desp, sizeof(Despesa), 1, arq)){
		printf("%iª Despesa\nDescrição: %s\nValor: %.2f\nData de Vencimento: %s\nQuitada: %s\n\n", desp.id, desp.descricao, desp.valor, desp.dataVenc, desp.quitado == SIM ? "Sim" : "Não");
	}
}

int verifica(FILE* arq, int esc){
	fseek(arq,0,SEEK_SET);
	Despesa desp;
	while(fread(&desp, sizeof(Despesa), 1, arq)){
		if(desp.id == esc){
			if(desp.quitado == SIM)
				return 1;
			return 2;
		}
	}
	return 0;
}

void quitar(FILE* arq){

	int esc;
	do{
		printf("=QUITAR DIVIDA=\n");
		input(INT, "Qual a despesa quitada? (0 - Cancelar)", &esc);
		if(esc < 0){
			alert("Entrada Inválida.");
			continue;
		}
		if(!esc)
			break;
		switch(verifica(arq, esc)){
			case 0: alert("Despesa Inexistente."); continue;
			break;
			case 1: alert("Despesa Já Quitada."); continue;
			break;
			case 2: alert("Despesa Marcada como Quitada.");
			break;
		}
		printf("\n");
		break;
	}while(1);
	int quit = SIM;
	if(esc){
		fseek(arq, esc*sizeof(Despesa)-sizeof(int),SEEK_SET);
		fwrite(&quit, sizeof(int), 1, arq);
	}
	system("clear");
}

void aindaQuitar(FILE* arq){
	Despesa desp;
	fseek(arq,0,SEEK_SET);
	float totalDespesas = 0, totalNaoPagas = 0;
	printf("=RELAÇÃO DAS DESPESAS=\n\n");
	while(fread(&desp, sizeof(Despesa), 1, arq)){
		if(desp.quitado == NAO){
			printf("%iª Despesa\nDescrição: %s\nValor: %.2f\nData de Vencimento: %s\nQuitada: %s\n\n", desp.id, desp.descricao, desp.valor, desp.dataVenc, desp.quitado == SIM ? "Sim" : "Não");
			totalNaoPagas += desp.valor;
		}
		totalDespesas += desp.valor;
	}
	printf("Total: %.2f\n\n", totalDespesas);
	printf("Total a Pagar: %.2f\n\n", totalNaoPagas);
	printf("Total Pago: %.2f\n\n", totalDespesas - totalNaoPagas);
}

int main(){
	
	FILE* arquivo = NULL;
	arquivo = abrirArquivo("despesas-dados");
	
	do{
		switch(interface()){
			case 1: cadastrar(arquivo);
			break;
			case 2: listar(arquivo);
			break;
			case 3: quitar(arquivo);
			break;
			case 4: aindaQuitar(arquivo);
			break;
			case 0: fclose(arquivo); printf("FIM DO PROGRAMA"); return 0;
			break;
			case 99: arquivo = fopen("despesas-dados", "wb+"); //resetar arquivo
			break;
		}
		
	}while(1);
	
}
