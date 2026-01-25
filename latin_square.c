#include <stdio.h>
#include <stdlib.h>
#include "latin_square.h"

LatinSquare* LatinSquare_create(int taille) {
    LatinSquare *ls = malloc(sizeof(LatinSquare));
    ls->taille = taille;
    ls->carre = malloc(taille * sizeof(int*));
    for(int i=0; i<taille; i++) {
        ls->carre[i] = malloc(taille * sizeof(int));
    }
    return ls;
}

void LatinSquare_destroy(LatinSquare *ls) {
    for(int i=0; i<ls->taille; i++) {
        free(ls->carre[i]);
    }
    free(ls->carre);
    free(ls);
}

void LatinSquare_build(LatinSquare *ls, Permutation *p) {
    for(int i=0; i<ls->taille; i++) {
        for(int j=0; j<ls->taille; j++) {
            ls->carre[i][j] = p->permute[(i + j) % ls->taille];
        }
    }
}

void LatinSquare_print(LatinSquare *ls) {
    for(int i=0; i<ls->taille; i++) {
        for(int j=0; j<ls->taille; j++) {
            printf("%2d ", ls->carre[i][j]);
        }
        printf("\n");
    }
}
