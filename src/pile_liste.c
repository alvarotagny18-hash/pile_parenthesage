#include <stdio.h>
#include <stdlib.h>
#include "../include/pile.h"

void initL(PileL *p) {
    *p = NULL;
}

int estVideL(PileL p) {
    return p == NULL;
}

void empilerL(PileL *p, char x) {
    Noeud *n = (Noeud *)malloc(sizeof(Noeud));
    if (n == NULL) { printf("Erreur allocation"); 
        return; }
    n->valeur = x;
    n->suivant = *p;
    *p = n;
}

char depilerL(PileL *p) {
    if (estVideL(*p)) { printf("Erreur : pile vide"); 
        return 0; }
    Noeud *tmp = *p;
    char val = tmp->valeur;
    *p = tmp->suivant;
    free(tmp);
    return val;
}

char sommetL(PileL p) {
    if (estVideL(p)) { printf("Erreur : pile vide"); 
        return 0; }
    return p->valeur;
}
