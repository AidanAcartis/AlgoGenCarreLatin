#include <stdio.h>
#include "utils.h"


void afficheTableau(int Tableau[],int TailleTableau)///FONCTION AFFICHAGE
{
    int i;
    for(i=0;i<TailleTableau;i++)
	{
		printf("Tour[%d] = %d\n", i,Tableau[i]);
	}
}
void afficheTableauPermutee(int Tableau[], int TailleTableau)
{
	int i;
	printf("\n");
	for(i=0;i<TailleTableau;i++)
	{
		printf("%d\t",Tableau[i]);
	}                                      
}
int FactorielSur2(int a)
{
    if (a <= 1) return 1;  // ← IMPORTANT pour éviter la boucle infinie

    int F = 1;
    for(int i = 2; i <= a; i++)
        F *= i;

    return F / 2;
}

int Factoriel(int a)
{
    int F = 1;
    for(int i = 2; i <= a; i++)
        F *= i;
    return F;
}
