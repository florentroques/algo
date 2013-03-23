#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tri.h"

void randTab(int t[], const int taille) {
	int i;
	srand(time(NULL));

	for(i=0; i<taille; i++) {
		t[i] = rand()%RAND;
	}
}

void printTab(int const t[], const int taille) {
	int i;

	for(i=0; i<taille; i++) {
		printf("%d ", t[i]);
	}

	printf("\n");
}
void echange(int *a, int *b, Tri* tri) {
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
	(*tri).aff = (*tri).aff+3;
}

Tri triInsertion(int t[], int taille) {
	Tri tri = {0, 0};
	int i, j, elem;

	for(i=1; i<taille; i++) {
		elem = t[i];
		j = i;

		tri.aff = tri.aff + 2;
		tri.cmp++;

		while(j>0 && t[j-1]>elem) {
			t[j] = t[j-1];
			j--;
			tri.aff++;
			tri.cmp++;
		}

		t[j] = elem;
		tri.aff++;
	}
	/** /
	printTri(tri, "Insertion");
	/**/
	return tri;
}

Tri triBulles(int t[], int taille) {
	Tri tri = {0, 0};
	int i, j;

	for(i=0; i<taille-1; i++) {
		for(j=taille-1; j>i; j--) {
			if(t[j]<t[j-1]) {
				echange(&t[j], &t[j-1], &tri);
				tri.cmp++;
			}

			tri.cmp++;
		}
		tri.cmp++;
	}
	/** /
	printTri(tri, "Bulles");
	/**/
	return tri;
}

Tri triSelection(int t[], int taille) {
	Tri tri = {0, 0};
	int i, j, min;

	for(i=0; i<taille-1; i++) {
		min = i;
		tri.aff = tri.aff + 2;
		tri.cmp++;

		for(j=i+1; j<taille; j++) {
			if(t[min]>t[j]) {
				min = j;
				tri.aff++;
				tri.cmp++;
			}

			tri.aff++;
			tri.cmp++;
		}
		echange(&t[i], &t[min], &tri);
	}
	/** /
	printTri(tri, "Selection");
	/**/
	return tri;
}

void choix(){

}

void triRapide(int t[], int taille) {
	
}

void printTri(Tri tri, char* nomTri) {
	printf("Tri %s Affectations: %d Comparaisons: %d\n", nomTri, tri.aff, tri.cmp);
}

