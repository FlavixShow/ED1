#include <stdio.h>
#include <stdlib.h>

int main(){
		int n = 50;
		float pi = 3.14159;
		int k = 2;

		printf("%.2f\n", pi);
		printf("%.1f\n", pi*k);
		printf("%.1f\n", n*pi);
		printf("%04d\n", k);
		printf("%03d\n", n/k);
		printf("%d%20d\n", n*k, n);
}

