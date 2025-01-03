#!/usr/bin/python3
def canUnlockAll(boxes):
    """
    Détermine si toutes les boîtes peuvent être déverrouillées
     en partant de la première boîte.

    Args:
        boxes (List[List[int]]): Une liste de boîtes, où
          chaque boîte contient une liste de clés.

    Returns:
        bool: Vrai si toutes les boîtes peuvent être déverrouillées, Faux sinon.
    """
    n = len(boxes)
    opened = [False] * n
    opened[0] = True
    keys = [0]

    while keys:
        current_key = keys.pop()
        for key in boxes[current_key]:
            if key < n and not opened[key]:
                opened[key] = True
                keys.append(key)

    return all(opened)
