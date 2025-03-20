#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "menger.h"

/**
 * isHole - Vérifie si une cellule doit être vide
 * @row: Position de la ligne
 * @col: Position de la colonne
 *
 * Return: 1 si la position doit être un trou, 0 sinon
 */
int isHole(int row, int col)
{
	while (row > 0 || col > 0)
	{
		if (row % 3 == 1 && col % 3 == 1)
		{
			return (1);
		}
		row /= 3;
		col /= 3;
	}
	return (0);
}

/**
 * menger - Dessine une éponge de Menger
 * @level: Niveau de récursion de l'éponge
 *
 * Description: Génère une représentation ASCII d'une éponge de Menger
 * Le niveau 0 est un carré plein. Chaque niveau supérieur subdivise
 * chaque carré en 9 sous-carrés avec le central vide.
 */
void menger(int level)
{
	int size, i, j;

	if (level < 0)
		return;

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (isHole(i, j))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
