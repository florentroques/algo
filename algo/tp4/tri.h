#ifndef tri_h

/* Afin de comptabiliser les valeurs des affectations et des comparaisons,
on utilise deux pointeurs sur des entiers que l'on passera en paramètres aux fonctions concernées,
qui se chargeront de les incrementer au fur et à mesure. */

void init_tab(int tab[], int taille);
void echanger(int *a, int *b, int *comparaisons, int *affectations);
void tri_selection(int tab[], int taille, int *comparaisons, int *affectations);
void tri_insertion(int tab[], int taille, int *comparaisons, int *affectations);
void tri_bulle(int tab[], int taille, int *comparaisons, int *affectations);
void q_sort(int tab[], int debut, int fin, int piv, int *comparaisons, int *affectations);
int calcul_median(int tab[], int debut, int fin, int *comparaisons, int *affectations);


#endif

