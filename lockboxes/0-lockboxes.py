#!/usr/bin/python3
"""
Module 0-lockboxes.

Contient une fonction pour déterminer si toutes les boîtes
peuvent être déverrouillées en partant de la première boîte.
"""


def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être déverrouillées
    en partant de la première boîte.

    Args:
        boxes (List[List[int]]): Une liste de boîtes, où
                                 chaque boîte contient une liste de clés.

    Returns:
        bool: Vrai si toutes les boîtes peuvent être déverrouillées,
              Faux sinon.
    """
    n = len(boxes)
    if n == 0:
        return False

    opened = [False] * n
    opened[0] = True  
    keys = [0]

    while keys:
        current_key = keys.pop()
        for key in boxes[current_key]:
            if 0 <= key < n and not opened[key]:
                opened[key] = True
                keys.append(key)

    return all(opened)