#include <stdio.h>
#include <string.h>

int main() {

	//verificar email
    char email[100];
    char az[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'x', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '_', '-'};
	
    
    scanf(" %[^\n]s", email);
	int quantArroba = 0, posArroba = strlen(email), ponto = 0; 
	int val = 0;
    for(int i = 0; i < strlen(email); i++){
		if(email[i] == '@'){
			posArroba = i;
			if(!i){
				printf("Inválido 1");
				return 0;
			}
			quantArroba++;	
			if(quantArroba > 1){
				printf("Inválido 2");
				break;
			}
			for(int j = 0; j < 3; j++){
				if(email[i+1] == az[strlen(az) - (j+1)]){
					printf("Inválido 3");
					return 0;
				}
				if(email[i-1] == az[strlen(az) - (j+1)]){
					printf("Inválido 4");
					return 0;
				}
			}
			continue;
		}
		for(int j = 0; j < strlen(az); j++){
			if((email[i]) == az[j]){
				val = 1;
				break;
			}
		}
		if(!val){
			printf("Inválido 5");
			return 0;
		}
		val = 0;
		for(int j = 0; j < 3; j++){
			if(email[0] == az[strlen(az) - (j+1)]){
				printf("Inválido 6");
				return 0;
			}
		}
		for(int j = 0; j < 26; j++){
			if(email[strlen(email)-1] == az[j]){
				val = 1;
				break;
			}
		}
		if(!val){
			printf("Inválido 7");
			return 0;
		}
		val = 0;
		if(i > posArroba){
			if(email[i] == '.'){
				ponto++;
				if(ponto > 1){
					printf("Inválido 8");
					return 0;
				}

				if(!email[i+2]){
					printf("Inválido 11");
					return 0;
				}
				continue;
			}
			for(int j = 0; j < 2; j++){
				if(email[i] == az[strlen(az) - (j+2)]){
					printf("Inválido 12");
					return 0;
				}
			}
		}
		for(int j = 0; j < 3; j++){
			if(email[i] == az[strlen(az) - (j+1)]){
				for(int k = 0; k < 3; k++){
					if(email[i+1] == az[strlen(az) - (k+1)]){
						printf("Inválido 13");
						return 0;
					}
					if(email[i-1] == az[strlen(az) - (k+1)]){
						printf("Inválido 14");
						return 0;
					}
				}
			}
		}
	}
	printf("Válido");
    return 0;
}
