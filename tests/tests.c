#include <stdio.h>
#include "../include/pile.h"
#include "../include/verification.h"

int main() {
    char *expressions[] = {
        "(a+b)",
        "((a+b)*c)",
        "{[a+b]*(c-d)}",
        "((a+b)",
        "(a+b))",
        "{(a+b]*c}",
        "",
        "a+b*c",
        "{[(a+b)*c]-d}",
        "($+@)",
        "("
    };
    int attendus[] = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int n = 11;

    for (int i = 0; i < n; i++) {
        int res = verifierParenthesage(expressions[i]);
        printf("[%s] \"%s\" => %s\n",
            res == attendus[i] ? "OK" : "ECHEC",
            expressions[i],
            res ? "Correcte" : "Incorrecte");
    }
    return 0;
}