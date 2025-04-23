#!/usr/bin/python3
"""
Module pour calculer la quantité d'eau de pluie retenue entre les murs.
"""

def rain(walls):
    """
    Calcule la quantité d'eau retenue après la pluie entre les murs.

    Args:
        walls (list): Liste des hauteurs des murs.

    Returns:
        int: Quantité totale d'eau retenue.
    """
    if not walls:
        return 0
    
    gauche = 0
    droite = len(walls) - 1
    max_gauche = 0
    max_droite = 0
    total = 0
    
    while gauche <= droite:
        if walls[gauche] <= walls[droite]:
            if walls[gauche] >= max_gauche:
                max_gauche = walls[gauche]
            else:
                total += max_gauche - walls[gauche]
            gauche += 1
        else:
            if walls[droite] >= max_droite:
                max_droite = walls[droite]
            else:
                total += max_droite - walls[droite]
            droite -= 1
    
    return total
