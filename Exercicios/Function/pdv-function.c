#include <stdio.h>
#include <stdlib.h>

//sistema pdv (ponto de venda) "com funções"

/* REQUISITOS DA APLICAÇÃO

1- DEVE SER POSSÍVEL CADASTRAR ATÉ 100 PRODUTOS.
2- TODO PRODUTO DEVE TER CODIGO ÚNICO (GARANTIDO PELO SW).
3- SAÍDA DO CADASTRO DE PRODUTOS SERÁ CODIGO <= 0;

FASE DE VENDAS!
1- SOLICITAR CODIGO DE ITEM PARA VENDA:
	1.1- VERIFICAR SE ITEM EXISTE
		1.1.1- IMPRIMIR TODOS OS DADOS DO PRODUTO, OU
		1.1.2- CODIGO NÃO EXISTENTE! TENTAR NOVAMENTE.

	1.2. SOLICITAR QUANTIDADE DESTE MESMO ITEM NO CARRINHO
		1.2.1- VERIFICAR SE A QTDE. ESTÁ DISPONÍVEL
		1.2.2- ATUALIZAR ESTOQUE DO ITEM
		
2. REPETIR TODO PROCESSO DE VENDA DO CARRINHO ATÉ CÓDIGO <=0

3. INFORMAR TOTAL DA VENDA
4. INFORMAR VALOR PAGO
5. INFORMAR TROCO DA VENDA

6. PERGUNTAR SE HÁ NOVO CARRINHO DE COMPRAS
	6.1. REPETIR TODO PROCESSO PARA NOVO CARRINHO.

7. NÃO HAVENDO...
	7.1 RELATÓRIO ATUALIZADO DE TODOS OS PRODUTOS
	7.2 FATURAMENTO DO DIA (TOTAL DE VENDAS)
*/
#define STR " %s"
#define FLT " %f"
#define INT " %i"
#define MAX 100

typedef struct{
	int codigo;   //chave
	char descricao[100];
	float valor;
	int estoque;
}Produto;

void input(char tipo[], char texto[], void* campo){
	printf("Insira %s do produto: ", texto);
	scanf(tipo, campo);
}

void pressEnter(char texto[]){
	printf("%sPressione ENTER...", texto);
	while(getchar() != '\n');
	getchar();
	system("clear");
}

void printLinha(int quantSimb, char texto[], char simbolo){
	for(int i = 0; i < quantSimb; i++)
		printf("%c", simbolo);
	printf(" %s ", texto);
	for(int i = 0; i < quantSimb; i++)
		printf("%c", simbolo);
	printf("\n");
}

void ordena(Produto produtos[], int cont){
	for(int i = 1; i < cont; i++){
		Produto temp = produtos[i];
		int j = i - 1;
		
		while(j >= 0 && temp.codigo < produtos[j].codigo){
			produtos[j+1] = produtos[j];
			j--;
		}
		produtos[j+1] = temp;
	}
}

typedef struct{
	int existe;
	int id;
}BuscaRet;

void busca(Produto produtos[], int cont, int valor_comp, BuscaRet* ret){
	int ini = 0, fim = cont-1, meio;
	ret->existe = 0;
	while(ini < fim+1){
		meio = (ini+fim)/2;
		if(valor_comp == produtos[meio].codigo){
			ret->existe = 1;
			break;
		}else if(valor_comp > produtos[meio].codigo){
			ini = meio+1;
		}else{
			fim = meio-1;
		}
	}
	ret->id = meio;
}

int main(){
	Produto produtos[MAX];
	int cont = 0;
	
	//CADASTRO DE PRODUTOS
	while(cont < MAX){
		printLinha(30, "CADASTRO DE PRODUTOS", '=');
		printf("Digite '0' ou valor menor para sair\n");
		input(INT, "o código", &produtos[cont].codigo);

		if(produtos[cont].codigo <= 0){
			system("clear");
			break;
		}
		
		//verifica se já existe para não cadastrar repetido
		BuscaRet ret;
		busca(produtos, cont, produtos[cont].codigo, &ret);
		if(ret.existe){
			pressEnter("Código de produto já cadastrado! ");
			continue;
		}
		
		input(STR, "a descrição", produtos[cont].descricao);
		input(FLT, "o preço", &produtos[cont].valor);
		input(INT, "a quantidade", &produtos[cont].estoque);

		cont++;
		//ordena para busca binária
		ordena(produtos, cont);
		system("clear");
	}
	
	//VENDAS
	int cont_prt = cont;
	float valor_tot = 0, faturamento = 0;
	while(1){
		int codigo_venda;
		printLinha(38, "VENDAS", '=');
		input(INT, "o código", &codigo_venda);

		if(codigo_venda<=0){
			system("clear");
			float valor_pago;
			do{
				//tratamento final da compra: valor total, valor pago e troco
				printLinha(38, "VENDAS", '=');
				printf("Valor total da compra (R$): %.2f\n", valor_tot);
				printf("Quantidade paga (R$): ");
				scanf(" %f", &valor_pago);
				if(valor_pago < valor_tot){
					pressEnter("Valor insuficiente! ");
					continue;
				}
				printf("Troco: R$ %.2f\n\n", valor_pago - valor_tot);
			}while(valor_pago < valor_tot);
			
			faturamento += valor_tot;
			valor_tot = 0;
			pressEnter("");
			system("clear");
			
			char esc;
			do{
				printf("Cadatrar outro carrinho[s/n]: ");
				scanf(" %c", &esc);
				if(esc == 's'){
					break;
				}else if(esc == 'n'){
					system("clear");
					//ordena para imprimir
					ordena(produtos, cont_prt);
					
					//RELATÓRIO
					printLinha(37, "RELATÓRIO", '=');
					for(int i = 0; i < cont_prt; i++){
						printf("Cód: %i - Valor: R$ %.2f - Quant. em estoque: %i - Descrição: %s\n", produtos[i].codigo, produtos[i].valor, produtos[i].estoque, produtos[i].descricao);
					}
					printf("\nFaturamento do dia: R$ %.2f", faturamento);
					return 0;
				}
				pressEnter("Entrada inválida! ");
			}while(esc != 's' && esc != 'n');
		}
		
		//Verifica se o produto está em estoque
		BuscaRet ret;
		busca(produtos, cont, codigo_venda, &ret);
		if(ret.existe){
			printf("Cód: %i - Valor: R$ %.2f - Quant. em estoque: %i - Descrição: %s\n", produtos[ret.id].codigo, produtos[ret.id].valor, produtos[ret.id].estoque, produtos[ret.id].descricao);	
		}else{
			pressEnter("Código não existente, tente novamente! ");
			continue;
		}
		
		//Quantidade do produto vendido
		int quantidade_venda;
		printf("Quantidade do item: ");
		scanf(" %i", &quantidade_venda);
		
		//verifica se quantidade é suficiente
		if(quantidade_venda > produtos[ret.id].estoque){
			pressEnter("Quantidade indisponível. ");
			continue;
		}
		system("clear");
		
		//soma o valor da compra
		valor_tot += produtos[ret.id].valor * quantidade_venda;
		
		//atualiza estoque e indisponibiliza produto caso não haja mais
		produtos[ret.id].estoque -= quantidade_venda;
		if(!produtos[ret.id].estoque){
			Produto temp = produtos[ret.id];
			for(int i = ret.id; i < cont-1; i++){
				produtos[i] = produtos[i+1];
			}
			produtos[cont-1] = temp;
			cont--;
		}
	}
}
