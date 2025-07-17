#!/usr/bin/python3
"""
Module contenant la fonction island_perimeter
"""


def island_perimeter(grid):
    """
    Calcule le périmètre de l'île décrite dans la grille.

    Args:
        grid (list): Liste de listes d'entiers où 0 représente l'eau
                     et 1 représente la terre.

    Returns:
        int: Le périmètre de l'île.

    Description:
        - Chaque cellule de terre (1) contribue potentiellement 4 au périmètre
        - On soustrait 2 pour chaque côté partagé avec une cellule adjacente
        - Les cellules sont connectées horizontalement/verticalement seulement
    """
    if not grid or not grid[0]:
        return 0

    rows = len(grid)
    cols = len(grid[0])
    perimeter = 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # Si c'est de la terre
                # Chaque cellule de terre contribue 4 au périmètre
                perimeter += 4

                # Vérifier la cellule du haut
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Soustraire le côté partagé

                # Vérifier la cellule de gauche
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Soustraire le côté partagé

    return perimeter
