#ifndef VERIFICATION_H
#define VERIFICATION_H

/* Retournons 1 si l'expression est bien parathésée, */
int verifierParenthesage(char expression[]);

/* REtournons 1 si la paire ouvrante ou fermante est similaire, */
int compatible(char ouvrant, char fermant);

#endif