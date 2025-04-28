#include "sort.h"

/**
 * swap - Échange deux entiers
 * @a: Premier entier
 * @b: Deuxième entier
 */
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * heapify - Maintient la propriété de tas max
 * @array: Tableau à trier
 * @heap_size: Taille actuelle du tas
 * @root: Indice de la racine
 * @original_size: Taille originale pour l'affichage
 */
void heapify(int *array, size_t heap_size, size_t root, size_t original_size) {
    size_t largest = root;
    size_t left = 2 * root + 1;
    size_t right = 2 * root + 2;

    if (left < heap_size && array[left] > array[largest])
        largest = left;

    if (right < heap_size && array[right] > array[largest])
        largest = right;

    if (largest != root) {
        swap(&array[root], &array[largest]);
        print_array(array, original_size);
        heapify(array, heap_size, largest, original_size);
    }
}

/**
 * heap_sort - Trie un tableau avec l'algorithme de tri par tas
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void heap_sort(int *array, size_t size) {
    ssize_t i;

    if (!array || size < 2)
        return;

    /* Construction du tas max */
    for (i = (size / 2) - 1; i >= 0; i--)
        heapify(array, size, (size_t)i, size);

    /* Extraction des éléments */
    for (i = size - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        print_array(array, size);
        heapify(array, (size_t)i, 0, size);
    }
}
