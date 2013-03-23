#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define TAILLE 12

void initTab(int tab[], int taille) {
	int i;
	
	for(i=0; i<taille; i++){
		tab[i] = rand()%50;
	}
		
}

void minArray(int tab[], int taille){
	int min = tab[0];
	int i;
	
	for(i=1; i<taille; i++){
		if(tab[i]<min){
			min = tab[i];
		}
	}
		
	printf("le min est %d\n", min);
}

void maxArray(int tab[], int taille){	
	int max = tab[0];
	int i;
	
	for(i=1; i<taille; i++){
		if(tab[i]>max){
			max = tab[i];
		}
	}
		
	printf("le max est %d\n", max);
}

void min2Array(int tab[], int taille){
	/* min1<min2 */
	int min1,min2,i;
	
	if(tab[0]>tab[1]){
		min2 = tab[0];
		min1 = tab[1];
	}else{
		min2 = tab[1];
		min1 = tab[0];
	}
	
	for(i=0; i<taille; i++){
		if(tab[i]>min1){
			if(tab[i]<min2){
				min2 = tab[i];
			}
		}
		else{
			min1 = tab[i];
		}
	}
	
	printf("\nappel minMaxArray\n");
	printf("le premier minimum est %d\n", min1);
	printf("le deuxieme minimum est %d\n", min2);
}


int main (int argc, char* argv[]){

	int i;
	int tab[TAILLE];
	srand(getpid());
	
	int sizeArray = sizeof(tab)/sizeof(tab[0]);
	
	/*initTab(tab, sizeof(tab)/sizeof(int));*/
	initTab(&tab[0], sizeArray);

	for(i=0; i<sizeof(tab)/sizeof(tab[0]); i++){
		printf("%d\n", tab[i]);
	}
	
	maxArray(&tab[0], sizeArray);
	minArray(&tab[0], sizeArray);
	min2Array(&tab[0], sizeArray);
		
	return 0;
}
