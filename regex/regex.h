#ifndef REGEX_H
#define REGEX_H

/*
 * Fichier: regex.h
 * Description: Prototypes pour le module de vérification de correspondance
 *              d'expressions régulières simplifiées.
 * Règles supportées:
 *   - '.' correspond à n'importe quel caractère unique
 *   - 'c*' correspond à zéro ou plusieurs répétitions du caractère précédent
 *
 * Auteur: Projet Holberton - RegEx (adapté)
 */

/*
 * regex_match - Vérifie si un motif (pattern) correspond à une chaîne.
 * @str:     chaîne à analyser (peut être vide).
 * @pattern: expression régulière (peut être vide). Supporte '.' et '*'.
 *
 * Retour: 1 si le motif correspond à la chaîne, sinon 0.
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
