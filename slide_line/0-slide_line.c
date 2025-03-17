#include "slide_line.h"

/**
 * slide_line - Glisse et fusionne une ligne selon les règles du jeu 2048
 * @line: Tableau d'entiers représentant la ligne
 * @size: Taille du tableau
 * @direction: Direction du mouvement (SLIDE_LEFT ou SLIDE_RIGHT)
 *
 * Return: 1 si l'opération est réussie, 0 sinon
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, pos;
    int temp[size];

    /* Initialiser le tableau temporaire à zéro */
    for (i = 0; i < size; i++)
        temp[i] = 0;

    if (direction == SLIDE_LEFT)
    {
        pos = 0;
        for (i = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (temp[pos] == 0)
                    temp[pos] = line[i];
                else if (temp[pos] == line[i])
                {
                    temp[pos] *= 2;
                    pos++;
                }
                else
                    temp[++pos] = line[i];
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        pos = size - 1;
        for (i = size; i-- > 0;)
        {
            if (line[i] != 0)
            {
                if (temp[pos] == 0)
                    temp[pos] = line[i];
                else if (temp[pos] == line[i])
                {
                    temp[pos] *= 2;
                    pos--;
                }
                else
                    temp[--pos] = line[i];
            }
        }
    }
    else
        return (0);

    /* Copier le résultat dans le tableau original */
    for (i = 0; i < size; i++)
        line[i] = temp[i];

    return (1);
}
