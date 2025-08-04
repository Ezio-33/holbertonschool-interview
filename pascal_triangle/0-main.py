#!/usr/bin/python3
"""
0-main
Fichier de test pour la fonction pascal_triangle
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle


def print_triangle(triangle):
    """
    Affiche le triangle de Pascal de manière formatée

    Args:
        triangle (list): Liste de listes représentant le triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))
