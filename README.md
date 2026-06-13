# Pile & Vérification du Parenthésage

Projet C — INF Algorithmique & Structures de données  
Licence 1 Informatique — Université de Yaoundé 1 — 2025/2026

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