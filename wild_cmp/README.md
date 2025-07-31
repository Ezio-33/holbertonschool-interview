# Wild Compare

Ce projet implémente une fonction qui compare deux chaînes de caractères avec support des caractères génériques.

## Description

La fonction `wildcmp` compare deux chaînes de caractères et retourne 1 si les chaînes peuvent être considérées comme identiques, sinon retourne 0. La seconde chaîne peut contenir le caractère spécial `*` qui peut remplacer n'importe quelle chaîne (y compris une chaîne vide).

## Prototype de la fonction

```c
int wildcmp(char *s1, char *s2);
```

## Paramètres

- `s1`: La première chaîne à comparer
- `s2`: La seconde chaîne à comparer (peut contenir des caractères génériques)

## Valeur de retour

- `1` si les chaînes correspondent (en tenant compte des caractères génériques)
- `0` si les chaînes ne correspondent pas

## Exemples

```c
wildcmp("main.c", "*.c") → 1
wildcmp("main.c", "m*a*i*n*.*c*") → 1
wildcmp("main.c", "main.c") → 1
wildcmp("main.c", "m*c") → 1
wildcmp("main.c", "*") → 1
wildcmp("main.c", "m.*c") → 0
```

## Compilation

```bash
gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-wildcmp.c -o 0-wildcmp
```

## Auteur

Samuel verschueren
