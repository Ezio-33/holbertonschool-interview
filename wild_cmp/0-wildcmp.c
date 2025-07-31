#include "holberton.h"

/**
 * wildcmp - compare deux chaînes avec support des caractères génériques
 * @s1: première chaîne
 * @s2: seconde chaîne (peut contenir des caractères génériques)
 *
 * Description: Cette fonction compare deux chaînes et retourne 1 si elles
 * peuvent être considérées comme identiques, sinon retourne 0. La seconde
 * chaîne peut contenir le caractère spécial '*' qui peut remplacer
 * n'importe quelle chaîne (y compris une chaîne vide).
 *
 * Return: 1 si les chaînes correspondent, 0 sinon
 */
int wildcmp(char *s1, char *s2)
{
	/* Si les deux chaînes sont vides, elles correspondent */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	/* Si s2 est '*', il peut correspondre à toute partie restante de s1 */
	if (*s2 == '*')
	{
		/* Ignorer les astérisques consécutifs */
		if (*(s2 + 1) == '*')
			return (wildcmp(s1, s2 + 1));

		/* Si '*' est à la fin de s2, il correspond à tout dans s1 */
		if (*(s2 + 1) == '\0')
			return (1);

		/* Essayer de correspondre '*' avec chaîne vide ou caractères */
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	/* Si s1 est vide mais s2 ne l'est pas (et s2 n'est pas '*') */
	if (*s1 == '\0')
		return (0);

	/* Si les caractères actuels correspondent, continuer */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Les caractères ne correspondent pas et s2 n'est pas '*' */
	return (0);
}
