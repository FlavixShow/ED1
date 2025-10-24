#include <stdlib.h>
#include <stdio.h>

int main(){
	
	int valor, cem, cinq, vin, dez, cin, dois;

	printf("Quanto deseja sacar? ");
	scanf("%i", &valor);
	
	cem = valor/100;
	valor -= cem * 100;
	cinq = valor/50;
	valor -= cinq * 50;
	vin = valor/20;
	valor -= vin * 20;
	dez = valor/10;
	valor -= dez * 10;
	cin = valor/05;
	valor -= cin * 05;
	dois = valor/2;
	valor -= dois * 02;
	printf("Notas de R$ 100.00: %i\n", cem);
	printf("Notas de R$ 50.00: %i\n", cinq);
	printf("Notas de R$ 20.00: %i\n", vin);
	printf("Notas de R$ 10.00: %i\n", dez);
	printf("Notas de R$ 5.00: %i\n", cin);
	printf("Notas de R$ 2.00: %i\n", dois);
	printf("Notas de R$ 1.00: %i\n", valor);
	printf("Total de notas: %i", cem + cinq + vin + dez + cin + dois + valor);

}
