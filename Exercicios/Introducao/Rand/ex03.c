#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int num, m , c, d, u, soma, cubo;
	srand(time(NULL));
	do{
		num = 1000 + rand() % 9001;
		m = num / 1000;
		c = (num % 1000)/100;
		d = (((num % 1000))%100)/10;
		u = ((num % 1000)%100)%10;
		soma = m + c + d + u;
		cubo = soma*soma*soma;
		if(cubo == num){
			printf("%i\n", num);
			system("sleep 1");
			// 4913 e 5832;
		}
	}while(1);
}
