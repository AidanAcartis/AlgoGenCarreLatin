#ifndef LATIN_SQUARE_H
#define LATIN_SQUARE_H

#include "permutation.h"

typedef struct {
    int taille;
    int **carre;
} LatinSquare;

LatinSquare* LatinSquare_create(int taille);
void LatinSquare_destroy(LatinSquare *ls);

void LatinSquare_build(LatinSquare *ls, Permutation *p);
void LatinSquare_print(LatinSquare *ls);

#endif
