#include "regex.h"
#include <stddef.h>

/*
 * Correspondance d'expression régulière simplifiée
 * - '.' : n'importe quel caractère unique
 * - 'x*': zéro ou plusieurs occurrences du caractère précédent 'x'
 *
 * Implémentation récursive sans variables globales, conforme Betty.
 */

/*
 * char_match - indique si le premier char de str correspond au premier de pattern
 *              en tenant compte de '.' comme joker.
 * @str: chaîne d'entrée (peut être NULL ou vide)
 * @pattern: motif (non NULL)
 * Return: 1 si correspondance du premier caractère, 0 sinon
 */
static int char_match(const char *str, const char *pattern)
{
	if (!*str)
		return (0);
	return (*pattern == '.' || *pattern == *str);
}

/*
 * regex_match - Vérifie si un motif correspond à une chaîne.
 * @str: chaîne à analyser
 * @pattern: motif (supporte '.' et '*')
 * Return: 1 si correspond, 0 sinon
 */
int regex_match(char const *str, char const *pattern)
{
	/* Cas de base: motif vide -> correspond si chaîne vide */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Gestion du quantificateur '*' appliqué au caractère courant du motif */
	if (*(pattern + 1) == '*')
	{
		/* Essayer zéro occurrence: avancer le motif de 2 */
		if (regex_match(str, pattern + 2))
			return (1);
		/* Essayer >= 1 occurrence tant que le premier caractère correspond */
		while (*str && char_match(str, pattern))
		{
			str++;
			if (regex_match(str, pattern + 2))
				return (1);
		}
		return (0);
	}

	/* Pas d'étoile: un seul caractère doit correspondre puis avancer les deux */
	if (char_match(str, pattern))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
