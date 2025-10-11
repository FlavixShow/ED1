#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gconio.h>

int main (){
	
	int move = 0, 
		quantAlvo, 
		alvoColet = 0, 
		x = 4, 
		y = 5, 
		altura = 18, 
		largura = 70, 
		xAlvo = 4, 
		yAlvo = 5,
		xMeio,
		yMeio,
		corFundo = 0;
		
	float media = 0;
	
	char person = '>';
	
	textbackground(corFundo);
	//cabeçalho
	textcolor(CYAN);
	gotoxy(1,1);

	printf(" ==============SNAKE==============\n");
	printf(" Digite quantos alvos deseja: ");
	scanf("%i", &quantAlvo);
	system("clear");
	
	while(getchar() != '\n')
		quantAlvo = 0;

	while(quantAlvo <= 0){
		printf(" ========================SNAKE========================\n");
		printf(" Valor inválido, digite um número maior que zero: ");
		scanf("%i", &quantAlvo);
		while(getchar() != '\n')
		quantAlvo = 0;
		system("clear");
	}

	printf(" ==============SNAKE==============\n");
	printf(" Utilize [w] [a] [s] [d]");
	
	//gerar quadro
	for(int i = 0; i < largura+1; i++){
		gotoxy(i+3, 4);
		printf("_");
		gotoxy(i+3, altura+5);
		printf("-");
	}
	for(int j = 0; j < altura; j++){
		gotoxy(3, j+5);
		printf("|");
		gotoxy(largura+3, j+5);
		printf("|");
	}
	
	//posição inicial do personagem
	textcolor(WHITE);
	gotoxy(x,y);
	printf("%c", person);

	//primeira posição do alvo
	srand(time(NULL));
	while(xAlvo == 4)
		xAlvo = 4 + rand() % (largura-3);
	while(yAlvo == 5)
		yAlvo = 5 + rand() % (altura-1);
	gotoxy(xAlvo, yAlvo);
	printf("@");
	
	//definir meio do quadro para escrever parabéns
	xMeio = (largura-3)/2;
	yMeio = (altura-1)/2 + 5;
	
	//game
	do{
		//stats do game
		gotoxy(37,1);
		textcolor(WHITE);
		printf("Movimentos: %i - ", move);
		printf("Alvos: %i/%i - ", alvoColet, quantAlvo);
		printf("Média: %.2f", media);
		
		//parar jogo e escrever parabéns
		//tem que ser aqui para computar o ultimo alvo coletado 
		if(alvoColet == quantAlvo){
			gotoxy(xMeio, yMeio);
			printf("PARABÉNS!!!");
			gotoxy(xMeio-8, yMeio+1);
			printf("Pressione ENTER para sair...");
			break;
		}
		
		//movimento
		switch(getch()){
			case 'w': move++; y--; person = '^'; /*apagar passo anterior*/ gotoxy(x,y+1); printf(" ");
			break;
			case 'a': move++; x--; person = '<'; gotoxy(x+1,y); printf(" ");
			break;
			case 's': move++; y++; person = 'v'; gotoxy(x,y-1); printf(" ");
			break;
			case 'd': move++; x++; person = '>'; gotoxy(x-1,y); printf(" ");
			break;
		}
		
		//tratamento para não ultrapassar borda
		if(y == 4)
			y = altura + 4;
			
		if(y == altura + 5)
			y = 5;
			
		if(x == 3)
			x = largura + 2;
			
		if(x == largura + 3)
			x = 4;
		
		//desenhar movimento
		gotoxy(x,y);
		printf("%c", person);
		
		//tratar a coleta do alvo e gerar em outra posição
		if(x == xAlvo && y == yAlvo){
			xAlvo = 4 + rand() % (largura-3);
			yAlvo = 5 + rand() % (altura-1);
			alvoColet++;
			if(alvoColet != quantAlvo){
				gotoxy(xAlvo, yAlvo);
				printf("@");
			}
		}

		//calcular média de movimentos
		if(alvoColet)
			media = (float) move / alvoColet;
			
	}while(1);
	
	//Tirar o texto de fim de execução
	textcolor(corFundo);
	gotoxy(1, altura+4);
	printf(" ");
	
	return 0;
}
