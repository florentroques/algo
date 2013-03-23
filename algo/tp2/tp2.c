#include <stdio.h>
#include <stdlib.h>

int fact_i(int n){
	if(n<0){
		fprintf(stderr, "Nombre positif uniquement");
		exit(1);
	}
	if(n==0) return 1;
  
	int i;
	for(i=1; n>0; n--){
		i=i*n;
	}
	return i;
}

int fact_r(int n){
	if(n<0){
		fprintf(stderr, "Nombre positif uniquement");
		exit(1);
	}
	if(n==0) return 1;

	return n*fact_r(n-1);
}
/***************************************************/

void ordreCroissant_i(int n){
	if(n<=0){
		fprintf(stderr, "Nombre >0 uniquement");
		exit(1);
	}
	if(n==1) printf("1");

	int i;
	for(i=1; i<=n; i++){
		printf("%d ",i);
	}
}

void ordreCroissant_r(int n){
	if(n==0){
		return;
	}

	ordreCroissant_r(n-1);
	printf("%d ",n);
}
/***************************************************/

void ordreDecroissant_i(int n){
	if(n<0){
		fprintf(stderr, "Nombre positif uniquement");
		exit(1);
	}
	if(n==0) printf("0");

	int i;
	for(i=n; i>0; i--){
		printf("%d ",i);
	}
}

void ordreDecroissant_r(int n){
	if(n==0){
		return;
	}

	printf("%d ",n);
	ordreDecroissant_r(n-1);
}
/***************************************************/

int sommeChiffre_i(int n){
	if(n<0){
		fprintf(stderr, "Nombre positif uniquement");
		exit(1);
	}
	if(n==0) printf("0");

	int i;
	for(i=0; i<n; i++){
		printf("%d",i%10);
	}

	return i;
}

int sommeChiffre_r(int n){

	if(n==0) return -1;
	int tmp = (n)%10;
	printf("%d",tmp);

	sommeChiffre_r(n-1);
}

/**
 * if tableau debut = tableau fin on a fini
 */
void testPalindrome(){

}


/**
 * Fonctions de test
 *
 * gdb quick reference
 * gdb -g exo.c
 *
 * ensuite gdb a.out
 *
 * (gdb) l
 * (gdb) breakpoint num
 */
void test_fact(int n){
	int result_fact_i = fact_i(n);
	printf("factorielle iterative %d\n",result_fact_i);
	int result_fact_r = fact_r(n);
	printf("factorielle recursive %d\n",result_fact_r);
}
void test_ordreCroissant(int n){
	printf("ordre croissant iteratif ");
	ordreCroissant_i(n);
	printf("\n");
	printf("ordre croissant recursif ");
	ordreCroissant_r(n);
	printf("\n");
}
void test_ordreDecroissant(int n){
	printf("ordre decroissant iteratif ");
	ordreDecroissant_i(n);
	printf("\n");
	printf("ordre decroissant recursif ");
	ordreDecroissant_r(n);
	printf("\n");
}

void test_sommeChiffre(int n){
	printf("somme chiffres iteratif ");
	sommeChiffre_i(n);
	printf("\n");
	printf("somme chiffres recursif ");
	sommeChiffre_r(n);
	printf("\n");
}

int main(int argc, char* argv[]){
	
	int test=912942;

	/** /
	test_fact(test);
	/**/
	/** /
	test_ordreCroissant(test);
	/**/
	/** /
	test_ordreDecroissant(test);
	/**/
	/**/
	test_sommeChiffre(test);
	/**/

	return 0;
}

