#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Affiche le sous-tableau en cours de recherche
 * @array: tableau d'entiers
 * @start: indice de début
 * @end: indice de fin
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * advanced_binary_rec - Recherche binaire récursive pour la première occurrence
 * @array: tableau d'entiers
 * @start: indice de début
 * @end: indice de fin
 * @value: valeur à rechercher
 * Retourne: l'indice de la première occurrence ou -1
 */
int advanced_binary_rec(int *array, size_t start, size_t end, int value)
{
	size_t mid;

	if (start > end)
		return (-1);

	print_array(array, start, end);

	mid = start + (end - start) / 2;

	if (array[mid] == value)
	{
		if (mid == start || array[mid - 1] != value)
			return ((int)mid);
		return (advanced_binary_rec(array, start, mid, value));
	}
	else if (array[mid] > value)
	{
		if (mid == 0)
			return (-1);
		return (advanced_binary_rec(array, start, mid - 1, value));
	}
	else
	{
		return (advanced_binary_rec(array, mid + 1, end, value));
	}
}

/**
 * advanced_binary - Recherche binaire avancée (première occurrence)
 * @array: tableau d'entiers trié
 * @size: taille du tableau
 * @value: valeur à rechercher
 * Retourne: l'indice de la première occurrence ou -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);
	return (advanced_binary_rec(array, 0, size - 1, value));
}
