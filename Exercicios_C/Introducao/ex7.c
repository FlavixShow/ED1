#include <stdlib.h>
#include <stdio.h> 

int main(){
	
	float valor, preco;
	
	printf("Preço do combustível: ");
	scanf("%f", &preco);
	printf("Valor que deseja abastecer: ");
	scanf("%f", &valor);
	
	
	printf("Custando R$ %.2f o litro e abastecendo R$ %.2f a quantidade será: %.2f l", preco, valor, valor/preco);
}
