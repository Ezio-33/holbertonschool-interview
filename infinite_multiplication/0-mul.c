#include "holberton.h"

/**
 * is_digit - Vérifie que la chaîne contient uniquement des chiffres
 * @s: chaîne à vérifier
 * Return: 1 si chiffres, 0 sinon
 */
int is_digit(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * allocate_result - alloue la mémoire pour le résultat
 * @size: taille nécessaire
 * Return: pointeur vers la mémoire allouée
 */
char *allocate_result(int size)
{
	char *res;
	int i;

	res = malloc(size + 1);
	if (!res)
		return (NULL);

	for (i = 0; i < size; i++)
		res[i] = '0';
	res[size] = '\0';

	return (res);
}

/**
 * multiply - multiplie deux grands nombres
 * @num1: premier nombre
 * @num2: deuxième nombre
 * Return: chaîne du résultat
 */
char *multiply(char *num1, char *num2)
{
	int l1, l2, i, j, mul, sum, carry;
	char *res;

	for (l1 = 0; num1[l1]; l1++)
		;
	for (l2 = 0; num2[l2]; l2++)
		;

	res = allocate_result(l1 + l2);
	if (!res)
		return (NULL);

	for (i = l1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = l2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0') + carry;
			sum = (res[i + j + 1] - '0') + mul;
			res[i + j + 1] = (sum % 10) + '0';
			carry = sum / 10;
		}
		res[i + j + 1] += carry;
	}

	return (res);
}

/**
 * main - point d'entrée du programme
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 * Return: 0 succès, 98 erreur
 */
int main(int argc, char **argv)
{
	char *res;
	int i = 0;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		_putchar('E'), _putchar('r'), _putchar('r');
		_putchar('o'), _putchar('r'), _putchar('\n');
		exit(98);
	}

	if ((argv[1][0] == '0' && argv[1][1] == '\0') ||
	    (argv[2][0] == '0' && argv[2][1] == '\0'))
	{
		_putchar('0'), _putchar('\n');
		return (0);
	}

	res = multiply(argv[1], argv[2]);
	if (!res)
	{
		_putchar('E'), _putchar('r'), _putchar('r');
		_putchar('o'), _putchar('r'), _putchar('\n');
		exit(98);
	}

	while (res[i] == '0')
		i++;
	for (; res[i]; i++)
		_putchar(res[i]);
	_putchar('\n');

	free(res);
	return (0);
}
