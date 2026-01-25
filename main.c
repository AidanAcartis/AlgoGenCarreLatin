#include <stdio.h>
#include <stdlib.h>
#include "permutation.h"
#include "latin_square.h"

int main() {
    int dimension;
    printf("Entrer la dimension : ");
    scanf("%d", &dimension);

    Permutation *p = Permutation_create(dimension);
    Permutation_init(p);
    Permutation_print(p);

    // Exemple de rotation
    Permutation_rotate(p, 2, dimension);
    Permutation_print(p);

    LatinSquare *ls = LatinSquare_create(dimension);
    LatinSquare_build(ls, p);
    LatinSquare_print(ls);

    LatinSquare_destroy(ls);
    Permutation_destroy(p);

    return 0;
}
