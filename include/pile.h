#ifndef PILE_H
#define PILE_H

#define TAILLE_MAX 100

typedef struct {
    char elements[TAILLE_MAX];
    int sommet;
} Pile;

void init(Pile *p);
int estVide(Pile p);
int estPleine(Pile p);
void empiler(Pile *p, char x);
char depiler(Pile *p);
char sommet(Pile p);

typedef struct Noeud {
    char valeur;
    struct Noeud *suivant;
} Noeud;

typedef Noeud *PileL;

void initL(PileL *p);
int estVideL(PileL p);
void empilerL(PileL *p, char x);
char depilerL(PileL *p);
char sommetL(PileL p);

#endif
