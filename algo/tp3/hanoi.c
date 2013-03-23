#include <stdio.h>
#include <stdlib.h>

void hanoi(int nb_plateaux, char depart, char intermediaire, char arrivee){
	if(nb_plateaux==1){
		printf("deplacer 1 disque de d vers a\n");
	}
	else{
		hanoi(nb_plateaux-1, depart, arrivee, intermediaire);
		printf("deplacer 1 disque de d vers i\n");
		hanoi(nb_plateaux-1, arrivee, intermediaire ,depart);
	}
}

int main(int argc, char **argv) {

	int n=3;
	char d, i, a;

	hanoi(n,'d','i','a');


	return 0;
}
