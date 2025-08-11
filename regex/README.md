RegEx - Projet Holberton (simplifié)

Ce projet fournit une fonction `regex_match(const char *str, const char *pattern)` qui vérifie la correspondance d'une chaîne avec une expression régulière simplifiée supportant `.` et `*`.

Compilation recommandée (Ubuntu 14.04, gcc 4.8.4):

- Flags: `-Wall -Werror -Wextra -pedantic`
- Exemple: `gcc -Wall -Wextra -Werror -pedantic main.c regex.c -o regex`

Règles supportées:

- `.` correspond à n'importe quel caractère unique
- `c*` correspond à zéro ou plusieurs répétitions du caractère `c`

Notes:

- Pas de variables globales
- Pas plus de 5 fonctions par fichier
- En-tête: `regex.h`
- Style: Betty
