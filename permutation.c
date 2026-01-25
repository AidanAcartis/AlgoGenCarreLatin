#include <stdio.h>
#include <stdlib.h>
#include "permutation.h"

Permutation* Permutation_create(int taille) {
    Permutation *p = malloc(sizeof(Permutation));
    p->taille = taille;
    p->base = malloc(taille * sizeof(int));
    p->permute = malloc(taille * sizeof(int));
    return p;
}

void Permutation_destroy(Permutation *p) {
    free(p->base);
    free(p->permute);
    free(p);
}

void Permutation_init(Permutation *p) {
    for(int i=0; i<p->taille; i++) {
        p->base[i] = ((i + p->taille) % p->taille) + 1;
    }
}

void Permutation_rotate(Permutation *p, int tour, int permut) {
    int i = p->taille - 1;
    int compt = 0;

    if(tour > permut || tour > p->taille || permut > p->taille) {
        printf("Erreur: paramètres invalides\n");
        return;
    }

    do {
        int s = i + tour;
        if(s < p->taille) {
            p->permute[i] = p->base[s];
        } else {
            p->permute[i] = p->base[s - permut];
        }
        i--;
        compt++;
    } while(compt != permut);

    while(i >= 0) {
        p->permute[i] = p->base[i];
        i--;
        compt++;
    }
}

void Permutation_print(Permutation *p) {
    for(int i=0; i<p->taille; i++) {
        printf("%d ", p->permute[i]);
    }
    printf("\n");
}

int factoriel(int a) {
    int F = 1;
    while(a > 1) {
        F *= a;
        a--;
    }
    return F;
}

int factoriel_sur2(int a) {
    return factoriel(a) / 2;
}
