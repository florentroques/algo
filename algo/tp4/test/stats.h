#ifndef STATS_H
#define STATS_H
#include "tri.h"

#define NOMBRE 50

/*
*************************
** Fonctions qui renvoient la moyenne
** d'affectations et de comparaisons
** sur NOMBRE essais
*************************
*/
Tri moyInsertion(const int taille);
Tri moyBulles(const int taille);
Tri moySelection(const int taille);

#endif

