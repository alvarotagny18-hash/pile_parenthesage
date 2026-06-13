#include <stdio.h>
#include "../include/pile.h"

void init(Pile *p) {
    p->sommet = -1;
}

int estVide(Pile p) {
    return p.sommet == -1;
}

int estPleine(Pile p) {
    return p.sommet == TAILLE_MAX - 1;
}

void empiler(Pile *p, char x) {
    if (estPleine(*p)) { printf("Erreur : pile pleine"); 
        return; }
    p->elements[++p->sommet] = x;
}

char depiler(Pile *p) {
    if (estVide(*p)) { printf("Erreur : pile vide"); 
        return 0; }
    return p->elements[p->sommet--];
}

char sommet(Pile p) {
    if (estVide(p)) { printf("Erreur : pile vide"); 
        return 0; }
    return p.elements[p.sommet];
}
