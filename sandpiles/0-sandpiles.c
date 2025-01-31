#include "sandpiles.h"
#include <stdio.h>

/**
 * is_unstable - Vérifie si la grille est instable
 * @grid: Grille 3x3 à vérifier
 * Return: 1 si instable, 0 sinon
 */
static int is_unstable(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i][j] > 3)
                return (1);
    return (0);
}

/**
 * print_grid_custom - Affiche la grille selon le format demandé
 * @grid: Grille 3x3 à afficher
 */
static void print_grid_custom(int grid[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * topple - Effectue un effondrement complet de la grille
 * @grid: Grille 3x3 à stabiliser
 */
static void topple(int grid[3][3])
{
    int temp[3][3];

    /* Création d'une copie temporaire de la grille */
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            temp[i][j] = grid[i][j];

    /* Application des règles d'effondrement */
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temp[i][j] > 3)
            {
                grid[i][j] -= 4; // Retire 4 grains
                /* Distribution aux voisins */
                if (i > 0) grid[i-1][j] += 1;
                if (i < 2) grid[i+1][j] += 1;
                if (j > 0) grid[i][j-1] += 1;
                if (j < 2) grid[i][j+1] += 1;
            }
        }
    }
}

/**
 * sandpiles_sum - Effectue l'addition et stabilise la grille
 * @grid1: Première grille (résultat final)
 * @grid2: Deuxième grille à ajouter
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    /* Étape 1: Addition des deux grilles */
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];

    /* Étape 2: Stabilisation itérative */
    while (is_unstable(grid1))
    {
        print_grid_custom(grid1);
        printf("=\n");
        topple(grid1);
    }
}
