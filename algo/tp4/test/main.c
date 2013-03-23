#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tri.h"
#include "stats.h"

/* N tailles de tableau a tester */
#define N 30
/* Tableaux de taille T_SIZES */
#define T_SIZES {5,10,15,20/** /}/**/,25,30,35,40,45,50,55,60,65,70,75,80,85,90,95,100,125,150,175,200,250,275,300,400,500,600}/**/

int main(int argc, char* tab[]) {
  int i, taille[N] = T_SIZES;
  srand(time(NULL));

  for(i=0; i<N; i++) {
	/**/
    printf("%d %d %d %d\n", taille[i], moyInsertion(taille[i]).aff, moyBulles(taille[i]).aff, moySelection(taille[i]).aff);
    printf("%d %d %d %d\n", taille[i], moyInsertion(taille[i]).cmp, moyBulles(taille[i]).cmp, moySelection(taille[i]).aff);
    /** /
    printf("%d %d\n", taille[i], moySelection(taille[i]).aff);
    printf("%d %d\n", taille[i], moySelection(taille[i]).cmp);
    /**/
  }

  return 0;
}
