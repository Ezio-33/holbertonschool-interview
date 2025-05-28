#include "holberton.h"

/**
 * is_digit - vérifie si une chaîne contient uniquement des chiffres
 * @str: chaîne à vérifier
 *
 * Return: 1 si chiffres uniquement, sinon 0
 */
int is_digit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

/**
 * calloc_result - alloue mémoire initialisée à '0'
 * @size: taille à allouer
 *
 * Return: pointeur vers la mémoire ou NULL
 */
char *calloc_result(int size)
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
 * multiply - multiplie deux nombres sous forme de chaînes
 * @n1: premier nombre
 * @n2: deuxième nombre
 *
 * Return: résultat sous forme de chaîne
 */
char *multiply(char *n1, char *n2)
{
	int len1, len2, len_res, i, j, mul, sum, carry;
	char *res;

	for (len1 = 0; n1[len1]; len1++)
		;
	for (len2 = 0; n2[len2]; len2++)
		;
	len_res = len1 + len2;
	res = calloc_result(len_res);
	if (!res)
		return (NULL);
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (n1[i] - '0') * (n2[j] - '0');
			sum = (res[i + j + 1] - '0') + mul + carry;
			res[i + j + 1] = (sum % 10) + '0';
			carry = sum / 10;
		}
		res[i + j + 1] += carry;
	}
	return (res);
}

/**
 * print_number - affiche une chaîne sans les zéros inutiles
 * @num: nombre à afficher
 */
void print_number(char *num)
{
	int i = 0;

	while (num[i] == '0' && num[i + 1])
		i++;
	for (; num[i]; i++)
		_putchar(num[i]);
	_putchar('\n');
}

/**
 * main - multiplie deux grands nombres
 * @argc: nombre d'arguments
 * @argv: tableau d'arguments
 *
 * Return: 0 succès, 98 erreur
 */
int main(int argc, char **argv)
{
	char *res;

	if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
	{
		print_error();
		exit(98);
	}
	if ((argv[1][0] == '0' && !argv[1][1]) ||
	    (argv[2][0] == '0' && !argv[2][1]))
	{
		_putchar('0'), _putchar('\n');
		return (0);
	}
	res = multiply(argv[1], argv[2]);
	if (!res)
	{
		print_error();
		exit(98);
	}
	print_number(res);
	free(res);
	return (0);
}
