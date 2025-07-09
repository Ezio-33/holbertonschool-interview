#include "sort.h"

/**
 * get_max - Trouve la valeur maximale dans un tableau
 * @array: Le tableau d'entiers
 * @size: Taille du tableau
 *
 * Return: La valeur maximale
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Effectue le tri par comptage pour un chiffre spécifique
 * @array: Le tableau d'entiers à trier
 * @size: Taille du tableau
 * @exp: L'exposant (1, 10, 100, etc.) pour le chiffre actuel
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	if (!output)
		return;

	/* Compter les occurrences de chaque chiffre */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Changer count[i] pour qu'il contienne la position réelle */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Construire le tableau de sortie */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copier le tableau de sortie dans le tableau original */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Trie un tableau d'entiers en ordre croissant
 *              en utilisant l'algorithme Radix sort LSD
 * @array: Le tableau d'entiers à trier
 * @size: Taille du tableau
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	/* Effectuer le tri par comptage pour chaque chiffre */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_radix(array, size, exp);
		print_array(array, size);
	}
}