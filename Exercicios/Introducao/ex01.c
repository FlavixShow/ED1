#include <stdio.h>
#include <stdlib.h>

int main(){
		
		int a, b;
		
		printf("Digite os dois números: ");
		scanf("%d %d", &a, &b);
		
		printf("a = %i\n", a);
		printf("b = %i\n", b);
		
		a = a + b;
		b = a - b;
		a = a - b;
		
		printf("a = %i\n", a);
		printf("b = %i\n", b);

}
