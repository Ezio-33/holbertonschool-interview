#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - Affiche la grille 3x3
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
 * is_unstable - Détermine si la grille est instable (valeurs > 3)
 * @grid: Grille 3x3 à vérifier
 * Return: 1 si la grille est instable, 0 sinon
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
 * topple - Effectue un effondrement de la grille pour toutes les cellules > 3
 * @grid: Grille 3x3 à modifier
 */
static void topple(int grid[3][3])
{
    int i, j;
    int temp[3][3];

    /* Copie temporaire pour éviter de modifier la grille en direct */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            temp[i][j] = grid[i][j];
    }

    /* Pour chaque cellule > 3, on redistribue 4 grains aux voisins */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (temp[i][j] > 3)
            {
                grid[i][j] -= 4;
                if (i - 1 >= 0)
                    grid[i - 1][j] += 1;
                if (i + 1 < 3)
                    grid[i + 1][j] += 1;
                if (j - 1 >= 0)
                    grid[i][j - 1] += 1;
                if (j + 1 < 3)
                    grid[i][j + 1] += 1;
            }
        }
    }
}

/**
 * sandpiles_sum - Calcule la somme de deux grilles de sable et stabilise
 * @grid1: Première grille (résultat)
 * @grid2: Deuxième grille
 *
 * Additionne grid2 dans grid1 puis effectue les effondrements
 * successifs jusqu'à obtenir une grille stable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    /* 1. Addition des deux grilles */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];
    }

    /* 2. Stabilisation par effondrement successif */
    while (is_unstable(grid1))
    {
        /* Affichage de la grille avant chaque effondrement */
        print_grid(grid1);
        printf("=\n");
        topple(grid1);
    }
}
