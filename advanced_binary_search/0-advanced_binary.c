#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Affiche le sous-tableau actuellement recherché
 * @array: Le tableau d'entiers
 * @from: Indice de début
 * @to: Indice de fin
 */
void print_array(int *array, int from, int to)
{
	int i;

	printf("Searching in array: ");
	for (i = from; i < to; i++)
		printf("%d, ", array[i]);
	printf("%d\n", array[to]);
}

/**
 * recursion_binary - Recherche binaire récursive pour la première occurrence
 * @array: Le tableau d'entiers
 * @from: Indice de début
 * @to: Indice de fin
 * @value: Valeur à rechercher
 *
 * Return: L'indice de la première occurrence ou -1 si non trouvé
 */
int recursion_binary(int *array, int from, int to, int value)
{
	int mid;

	if (from > to)
		return (-1);

	print_array(array, from, to);

	mid = from + (to - from) / 2;

	/* Si on trouve la valeur et que c'est la première occurrence */
	if (array[mid] == value && (mid == from || array[mid - 1] != value))
		return (mid);

	/* Si la valeur du milieu est supérieure ou égale, on cherche à gauche */
	if (array[mid] >= value)
		return (recursion_binary(array, from, mid, value));

	/* Sinon, on cherche à droite */
	return (recursion_binary(array, mid + 1, to, value));
}

/**
 * advanced_binary - Recherche binaire avancée (première occurrence)
 * @array: Tableau d'entiers trié
 * @size: Taille du tableau
 * @value: Valeur à rechercher
 *
 * Return: L'indice de la première occurrence ou -1 si non trouvé
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || size == 0)
		return (-1);

	return (recursion_binary(array, 0, (int)size - 1, value));
}
