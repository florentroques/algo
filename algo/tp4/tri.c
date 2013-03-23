#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tri.h"
#define BORNE 10000 /*Nombre aleatoire de 0 à 10000 */

/*

	Procédure de remplissage aléatoire d'un tableau.

*/
void init_tab(int tab[], int taille){
	srand(time(NULL));
	int i=0;	
	while(i!=taille){
		tab[i]=rand()%BORNE;
		i++;
	}
}

/*

	Procédure qui permet l'échange de deux valeurs données en paramètre.
	
	Le coût des affectations est compté ici pour le calcul de la complexité.

*/
void echanger(int *a, int *b, int *comparaisons, int *affectations){
	int tmp = *a;
	*a = *b;
	*b = tmp;
	*affectations = *affectations+3;
}

/*

	Procédure de Tri d'un tableau en paramètre en utilisant le tri par selection.

*/
void tri_selection(int tab[], int taille, int *comparaisons, int *affectations){
	int i,min,j;
	for(i=0;i<taille-1;i++){
		min=i;
		*affectations = *affectations+2;
		*comparaisons = *comparaisons+1;
		for(j=i+1;j<taille;j++){
			if(tab[j]<tab[min]){ 
				min=j;
				*affectations = *affectations+1;
				*comparaisons = *comparaisons+1; 
			}
		*affectations = *affectations+1;
		*comparaisons = *comparaisons+1;
		}
		echanger(&tab[i],&tab[min],comparaisons,affectations);
	}
}

/*

	Procédure de Tri d'un tableau en paramètre en utilisant le tri par insertion.

*/
void tri_insertion(int tab[], int taille, int *comparaisons, int *affectations){
	int i,j,element;
	for(i=0;i<taille;i++){
		element=tab[i];
		j=i;
		*affectations = *affectations+2;
		*comparaisons = *comparaisons+1;
		while(j>0 && tab[j-1]>element){
			tab[j]=tab[j-1];
			j--;
			*affectations = *affectations+1;
			*comparaisons = *comparaisons+1; 
		}
		tab[j]=element;
		*affectations = *affectations+1;
	}
}

/*

	Procédure de Tri d'un tableau en paramètre en utilisant le tri Bulle.

*/
void tri_bulle(int tab[], int taille, int *comparaisons, int *affectations){
	int i=0,k;
	for(i=0;i<taille-1;i++){
		for(k=taille-1;k>i;k--){
			if(tab[k-1]>tab[k]){
				echanger(&tab[k],&tab[k-1],comparaisons,affectations);
				*comparaisons = *comparaisons+1;
			}
		*comparaisons = *comparaisons+1;
		}
	*comparaisons = *comparaisons+1;
	}
}

/*
La procédure QuickSort se charge de trier le tableau de façon récursive.

Le choix initial du pivot est un entier donné en paramètre.

*/
void q_sort(int tab[], int debut, int fin, int piv, int *comparaisons, int *affectations){
	if(debut >= fin) return;
	
	int posPivot;
	int gauche = debut-1;
    	int droite = fin+1;
	
	*affectations = *affectations+2;
	
	switch (piv) { 	
		case 1: posPivot = debut; break;
		case 2: posPivot = fin-1; break;
		case 3: posPivot = calcul_median(tab, debut, fin, comparaisons, affectations); break;
		case 4: posPivot = rand()%(fin-debut) + debut; break;
	}

    	while(gauche<=droite){
		do droite--; while(tab[droite]>tab[posPivot]);
		do gauche++; while(tab[gauche]<tab[posPivot]);
		*comparaisons = *comparaisons+3; 
	    	if(gauche<droite) {
			echanger(&tab[gauche],&tab[droite],comparaisons,affectations);       
		}        
           	else break;
	}
	q_sort(tab, debut, droite, piv, comparaisons, affectations);
	q_sort(tab, droite+1, fin, piv, comparaisons, affectations);
}


/*
CalculMedian est une fonction qui retourne le Median à 3 
dans un tableau fournit en paramètre. Si la taille du tableau est inférieur à 3, 
que les valeurs sont toutes identiques, ou s'il n'y a pas 3 valeurs différentes 
au minimum, alors la fonction renvoie l'indice de la première case du tableau.

*/
int calcul_median(int tab[], int debut, int fin, int *comparaisons, int *affectations){

	if((fin-debut)<2) return debut;	
	*comparaisons = *comparaisons+1;

	int i, j, min=debut, max=debut, compt=1;
	/*Calcul MIN MAX des 3 premières valeurs de tab*/
	for(i=debut;i<=fin;i++) {
		if( compt >= 3) break;
		if(tab[i] != tab[i-1]){
			if(tab[i] <= tab[min]) {
				min = i;
				*affectations = *affectations+1;
			}
			if(tab[i] >= tab[max]) {
				max = i;
				*affectations = *affectations+1;
			}
			*comparaisons = *comparaisons+4;
			compt++;
		}
	}

	/*Si moins de 3 valeurs dans tab, retourne le premier élément de tab*/
	if (compt<(debut+3)) return debut;
	*comparaisons = *comparaisons + 1;
	/* Retourne l'indice de l'élément median*/
	for(j=debut;j<i;j++) {
		if( j!= min && j!= max) return j;
		*comparaisons = *comparaisons + 1;		
	}
	return debut;
}


