#ifndef SUBSTRING_H
#define SUBSTRING_H

/*
 * Fonction qui trouve tous les indices de sous-chaînes possibles
 * contenant une liste de mots dans une chaîne donnée
 *
 * @s: la chaîne à scanner
 * @words: le tableau de mots dont toutes les sous-chaînes doivent être
 *         une concaténation arrangée
 * @nb_words: le nombre d'éléments dans le tableau words
 * @n: adresse où stocker le nombre d'éléments dans le tableau retourné
 *
 * Return: un tableau alloué, stockant chaque index dans s où une
 *         sous-chaîne a été trouvée. Si aucune solution n'est trouvée,
 *         NULL peut être retourné
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n);

#endif /* SUBSTRING_H */
