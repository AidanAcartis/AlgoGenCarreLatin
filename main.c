#include <stdio.h>
#include <stdlib.h>
#include "permutation.h"
#include "boucles.h"
#include "utils.h"

int main()
{
    int *T = NULL;
    int *t = NULL;
    int dimension = 0;

    int *Tour = NULL;
    int *Permut = NULL;
    int compteur = 0;

    printf("\nEntrer la dimension :)(::");
    scanf("%d", &dimension);

    T = malloc((dimension)*sizeof(int));
    t = malloc((dimension)*sizeof(int));

    DefinirTableaut(t, dimension);
    afficheTableauPermutee(t, dimension);

    Tour = malloc((dimension)*sizeof(int));
    Permut = malloc((dimension)*sizeof(int));

    int n = dimension;
    Tour[0] = n;
    for(int l=1; l<(dimension-1); l++) {
        Tour[l] = n;
        n--;
    }
    Tour[dimension-1] = 1;

    int m = dimension;
    Permut[0] = m;
    for(int k=1; k<=(dimension-1); k++) {
        Permut[k] = m;
        m--;
    }

    printf("\nOn doit obtenir %d permutaions possibles", Factoriel(dimension));
    printf("\n");

    BouclePermut(Tour, Permut, T, t, dimension, compteur);

    free(Tour);
    free(T);
    free(t);
    free(Permut);
    return 0;
}
