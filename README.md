# Pile & Vérification du Parenthésage

Projet C — INF Algorithmique & Structures de données  
Licence 1 Informatique — Borelien — 2025/2026

## Description

Ce projet implémente une structure de pile (Stack) en C selon deux approches,
et l'utilise pour vérifier le parenthésage d'expressions mathématiques.

## Arborescence

## Compilation

```bash
make
```

## Exécution

```bash
./main        # tests unitaires pile + vérification
./run_tests   # cas de test automatisés
```

## Analyse

### Comparaison des deux implémentations

**Pile par tableau** : taille fixe (TAILLE_MAX=100), accès en O(1),
pas d'allocation dynamique. Simple et rapide mais limitée en taille.

**Pile par liste chaînée** : taille illimitée, chaque nœud est alloué
dynamiquement avec malloc. Plus flexible mais plus lente à cause des
allocations et libérations mémoire, et chaque nœud occupe plus d'espace
(valeur + pointeur).

### Pourquoi la pile est adaptée à ce problème ?

La propriété LIFO est exactement ce dont on a besoin : le dernier ouvrant
empilé doit être le premier vérifié quand on rencontre un fermant.

### Complexité

- **Temporelle** : O(n) — chaque caractère est traité une seule fois.
- **Spatiale** : O(n) dans le pire cas — si tous les caractères sont des ouvrants.

### Peut-on résoudre sans pile ?

Avec un simple compteur, on peut gérer un seul type de parenthèses `()`.
Mais avec plusieurs types `()`, `[]`, `{}`, le compteur ne suffit pas :
il ne peut pas détecter les incompatibilités comme `{(a+b]`.

### Question 13 — Pourquoi la pile est-elle adaptée à ce problème ?

La pile est parfaitement adaptée grâce à sa propriété LIFO (Last In, First Out).
Quand on parcourt une expression, le dernier ouvrant rencontré doit être le premier
vérifié lorsqu'on rencontre un fermant. Par exemple dans `{(a+b)}`, on empile `{`
puis `(`. Le premier fermant `)` doit correspondre à `(` (le dernier empilé), pas à `{`.
Une file (FIFO) donnerait le mauvais ordre de vérification.

### Question 14 — Que se passe-t-il quand un fermant arrive et la pile est vide ?

Cela signifie qu'il y a un fermant sans ouvrant correspondant : on retourne 0 immédiatement.
Exemple : `(a+b))` — après avoir traité `(a+b)`, la pile est vide. Le deuxième `)`
ne trouve aucun ouvrant → expression incorrecte.

### Question 15 — Pourquoi vérifier que la pile est vide à la fin ?

Il peut rester des ouvrants non fermés sans qu'aucune erreur n'ait été détectée
pendant le parcours. Exemple : `((a+b)` — le parcours se déroule sans erreur,
mais à la fin il reste `(` dans la pile → expression incorrecte.
Sans cette vérification finale, on conclurait à tort que l'expression est correcte.

### Question 16 — Complexité de l'algorithme ?

- **Temporelle** : O(n) — chaque caractère est traité exactement une fois.
  Chaque empilage et dépilage s'effectue en O(1).
- **Spatiale** : O(n) dans le pire cas — si tous les caractères sont des ouvrants,
  la pile contient n éléments simultanément.

### Question 17 — Peut-on résoudre sans pile ?

Avec un compteur simple, on peut gérer un seul type de parenthèses `()` :
on incrémente pour `(` et décrémente pour `)`. Si le compteur reste positif
et vaut 0 à la fin, l'expression est correcte.

Mais avec plusieurs types `()`, `[]`, `{}`, le compteur échoue.
Exemple : `{(a+b]` — le compteur voit autant d'ouvrants que de fermants
et dirait "correct", alors que la paire `{` / `]` est incompatible.
La pile est donc indispensable dès qu'on a plusieurs types de délimiteurs.