#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	
	int faces[6];
	int n, num;
	
	printf("Quantas vezes o dado será jogado? ");
	scanf("%i", &n);
	
	srand(time(NULL));
	for(int i = 0; i < n; i++){
		num = 1 + rand() % 6;
		faces[num - 1]++;
		
		/*switch (1 + rand() % 6){
			case 1: faces[0]++;
			break;
			case 2: faces[1]++;
			break;
			case 3: faces[2]++;
			break;
			case 4: faces[3]++;
			break;
			case 5: faces[4]++;
			break;
			case 6: faces[5]++;
			break;
		}*/
	}
	for(int i = 0; i < 6; i++){
		printf("O lado %i caiu %i vezes -> %.2f%c\n", i+1, faces[i], (float)faces[i]/n*100, '%');
	}
}
