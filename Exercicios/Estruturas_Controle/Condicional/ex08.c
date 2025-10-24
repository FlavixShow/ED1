#include <stdio.h>

int main(){
	
	int d, m, a;
	
	printf("Digite dia, mes e ano: ");
	scanf("%i %i %i", &d, &m, &a);
	

	if(d == 30 && m == 12){ // virada de ano;
		m = 1;
		d = 1;
		a++;
	}else if(d == 30){ // virada de mês;
		d = 1;
		m++;
	}else{ // virada de dia kk;
		d++;
	}
	
	printf("Amanhã será %02i/%02i/%i", d, m, a);

	
	
	
	
	
	// easter egg
	if(d == 14 && m == 9){
		printf("\nVida longa ao sacro imperador da humanidade!");
	}
}
	
