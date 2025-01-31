#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Affiche une grille 3x3
 * @grid: Grille à afficher
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Vérifie si le tas de sable est stable
 * @grid: Grille 3x3 à vérifier
 *
 * Return: 1 si stable (aucune cellule > 3), 0 sinon
 */
static int is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * topple - Fait basculer les grains de sable des cellules instables
 * @grid: Grille 3x3 à modifier
 */
static void topple(int grid[3][3])
{
    int i, j;
    int temp[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    /* Distribution des grains */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;
                if (i > 0)
                    temp[i - 1][j]++;
                if (i < 2)
                    temp[i + 1][j]++;
                if (j > 0)
                    temp[i][j - 1]++;
                if (j < 2)
                    temp[i][j + 1]++;
            }
        }
    }

    /* Mise à jour de la grille avec les nouvelles valeurs */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid[i][j] += temp[i][j];
        }
    }
}

/**
 * sandpiles_sum - Calcule la somme de deux tas de sable
 * @grid1: Premier tas de sable (contiendra le résultat)
 * @grid2: Deuxième tas de sable
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    /* Addition des deux grilles */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Stabilisation par basculement successif */
    while (!is_stable(grid1))
    {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}
