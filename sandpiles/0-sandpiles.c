#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Affiche une grille 3x3
 * @grid: Grille 3x3 à afficher
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_unstable - Vérifie si la grille est instable (au moins une cellule > 3)
 * @grid: Grille 3x3 à vérifier
 *
 * Return: 1 si instable, 0 sinon
 */
static int is_unstable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (1);
        }
    }
    return (0);
}

/**
 * topple - Effectue l'effondrement pour toutes les cellules > 3
 * @grid: Grille 3x3 à modifier
 */
static void topple(int grid[3][3])
{
    int i, j;
    int temp[3][3];

    /* Copie de la grille avant de redistribuer */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            temp[i][j] = grid[i][j];
    }

    /* Pour chaque cellule, si > 3, on retire 4 et on distribue aux voisins */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (temp[i][j] > 3)
            {
                grid[i][j] -= 4;
                if (i > 0)
                    grid[i - 1][j] += 1;
                if (i < 2)
                    grid[i + 1][j] += 1;
                if (j > 0)
                    grid[i][j - 1] += 1;
                if (j < 2)
                    grid[i][j + 1] += 1;
            }
        }
    }
}

/**
 * sandpiles_sum - Calcule la somme de deux grilles de sable et stabilise le résultat
 * @grid1: Première grille (et celle qui stocke le résultat final)
 * @grid2: Deuxième grille à additionner
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    /* 1. Addition des deux grilles */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* 2. Tant que la grille est instable, on l’affiche puis on la fait “toppler” */
    while (is_unstable(grid1))
    {
        print_grid(grid1);
        printf("=\n");
        topple(grid1);
    }
}
