#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <gconio.h>

int main(){

	int size = 5;
	int matriz[size + 1][size + 1];
	
	srand(time(NULL));

	for(int i = 0; i < size; i++){
		matriz[i][size] = 0;
		for(int j = 0; j < size; j++){
			matriz[i][j] = rand() % 2;
			//printf("%i\t", matriz[i][j]);
			matriz[i][size] += matriz[i][j];
		}
		//rintf("%i", matriz[i][size]);
		//printf("\n\n");
	}
	//printf("\n");
	for(int i = 0; i < size; i++){
		matriz[size][i] = 0;
		for(int j = 0; j < size; j++){
			matriz[size][i] += matriz[j][i];
			matriz[j][i] = 0;
		}
		//printf("%i\t", matriz[size][i]);
	}
	//printf("\n\n\n\n");
	
	int esc, jogadas = 0;
	do{
		printf("   ");
		for(int i = 0; i < size; i++){
			if(!i){
				printf("%i\t  ", i+1);
				continue;
			}
			printf("%i\t ", i+1);
		}
		printf("\n");
		printf(" ");
		for(int i = 0; i < (size + 4)*4; i++){
			printf("-");
		}
		printf("\n");
		
		for(int i = 0; i < size + 1; i++){
			for(int j = 0; j < size + 1; j++){
				if(i == size && j == i)
					break;
		
				if(j == size-1  && i < size){
					printf("%i  |", matriz[i][j]);
					continue;
				}
				if(j == size)
					printf(" ");
				if(!j && i < size){
					printf("%i| %i\t  ", i+1, matriz[i][j]);
					continue;
				}
				if(!j && i == size){
					printf("   %i\t  ", matriz[i][j]);
					continue;
				}
				printf("%i\t ", matriz[i][j]);
			}
			printf("\n");
			
			if(i == size-1){
				printf(" ");
				for(int j = 0; j < (size + 4)*4; j++){
					printf("-");
				}
			}
			for(int j = 0; j < size - 1; j++){
				if(!j && i < size-1){
					printf(" |\t");
					continue;
				}
				printf(" \t");
				if(j == size - 2 && i < size-1)
					printf("    |");
			}
			printf("\n");
		}
		printf("\n\n\n");
		int ganhou = 1;
		for(int i = 0; i < size; i++){
			int soma = 0;
			for(int j = 0; j < size; j++)
				soma += matriz[i][j];
			
			if(soma != matriz[i][size]){
					 ganhou = 0;
					 break;
			}
			soma = 0;
			
			for(int j = 0; j < size; j++)
				soma += matriz[j][i];
			
			if(soma != matriz[size][i]){
					 ganhou = 0;
					 break;
			}
			soma = 0;
		}

		if(ganhou == 1){
			printf("Parabéns. Você venceu./nTotal de jogadas: %i", jogadas);
			break;
		}
		scanf("%i", &esc);
		if(esc/10 < 6 && esc%10 < 6){
			matriz[(esc/10) - 1][(esc%10) - 1] = matriz[esc/10  - 1][esc%10 - 1] == 1? 0 : 1;	
			jogadas++;
			system("clear");
			continue;
		}	
		printf("Jogada inválida.");
		getchar();
		while(getchar() != '\n');
		system("clear");
	}while(1);
	
	return 0;
}
