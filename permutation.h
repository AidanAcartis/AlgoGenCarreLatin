#ifndef PERMUTATION_H
#define PERMUTATION_H

typedef struct {
    int taille;
    int *base;      // tableau t
    int *permute;   // tableau T
} Permutation;

Permutation* Permutation_create(int taille);
void Permutation_destroy(Permutation *p);
void Permutation_init(Permutation *p);
void Permutation_rotate(Permutation *p, int tour, int permut);
void Permutation_print(Permutation *p);

int factoriel(int a);
int factoriel_sur2(int a);

#endif
