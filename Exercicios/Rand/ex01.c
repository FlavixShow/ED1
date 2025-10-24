#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	srand(time(NULL));
	
	int x, y;
	
	printf("Insira X: \n");
	scanf("%i", &x);
	printf("Insira Y: \n");
	scanf("%i", &y);
	printf("\nNúmeros:\n");
	for(int i = 0; i < x; i++){
		printf("%i\n", rand() % (y+1));
	}
}
