#include <stdio.h>
#include "search_algos.h"

/**
 * print_array - Affiche le tableau ou sous-tableau
 * @array: le tableau
 * @left: index de début
 * @right: index de fin
 */
void print_array(int *array, size_t left, size_t right)
{
    printf("Searching in array: ");
    for (size_t i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i != right)
            printf(", ");
    }
    printf("\n");
}

/**
 * recursive_search - Fonction récursive qui trouve la première occurrence
 * @array: le tableau
 * @left: index de début
 * @right: index de fin
 * @value: valeur recherchée
 * Return: index ou -1
 */
int recursive_search(int *array, size_t left, size_t right, int value)
{
    if (left > right)
        return -1;

    print_array(array, left, right);

    size_t mid = left + (right - left) / 2;

    if (array[mid] == value)
    {
        if (mid == left || array[mid - 1] != value)
            return mid;
        return recursive_search(array, left, mid, value);
    }

    if (array[mid] >= value)
        return recursive_search(array, left, mid - 1, value);
    else
        return recursive_search(array, mid + 1, right, value);
}

/**
 * advanced_binary - Interface de recherche avancée
 * @array: tableau trié
 * @size: taille du tableau
 * @value: valeur à chercher
 * Return: index ou -1
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return recursive_search(array, 0, size - 1, value);
}
