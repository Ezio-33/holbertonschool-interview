#ifndef REGEX_H
#define REGEX_H

/*
 * File: regex.h
 * Desc: Déclarations pour la fonction de correspondance d'expressions
 *       régulières simplifiées (support '.' et '*').
 */

/**
 * regex_match - Vérifie la correspondance d'une chaîne avec un motif.
 * @str: chaîne à analyser (peut être vide).
 * @pattern: motif supportant '.' et '*'.
 *
 * Return: 1 si le motif correspond à la chaîne, sinon 0.
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
