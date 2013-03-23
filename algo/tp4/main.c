/*		TP3 d'algorithme 			*/
/*			Complexité sur les tris			*/
/*				LOSLIER	Mathieu IR1			*/


#include <stdio.h>
#include <stdlib.h>

#include "statistiques.h"



int main(int argc, char** argv){

	statistiques('S',"selection_aff","selection_comp");
	statistiques('I',"insertion_aff","insertion_comp");
	statistiques('B',"bulle_aff","bulle_comp");
	statistiques('D',"qsort_debut_aff","qsort_debut_comp");
	statistiques('F',"qsort_fin_aff","qsort_fin_comp");
	statistiques('M',"qsort_median_aff","qsort_median_comp");
	statistiques('A',"qsort_alea_aff","qsort_alea_comp");
	
	return 0;
}
