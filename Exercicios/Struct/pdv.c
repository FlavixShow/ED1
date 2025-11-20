#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//sistema pdv (ponto de venda)

typedef struct{
	int codigo;   //chave
	char descricao[100];
	float valor;
	int estoque;
}Produto;

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

#define MAX 100

int main(){
	
	Produto produtos[MAX];
	int cont = 0;
	
	//CADASTRO DE PRODUTOS
	while(cont < MAX){
		printf("=============================== CADASTRO DE PRODUTOS ===============================\n");
		printf("Digite '0' ou valor menor para sair\n");
		printf("Código do produto: ");
		scanf(" %i", &produtos[cont].codigo);
		
		if(produtos[cont].codigo <= 0){
			system("clear");
			break;
		}
		
		//verifica se já existe para não cadastrar repetido
		int ini = 0, fim = cont-1, existe = 0;
		while(ini < fim+1){
			int meio = (ini+fim)/2;
			if(produtos[meio].codigo == produtos[cont].codigo){
				existe = 1;
				break;
			}else if(produtos[meio].codigo < produtos[cont].codigo){
				ini = meio+1;
			}else{
				fim = meio-1;
			}
		}
		if(existe){
			printf("Código de produto já cadastrado! Pressinone ENTER...");
			while(getchar() != '\n');
			getchar();
			system("clear");
			continue;
		}
		
		printf("Descrição do produto: ");
		scanf(" %[^\n]s", produtos[cont].descricao);
		printf("Preço do produto (R$): ");
		scanf(" %f", &produtos[cont].valor);
		printf("Quant. do produto em estoque: ");
		scanf(" %i", &produtos[cont].estoque);
		
		cont++;
		//ordena para busca binária
		for(int i = 1; i < cont; i++){
			Produto temp = produtos[i];
			int j = i - 1;
			
			while(j >= 0 && temp.codigo < produtos[j].codigo){
				produtos[j+1] = produtos[j];
				j--;
				
			}
			produtos[j+1] = temp;
		}
		system("clear");
	}
	
	//VENDAS
	int cont_prt = cont;
	float valor_tot = 0, faturamento = 0;
	while(1){
		int codigo_venda;
		printf("====================================== VENDAS ======================================\n");
		printf("Código do item: ");
		scanf(" %i", &codigo_venda);
		
		if(codigo_venda<=0){
			system("clear");
			float valor_pago;
			do{
				//tratamento final da compra: valor total, valor pago e troco
				printf("====================================== VENDAS ======================================\n");
				printf("Valor total da compra (R$): %.2f\n", valor_tot);
				printf("Quantidade paga (R$): ");
				scanf(" %f", &valor_pago);
				if(valor_pago < valor_tot){
					printf("Valor insuficiente! Pressione ENTER...");
					while(getchar() != '\n');
					getchar();
					system("clear");
					continue;
				}
				printf("Troco: R$ %.2f\n\n", valor_pago - valor_tot);
			}while(valor_pago < valor_tot);
			
			faturamento += valor_tot;
			valor_tot = 0;
			printf("Pressione ENTER...");
			while(getchar() != '\n');
			getchar();
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
					for(int i = 1; i < cont_prt; i++){
						Produto temp = produtos[i];
						int j = i - 1;
			
						while(j >= 0 && temp.codigo < produtos[j].codigo){
							produtos[j+1] = produtos[j];
							j--;
							
						}
						produtos[j+1] = temp;
					}
					
					//RELATÓRIO
					printf("===================================== RELATÓRIO =====================================");
					for(int i = 0; i < cont_prt; i++){
						printf("Cód: %i - Valor: R$ %.2f - Quant. em estoque: %i - Descrição: %s\n", produtos[i].codigo, produtos[i].valor, produtos[i].estoque, produtos[i].descricao);

					}
					printf("\nFaturamento do dia: R$ %.2f", faturamento);
					return 0;
				}
				
				printf("Entrada inválida! Pressione ENTER...");
				while(getchar() != '\n');
				getchar();
				system("clear");
			}while(esc != 's' && esc != 'n');
			continue;
		}
		
		//Verifica se o produto está em estoque
		int ini = 0, fim = cont-1, existe = 0, meio;
		while(ini < fim+1){
			meio = (ini+fim)/2;
			if(codigo_venda == produtos[meio].codigo){
				printf("Cód: %i - Valor: R$ %.2f - Quant. em estoque: %i - Descrição: %s\n", produtos[meio].codigo, produtos[meio].valor, produtos[meio].estoque, produtos[meio].descricao);
				existe = 1;
				break;
			}else if(codigo_venda > produtos[meio].codigo){
				ini = meio+1;
			}else{
				fim = meio-1;
			}
		}
		if(!existe){
			printf("Código não existente, tente novamente! Pressione ENTER..");
			while(getchar() != '\n');
			getchar();
			system("clear");
			continue;
		}
		
		//Quantidade do produto vendido
		int quantidade_venda;
		printf("Quantidade do item: ");
		scanf(" %i", &quantidade_venda);
		
		//verifica se quantidade é suficiente
		if(quantidade_venda > produtos[meio].estoque){
			printf("Quantidade indisponível. Pressione ENTER...");
			while(getchar() != '\n');
			getchar();
			system("clear");
			continue;
		}
		system("clear");
		
		//soma o valor da compra
		valor_tot += produtos[meio].valor * quantidade_venda;
		
		//atualiza estoque e indisponibiliza produto caso não haja mais
		produtos[meio].estoque -= quantidade_venda;
		if(!produtos[meio].estoque){
			Produto temp = produtos[meio];
			for(int i = meio; i < cont-1; i++){
				produtos[i] = produtos[i+1];
			}
			produtos[cont-1] = temp;
			cont--;
		}
	}
}

