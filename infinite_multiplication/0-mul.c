#include "holberton.h"

/**
 * _isnumber - Vérifie si une chaîne contient uniquement des chiffres
 * @s: chaîne à vérifier
 * Return: 1 si chiffres uniquement, sinon 0
 */
int _isnumber(char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * _callocX - alloue une chaîne initialisée avec des '0'
 * @nmemb: nombre d'éléments à allouer
 * Return: pointeur vers la mémoire ou NULL
 */
char *_callocX(unsigned int nmemb)
{
	unsigned int i;
	char *p;

	p = malloc(nmemb + 1);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < nmemb; i++)
		p[i] = '0';
	p[nmemb] = '\0';

	return (p);
}

/**
 * main - multiplie deux nombres infinis
 * @argc: nombre d'arguments
 * @argv: tableau des arguments
 * Return: toujours 0 ou 98 si erreur
 */
int main(int argc, char **argv)
{
	int i, j, l1, l2, len, mul, add, carry_mul, carry_add, pos, zero = 0;
	char *res;

	if (argc != 3 || !_isnumber(argv[1]) || !_isnumber(argv[2]))
	{
		write(1, "Error\n", 6), exit(98);
	}
	if (argv[1][0] == '0' || argv[2][0] == '0')
	{
		write(1, "0\n", 2), exit(0);
	}
	for (l1 = 0; argv[1][l1]; l1++)
		;
	for (l2 = 0; argv[2][l2]; l2++)
		;
	len = l1 + l2;
	res = _callocX(len);
	if (res == NULL)
		write(1, "Error\n", 6), exit(98);
	for (i = l2 - 1; i >= 0; i--)
	{
		carry_mul = 0, carry_add = 0;
		for (j = l1 - 1; j >= 0; j--)
		{
			pos = i + j + 1;
			mul = (argv[1][j] - '0') * (argv[2][i] - '0') + carry_mul;
			carry_mul = mul / 10;
			add = (res[pos] - '0') + (mul % 10) + carry_add;
			carry_add = add / 10;
			res[pos] = (add % 10) + '0';
		}
		res[pos - 1] = ((res[pos - 1] - '0') + carry_mul + carry_add) + '0';
	}
	if (res[0] == '0')
		zero = 1;
	for (; zero < len; zero++)
		_putchar(res[zero]);
	_putchar('\n');
	free(res);
	return (0);
}
