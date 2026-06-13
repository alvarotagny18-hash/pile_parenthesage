#include <stdio.h>
#include "../include/pile.h"
#include "../include/verification.h"

int main() {
    printf("=== Test Pile tableau ===\n");
    Pile p;
    init(&p);
    empiler(&p, '(');
    empiler(&p, '[');
    empiler(&p, '{');
    printf("Depilage : ");
    while (!estVide(p)) printf("%c ", depiler(&p));
    printf("\n");
    if (estVide(p)) printf("Pile vide : OK\n");

    printf("\n=== Test Pile liste ===\n");
    PileL pl;
    initL(&pl);
    empilerL(&pl, '(');
    empilerL(&pl, '[');
    empilerL(&pl, '{');
    printf("Depilage : ");
    while (!estVideL(pl)) printf("%c ", depilerL(&pl));
    printf("\n");
    if (estVideL(pl)) printf("Pile vide : OK\n");

    printf("\n=== Test Verification ===\n");
    char *expressions[] = {"(a+b)", "((a+b)*c)", "{[a+b]*(c-d)}", "((a+b)", "(a+b))", "{(a+b]*c}"};
    int attendus[] = {1, 1, 1, 0, 0, 0};
    for (int i = 0; i < 6; i++) {
        int res = verifierParenthesage(expressions[i]);
        printf("[%s] %s => %s\n", res==attendus[i]?"OK":"ECHEC", expressions[i], res?"Correcte":"Incorrecte");
    }
    return 0;
}
