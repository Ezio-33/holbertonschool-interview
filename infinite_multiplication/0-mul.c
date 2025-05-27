#include "holberton.h"

/**
 * _strlen - calcule la longueur d'une chaîne.
 * @s: la chaîne.
 *
 * Return: longueur de la chaîne.
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * is_valid_number - vérifie si une chaîne est composée de chiffres.
 * @str: chaîne à vérifier.
 *
 * Return: 1 si valide, 0 sinon.
 */
int is_valid_number(char *str)
{
	if (!str || !*str)
		return (0);

	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * print_number - affiche un nombre (chaîne).
 * @str: chaîne à afficher.
 */
void print_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

/**
 * multiply - multiplie deux grands nombres.
 * @num1: premier nombre.
 * @num2: deuxième nombre.
 *
 * Return: chaîne résultat ou NULL en cas d'erreur.
 */
char *multiply(char *num1, char *num2)
{
	int len1 = _strlen(num1), len2 = _strlen(num2);
	int len_res = len1 + len2, i, j, carry, digit1, digit2;
	int *result = malloc(sizeof(int) * len_res);
	char *final_res;

	if (!result)
		return (NULL);

	for (i = 0; i < len_res; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		digit1 = num1[i] - '0';

		for (j = len2 - 1; j >= 0; j--)
		{
			digit2 = num2[j] - '0';
			carry += result[i + j + 1] + (digit1 * digit2);
			result[i + j + 1] = carry % 10;
			carry /= 10;
		}
		result[i + j + 1] += carry;
	}

	final_res = malloc(len_res + 1);
	if (!final_res)
	{
		free(result);
		return (NULL);
	}

	i = 0, j = 0;
	while (i < len_res && result[i] == 0)
		i++;

	if (i == len_res)
		final_res[j++] = '0';
	else
	{
		while (i < len_res)
			final_res[j++] = result[i++] + '0';
	}

	final_res[j] = '\0';
	free(result);
	return (final_res);
}

/**
 * main - Point d'entrée du programme.
 * @argc: Nombre d'arguments.
 * @argv: Tableau d'arguments.
 *
 * Return: 0 (succès), 98 (erreur).
 */
int main(int argc, char *argv[])
{
	char *res;

	if (argc != 3 || !is_valid_number(argv[1]) || !is_valid_number(argv[2]))
	{
		print_number("Error");
		exit(98);
	}

	res = multiply(argv[1], argv[2]);
	if (!res)
	{
		print_number("Error");
		exit(98);
	}

	print_number(res);
	free(res);
	return (0);
}
