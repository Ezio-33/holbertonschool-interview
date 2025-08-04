#!/usr/bin/python3
"""
Module pour générer le triangle de Pascal
Ce module contient une fonction qui retourne une liste de listes
représentant le triangle de Pascal pour un nombre donné de lignes.
"""


def pascal_triangle(n):
    """
    Génère le triangle de Pascal avec n lignes

    Le triangle de Pascal est une disposition triangulaire de nombres
    où chaque nombre est la somme des deux nombres directement
    au-dessus de lui.

    Args:
        n (int): Le nombre de lignes du triangle à générer

    Returns:
        list: Une liste de listes d'entiers représentant le triangle de Pascal.
              Retourne une liste vide si n <= 0

    Exemple:
        >>> pascal_triangle(5)
        [[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]
    """
    # Si n est inférieur ou égal à 0, retourner une liste vide
    if n <= 0:
        return []

    # Initialiser le triangle avec la première ligne
    triangle = [[1]]

    # Générer chaque ligne du triangle
    for i in range(1, n):
        # Commencer chaque ligne avec 1
        row = [1]

        # Calculer les valeurs intermédiaires de la ligne
        # Chaque élément est la somme des deux éléments au-dessus
        for j in range(1, i):
            # Somme de l'élément à gauche et à droite de la ligne précédente
            value = triangle[i - 1][j - 1] + triangle[i - 1][j]
            row.append(value)

        # Terminer chaque ligne avec 1 (sauf la première ligne)
        row.append(1)

        # Ajouter la ligne complète au triangle
        triangle.append(row)

    return triangle
