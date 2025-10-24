#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

int main(){
	
	char card[16];
	int soma = 0, esc;

	srand(time(NULL));
	
	while(1){
		printf("Opções: \n");
		printf("1 - Gerar cartão.\n2 - Validar cartão.\n3 - sair.\n");
		scanf("%i", &esc);
		
		if(esc == 1){
			for(int i = 0; i < 15; i++){
				card[i] = '0' + (rand() % 10);
				if(!(i % 2)){
					soma += (card[i] - '0') < 9? ((card[i]-'0')*2) % 9: 9;
					continue;
				}
				soma += card[i] - '0';
			}
			card[15] = '0' + (10 - (soma % 10));
			printf("\nCartão: %s", card);
			break;
		}
		if(esc == 2){
			printf("\nDigite o cartão: ");
			scanf("%s", card);
			
			for(int i = 0; i < 16; i++){
				if(!(i % 2)){
					soma += (card[i] - '0') < 9? ((card[i]-'0')*2) % 9: 9;
					continue;
				}
				soma += card[i] - '0';
			}
			
			if(!(soma % 10) && soma != 0){
				printf("\n\nCartão válido.");
			}else{
				printf("\n\nCartão inválido.");
			}
			break;
		}
		if(esc != 3){
			system("clear");
			continue;
		}
		break;
	}
}	
