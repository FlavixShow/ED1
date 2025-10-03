#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int num, cont = 0;
	srand(time(NULL));
	do{
		num = rand() % 201 - 100;
		printf("%i\n", num);
		if(num == 0)
			break;
				
		cont++;
	}while(1);
	 printf("Total de números: %i", cont);
}
