#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - Fusionne deux sous-tableaux d'un tableau principal
 * @array: Le tableau original à trier
 * @tmp: Un tableau temporaire utilisé pour fusionner
 * @left: L’indice de départ du premier sous-tableau
 * @mid: L’indice de départ du second sous-tableau
 * @right: L’indice de fin (non inclus) du second sous-tableau
 */
void merge(int *array, int *tmp, size_t left, size_t mid, size_t right)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
		tmp[k++] = (array[i] < array[j]) ? array[i++] : array[j++];

	while (i < mid)
		tmp[k++] = array[i++];
	while (j < right)
		tmp[k++] = array[j++];

	for (i = left; i < right; i++)
		array[i] = tmp[i];

	printf("[Done]: ");
	print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Trie un tableau de manière récursive
 * @array: Le tableau à trier
 * @tmp: Tableau temporaire
 * @left: L’indice de début du sous-tableau
 * @right: L’indice de fin (non inclus) du sous-tableau
 */
void merge_sort_recursive(int *array, int *tmp, size_t left, size_t right)
{
	size_t mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	merge_sort_recursive(array, tmp, left, mid);
	merge_sort_recursive(array, tmp, mid, right);
	merge(array, tmp, left, mid, right);
}

/**
 * merge_sort - Fonction principale qui lance le tri fusion
 * @array: Le tableau à trier
 * @size: La taille du tableau
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	merge_sort_recursive(array, tmp, 0, size);
	free(tmp);
}
