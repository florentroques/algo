#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tri.h"

#define N 15

#define PIVOT_DEBUT 1
#define PIVOT_FIN 2
#define PIVOT_MEDIAN 3
#define PIVOT_RANDOM 4

int valeur[] = { 5, 10, 20, 40, 50, 75, 100, 200, 300, 500};



/*

Procédure créant les fichiers contenant le nombre moyen d'affectations
et de comparaisons pour toutes les tailles pour un algorithme. La procédure
prend le choix du tri en paramètre ainsi que les noms des fichiers à créer.

*/
void statistiques(char typeTri, char* fichierAff, char* fichierComp){
	
	int sommeComp, sommeAff, moyenneComp, moyenneAff, i, j, comparaisons, affectations, taille;

	int tableau[10000];
	
	FILE* fichier1 = fopen(fichierAff, "w");
	FILE* fichier2 = fopen(fichierComp, "w");
	
	for(i=0;i<10;i++){
		taille = valeur[i];
		sommeComp=0;
		sommeAff=0;
		for(j=0;j<N;j++){			
			init_tab(tableau, taille);
			comparaisons = 0;
			affectations = 0;
			switch (typeTri) {
			
				case 'S':
					tri_selection(tableau,taille, &comparaisons, &affectations);
					break;
					
				case 'I':
					tri_insertion(tableau,taille, &comparaisons, &affectations);
					break;
					
				case 'B':
					tri_bulle(tableau,taille, &comparaisons, &affectations);
					break;
					
				case 'D':
					q_sort(tableau, 0, taille-1, PIVOT_DEBUT, &comparaisons, &affectations);
					break;		
					
				case 'F':
					q_sort(tableau, 0, taille-1, PIVOT_FIN, &comparaisons, &affectations);
					break;
					
				case 'M':
					q_sort(tableau, 0, taille-1, PIVOT_MEDIAN, &comparaisons, &affectations);
					break;
					
				case 'A':
					q_sort(tableau, 0, taille-1, PIVOT_RANDOM, &comparaisons, &affectations);
					break;	
			}

			
			sommeComp = sommeComp + comparaisons;
			sommeAff = sommeAff + affectations;
		}
		moyenneComp = sommeComp / N;
		moyenneAff = sommeAff / N;
		fprintf(fichier1, "%d %d\n", taille, moyenneAff);
		fprintf(fichier2, "%d %d\n", taille, moyenneComp);
	}
	fclose(fichier1);
	fclose(fichier2);
	printf("Enregistrement des statistiques terminé.\n");
}

