#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Affiche un tableau d'entiers
 *
 * @array: Le tableau à afficher
 * @size: Nombre d'éléments dans @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
