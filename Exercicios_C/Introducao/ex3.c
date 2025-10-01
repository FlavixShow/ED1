#include <stdlib.h>
#include <stdio.h>

int main(){
		
		int s, h, m;
		
		printf("informe o tempo em segundos: ");
		scanf("%i", &s);
		
		h = (s/60)/60;
		s -= h*60*60; 
		m = s/60;
		s -= m*60;
		printf("%02i:%02i:%02i", h, m, s);
	
}
