#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int escDia, escSem, cont = 0, cont2 = 0;
	
	printf("Quantos dias tem o mês?\nInsira: ");
	scanf("%i", &escDia);
	printf("Em qual dia da semana inicia o mês?\n1 - Domingo\n2 - Segunda\n3 - Terça\n4 - Quarta\n5 - Quinta\n6 - Sexta\n7 - Sabado\nInsira: ");
	scanf("%i", &escSem);
	system("clear");
	printf("Dom\tSeg\tTer\tQua\tQui\tSex\tSab");
	for(int i = 0; i < escDia+escSem-1; i++){
        if(i % 7 == 0){
            printf("\n");
        }
        cont2++;
        if(i < escSem-1){
            printf("%i\t", 30-escSem+1+cont2);
            continue;
        }
        cont++;
        printf("%02i\t", cont);
    }
}
