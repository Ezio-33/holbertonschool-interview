#!/usr/bin/python3
"""
Ce module fournit une fonction qui pivote une matrice carrée à 90 degrés.
"""


def rotate_2d_matrix(matrix):
    """
    Pivote une matrice carrée de 90 degrés dans le sens horaire en place.

    Args:
        matrix (list of list of int): matrice carrée à pivoter.

    Returns:
        None: modifie directement la matrice donnée en entrée.
    """
    n = len(matrix)

    for i in range(n // 2):
        for j in range(i, n - i - 1):
            tmp = matrix[i][j]

            matrix[i][j] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = tmp
