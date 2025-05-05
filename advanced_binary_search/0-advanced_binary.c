#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Affiche la partie actuelle du tableau en cours de recherche
 * @array: Pointeur vers le tableau
 * @from: Index de départ
 * @to: Index de fin
 */
void print_array(int *array, int from, int to)
{
	printf("Searching in array: ");
	while (from < to)
	{
		printf("%d, ", array[from]);
		from++;
	}
	printf("%d\n", array[from]);
}

/**
 * recursion_binary - Fonction récursive pour trouver la première occurrence
 * @array: Tableau trié
 * @from: Index gauche (début)
 * @to: Index droit (fin)
 * @value: Valeur à chercher
 *
 * Return: Index de la première occurrence ou -1 si non trouvée
 */
int recursion_binary(int *array, int from, int to, int value)
{
	int mid;

	if (from > to)
		return (-1);

	print_array(array, from, to);

	mid = from + (to - from) / 2;

	if (array[mid] == value)
	{
		if (mid == from || array[mid - 1] != value)
			return (mid);
		/* Cherche plus à gauche */
		return (recursion_binary(array, from, mid - 1, value));
	}
	else if (array[mid] > value)
	{
		return (recursion_binary(array, from, mid - 1, value));
	}
	else
	{
		return (recursion_binary(array, mid + 1, to, value));
	}
}

/**
 * advanced_binary - Recherche avancée utilisant la récursion
 * @array: Tableau trié
 * @size: Taille du tableau
 * @value: Valeur à chercher
 *
 * Return: Index de la première occurrence ou -1 si non trouvée
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursion_binary(array, 0, size - 1, value));
}
