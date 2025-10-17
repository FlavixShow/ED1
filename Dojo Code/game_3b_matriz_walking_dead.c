#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>

int main(){
	
	srand(time(NULL));
	
	//introdução
	printf("---===============>> WALKING DEAD <<===============---\n\n");
	printf("Alô Rick Grimes! Você precisa atravessar a cidade repleta de zumbis\nassassinos com apenas um rifle e 50 munições.\nCada quarteirão da cidade possui a quantidade de zumbis indicado pelo\nnúmero impresso, e você deve percorrer cada quarteirão uma única vez!\nMas atenção... Há também um quarteirão (#) com munições extras.\n\nSEJA ESTRATÉGICO! Você será capaz de sair vivo desse desafio?\n\nTeclas de navegação:\n\n");
	printf("\t'w'\n\n'a'\t\t'd'\n\n\t's'\n\n");
	printf("Pressione ENTER para começar...");
	while(getchar() != '\n');
	system("clear");
	
	//variaveis da munição (condição de vitória ou derrota)
	int municao = 50, municaoGasta = 0;
	
	//gerar posição do bonus
	int xBonus, yBonus;
	do{
		xBonus = rand() % 10;
		yBonus = rand() % 10;
	}while(!xBonus || !yBonus);
	
	//primeiro frame kk
	int campo[10][10];
	printf("*\n");
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			campo[i][j] = rand() % 10;
			if(i == yBonus && j == xBonus){
				printf("# ");
				continue;
			}
			printf("%i ", campo[i][j]);
		}
		printf("\n");
	}
	gotoxy(18, 12);
	printf("[@]\n\n");
	printf("MUNIÇÃO UTILIZZADA: %i/%i\n", municaoGasta, municao);
	
	//colisão para verificar onde já passou;
	int colisao[10][10];
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			colisao[i][j] = 1;
		}
	}
	
	//variaveis de controle
	int x = 1, y = 0, xAnt = 0, yAnt = 0;
	
	//flags de controle
	int primMove = 1, inv = 0, pegou = 0;
	
	do{
		//movimento anterior
		xAnt = x;
		yAnt = y;
		//movimentação
		switch(getch()){
			case 'w': y--;
			break;
			case 'a': x--;
			break;
			case 's': y++;
			break;
			case 'd': x++;
			break;
		}
		//condição de vitória
		if(x == 10 && y == 11){
			printf("\n\n");
			printf("=D\nPARABÉNS! VOCÊ FOI SALVO!");
			break;
		}	
		//nao sair da matriz{
		if(x > 10){
			x = 10;
			printf("Movimento inválido.");
			inv = 1;
			getch();
		}
		//no movimento inicial
		if(primMove){
			if(x != 1){
				x = 1;
				printf("Movimento inválido.");
				inv = 1;
				getch();
			}
			if(y < 0){
			y = 0;
			printf("Movimento inválido.");
			inv = 1;
			getch();
		}
		}else{
			if(x <= 0){
				x = 1;
				printf("Movimento inválido.");
				inv = 1;
				getch();
			}
			if(y <= 0){
				y = 1;
				printf("Movimento inválido.");
				inv = 1;
				getch();
			}
		}
		if(y > 10){
			y = 10;
			printf("Movimento inválido.");
			inv = 1;
			getch();
		}
		//}
		
		//se o caminho já tiver sido usado
		if(!colisao[y-1][x-1] && !inv){
			x = xAnt;
			y = yAnt;
			printf("Movimento inválido.");
			inv = 1;
			getch();
		}
		//quando sai do ponto inicial
		if(y == 1){
			primMove = 0;
		}
		
		//somar os pontos e setar as posições já utilizada
		if(x > 0 && y > 0 && !inv){
			municaoGasta += campo[y-1][x-1];
			colisao[y-1][x-1] = 0;
		}
		
		//pegar o bônus
		if((x-1) == xBonus && (y-1) == yBonus){
			municao += 10;
			pegou = 1;
		}
		
		//zerar flag de movimento inválido
		inv = 0;
		
		//escrever a tela
		system("clear");
		cursor(0);
		printf("*\n");
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				if(i == yBonus && j == xBonus && !pegou){
					printf("# ");
					continue;
				}
				if(i == (y-1) && j == (x-1)){
					printf("_ ");
					continue;
				}
				if(!colisao[i][j]){
					printf("* ");
					continue;
				}
				printf("%i ", campo[i][j]);
			}
			printf("\n");
		}
		gotoxy(18, 12);
		printf("[@]\n\n");
		printf("MUNIÇÃO UTILIZZADA: %i/%i\n", municaoGasta, municao);
		
		
		//condição de derrota
		if(municaoGasta >= municao){
			printf("\n\n");
			printf("=(\nVirou Zumbi. Já era...");
			break;
		}
		
		
		//debug
		/*printf("x: %i y: %i valor pego: %i municão gasta: %i xBonus: %i yBonus: %i", x, y, campo[y-1][x-1], municaoGasta, xBonus, yBonus);
		printf("\n\n");
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				printf("%i ", colisao[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");*/
	}while(1);
}
