# Radix Sort

Ce projet implémente l'algorithme de tri Radix Sort en utilisant l'approche LSD (Least Significant Digit) en langage C.

## Description

Le tri Radix (Radix Sort) est un algorithme de tri non comparatif qui trie les entiers en les traitant chiffre par chiffre. Cette implémentation utilise l'approche LSD qui commence par le chiffre le moins significatif (unités) et progresse vers les chiffres les plus significatifs.

## Algorithme

L'algorithme fonctionne en plusieurs étapes :

1. Trouve le nombre maximum dans le tableau pour déterminer le nombre de chiffres
2. Pour chaque position de chiffre (unités, dizaines, centaines, etc.) :
   - Effectue un tri par comptage stable basé sur le chiffre à cette position
   - Affiche le tableau après chaque étape

## Complexité

- **Complexité temporelle** : O(d × (n + k))
  - d = nombre de chiffres dans le plus grand nombre
  - n = nombre d'éléments
  - k = plage de valeurs possibles pour un chiffre (0-9)
- **Complexité spatiale** : O(n + k)

## Fichiers

- `0-radix_sort.c` : Implémentation principale de l'algorithme Radix Sort
- `sort.h` : Fichier d'en-tête contenant les prototypes des fonctions
- `print_array.c` : Fonction utilitaire pour afficher les tableaux
- `0-main.c` : Fichier de test (optionnel)

## Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-radix_sort.c print_array.c -o radix
```

## Exécution

```bash
./radix
```

## Exemple de sortie

```
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

71, 52, 13, 73, 96, 86, 7, 48, 19, 99
7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
```

## Fonctions

### `void radix_sort(int *array, size_t size)`

Fonction principale qui trie un tableau d'entiers en ordre croissant.

**Paramètres :**

- `array` : Le tableau d'entiers à trier
- `size` : La taille du tableau

### `int get_max(int *array, size_t size)`

Fonction auxiliaire qui trouve la valeur maximale dans le tableau.

### `void counting_sort_radix(int *array, size_t size, int exp)`

Fonction auxiliaire qui effectue le tri par comptage pour un chiffre spécifique.

## Contraintes

- Fonctionne uniquement avec des entiers positifs (>= 0)
- Utilise l'allocation dynamique de mémoire (`malloc`/`free`)
- Respecte le style de codage Betty
- Aucune variable globale utilisée
- Maximum 5 fonctions par fichier

## Auteur

Projet réalisé dans le cadre du cursus Holberton School.
