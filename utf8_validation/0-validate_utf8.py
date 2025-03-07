#!/usr/bin/python3
"""
Module pour valider si un ensemble de données représente un encodage UTF-8 valide.
"""

def validUTF8(data):
    """
    Vérifie si une liste d'entiers représente un encodage UTF-8 valide.

    Args:
        data (list): Liste d'entiers représentant les octets.

    Returns:
        bool: True si l'encodage est valide, False sinon.
    """
    num_bytes = 0  # Nombre d'octets restants à vérifier

    # Parcourir chaque entier dans la liste
    for byte in data:
        # Garder uniquement les 8 bits les moins significatifs
        byte = byte & 0xFF

        if num_bytes == 0:
            # Déterminer le nombre d'octets nécessaires selon le premier octet
            if (byte >> 7) == 0:  # 1 byte (0xxxxxxx)
                continue
            elif (byte >> 5) == 0b110:  # 2 bytes (110xxxxx)
                num_bytes = 1
            elif (byte >> 4) == 0b1110:  # 3 bytes (1110xxxx)
                num_bytes = 2
            elif (byte >> 3) == 0b11110:  # 4 bytes (11110xxx)
                num_bytes = 3
            else:
                return False
        else:
            # Vérifier que l'octet suivant respecte le format `10xxxxxx`
            if (byte >> 6) != 0b10:
                return False
            num_bytes -= 1

    # Si tous les caractères ont été validés, num_bytes doit être égal à zéro
    return num_bytes == 0
