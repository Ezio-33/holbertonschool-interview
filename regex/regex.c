/*
 * File: regex.c
 * Description: Implementation of a simplified regular expression matcher
 * supporting '.' (any single character) and 'x*' (zero or more of x).
 * Recursive implementation without global variables.
 */

#include <stddef.h>
#include "regex.h"

/**
 * char_match - Check whether str[0] matches the first char of pattern.
 * @str: input string (may be NULL or empty)
 * @pattern: pattern (non NULL), first char is compared to str[0]
 *
 * Return: 1 if the first char matches (or pattern[0] is '.'), else 0.
 */
static int char_match(const char *str, const char *pattern)
{
	if (str == NULL || *str == '\0')
		return (0);

	return (*pattern == '.' || *pattern == *str);
}

/**
 * regex_match - Check whether a pattern matches an entire string.
 * @str: input string (may be empty)
 * @pattern: regex pattern supporting '.' and '*'
 *
 * Return: 1 if the pattern matches the string, otherwise 0.
 */
int regex_match(char const *str, char const *pattern)
{
	/* Gestion des pointeurs NULL (sécurité de base) */
	if (str == NULL || pattern == NULL)
		return (0);

	/* Cas de base: motif vide -> vrai si chaîne vide */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Si le prochain caractère du motif est '*', gérer le quantificateur */
	if (*(pattern + 1) == '*')
	{
		/* Zéro occurrence: ignorer 'x*' et tenter la suite */
		if (regex_match(str, pattern + 2))
			return (1);

		/* Une ou plusieurs occurrences: consommer str tant que ça matche */
		while (*str != '\0' && char_match(str, pattern))
		{
			str++;
			if (regex_match(str, pattern + 2))
				return (1);
		}
		return (0);
	}

	/* Pas d'étoile: un caractère doit matcher, puis avancer les deux */
	if (char_match(str, pattern))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
