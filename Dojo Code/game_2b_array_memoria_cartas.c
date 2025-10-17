#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	
	int pares, ver, id, cont = 0, esc1, esc2, acertos = 0, tent = 0;
	
	do{
		printf("==========JOGO DA MEMÓRIA DE CARTAS==========\n");
		printf("Com quantos pares de cartas deseja jogar? ");
		scanf("%i", &pares);
		system("clear");
	}while(pares < 2);
	
	int size = pares*2;
	int vetor[size], index[size], jogo[size];
	
	//gera os pares
	for(int i = 0; i < size; i++){
		vetor[i] = i + 1;
		if(i >= size/2)
			vetor[i] = i - size/2 + 1;
		//printf("%i", vetor[i]);
	}
	
	//gera os index;
	do{
		id = rand() % size;
		for(int i = 0; i < size; i++){
			if(id == index[i]){
				ver = 0;
				break;
			}
			ver = 1;
		}
		if(ver){
			index[cont] = id;
			cont++;
			//printf("%i", index[cont - 1]);
		}
		ver = 0;
		
		if(cont == size)
			break;
	}while(1);
	
	//atribui os pares nos index;
	for(int i = 0; i < size; i++){
		jogo[index[i]] = vetor[i];
	}
	
	do{
		printf("==========JOGO DA MEMÓRIA DE CARTAS==========");
		printf("\n\n");
		for(int i = 0; i < size; i++){
			if(!jogo[i]){
				//verifica se as cartas já sairam;
				printf("   ");
				continue;
			}
			printf("[] ");
		}
		printf("\n");
		for(int i = 0; i < size; i++){
			
			if(!jogo[i]){
				//verifica se as cartas já sairam;
				printf("   ");
				continue;
			}
			printf("%02i ", i);
		}
		printf("\n\n");

		printf("Escolha um par de cartas: ");
		scanf("%i", &esc1);
		scanf("%i", &esc2);
		
		//verifica se os valores inseridos são maiores que o range, iguais entre si e se ja foram escolhidos;
		if(esc1 > (size - 1) || esc2 > (size - 1) || jogo[esc1] == 0 || jogo[esc2] == 0 || esc1 == esc2){
			printf("Escolha inválida. Tente novamente...\n");
			while(getchar() != '\n');
			getchar();
			system("clear");
			continue;
		}
		
		system("clear");
		
		//reescreve com as cartas viradas;
		printf("==========JOGO DA MEMÓRIA DE CARTAS==========");
		printf("\n\n");
		for(int i = 0; i < size; i++){
			if(!jogo[i]){
				//verifica se as cartas já sairam;
				printf("   ");
				continue;
			}
			if(i == esc1 || i == esc2){
				printf("%02i ", jogo[i]);
				continue;
			}
			printf("[] ");
		}
		printf("\n");
		for(int i = 0; i < size; i++){
			if(!jogo[i]){
				//verifica se as cartas já sairam;
				printf("   ");
				continue;
			}
			printf("%02i ", i);
		}
		printf("\n\n");
		
		// conta tentativa;
		tent++;
		//quando o jogador acerta;
		if(jogo[esc1] == jogo[esc2]){
			acertos++;
			
			if(acertos == pares){
				//caso seja a última rodada;
				printf("Venceu em %i tentativas.", tent);
				break;	
			}
			
			
			printf("Parabuanis. Vc acertou!\n");
			//tiras as cartas do jogo;
			jogo[esc1] = 0;
			jogo[esc2] = 0;
			while(getchar() != '\n');
			getchar();
			system("clear");
			continue;
		}
		
		//quando o jogador erra;
		printf("Não foi dessa vez :(\n");
		while(getchar() != '\n');
		getchar();
		system("clear");
	}while(1); 
}
