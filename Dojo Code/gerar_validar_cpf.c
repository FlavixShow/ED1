#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
	srand(time(NULL));
	
	int size = 11;
	char cpf[size + 1];
	int somaA = 0, somaB = 0;
	
	while(1){
		
		int esc;
		
		printf("Opções:\n");
		printf("1 - verificar\n");
		printf("2 - Gerar\n");
		printf("3 - Sair\n");
		scanf(" %i", &esc);
		
		
		if(esc == 1){
			printf("Digite o CPF: ");
			scanf(" %[^\n]s", cpf);
		
			// Verificação CPF
			int somaA = 0, somaB = 0;
			for (int i = 0; i <= 8; i++)
				somaA += (cpf[i]-'0')*(i+1);
			
			for (int i = 0; i <= 9; i++)
				somaB += (cpf[i]-'0')*i;
				
			int dv1 = somaA % 11 > 9 ? 0 : somaA % 11;
			int dv2 = somaB % 11 > 9 ? 0 : somaB % 11;
			
			int pnd = (cpf[9]-'0'), ud = (cpf[10]-'0');
			if (dv1 == pnd && dv2 == ud) {
				printf("Valido!\n");
			} else if (dv1 != pnd) {
				printf("O 'dv1' é inválido.\n");
			} else if (dv2 != ud) {
				printf("O 'dv2' é inválido.\n");
			}
			continue;
		}
		
		if(esc == 2){
			// Gerador de CPF
			for (int i = 0; i < 11; i++) {
				if (i < 9) {
					cpf[i] = '0' + rand() % 10;
				} else {
					somaA = somaB = 0;
					// Penultimo digito
					for (int j = 0; j <= 8; j++)
						somaA += (cpf[j]-'0')*(j+1); 
					cpf[i] = '0' + (somaA % 11 > 9 ? 0 : somaA % 11);
					
					// Ultimo digito
					for (int j = 0; j <= 9; j++)
						somaB += (cpf[j]-'0')*j;
					cpf[i+1] = '0' + (somaB % 11 > 9 ? 0 : somaB % 11);
					break;
				}
			}
			printf("%s\n", cpf);
			continue;
		}
		if(esc > 3 || esc < 1){
			printf("inválido\n");
			system("clear");
			continue;
		}
		break;
	}
	
	return 0;
}
