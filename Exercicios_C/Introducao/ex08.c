#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int um, cinq, vin, dez, cin;
	float total;
	
	printf("Quantidade de moedas de 1 real: ");
	scanf("%i", &um);
	printf("Quantidade de moedas de 50 cent.: ");
	scanf("%i", &cinq);
	printf("Quantidade de moedas de 25 cent.: ");
	scanf("%i", &vin);
	printf("Quantidade de moedas de 10 cent.: ");
	scanf("%i", &dez);
	printf("Quantidade de moedas de 05 cent.: ");
	scanf("%i", &cin);
	
	total = (float) um + (float) (cinq*50 + vin*25 + dez*10 + cin*05)/100;
	
	printf("Total em reais: %.2f", total);
	
}
