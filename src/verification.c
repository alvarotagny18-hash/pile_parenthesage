#include <stdio.h>
#include "../include/pile.h"
#include "../include/verification.h"

int compatible(char ouvrant, char fermant) {
    if (ouvrant == '(' && fermant == ')') return 1;
    if (ouvrant == '[' && fermant == ']') return 1;
    if (ouvrant == '{' && fermant == '}') return 1;
    return 0;
}

int verifierParenthesage(char expression[]) {
    Pile p;
    init(&p);
    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            empiler(&p, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (estVide(p)) return 0;
            char o = depiler(&p);
            if (!compatible(o, c)) return 0;
        }
    }
    return estVide(p);
}