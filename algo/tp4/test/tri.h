#ifndef TRI_H
#define TRI_H

/* Bornes du random [1;10000] */
#define RAND 10000+1

/*
*************************
** Fonctions de lecture et d'écriture d'un tableau
*************************
*/

void randTab(int t[], const int taille);
void printTab(int const t[], const int taille);
typedef struct tri {
	int aff;
	int cmp;
} Tri;

/*
*************************
** Fonctions tri de tableau
*************************
*/

void echange(int *a, int *b, Tri* tri);
Tri triInsertion(int t[], int taille);
Tri triBulles(int t[], int taille);
Tri triSelection(int t[], int taille);
void triRapide(int t[], int taille);

void printTri(Tri tri, char* nomTri);

#endif
