#!/usr/bin/python3
"""Script qui lit des logs depuis stdin et affiche des statistiques toutes
les 10 lignes ou lors d'une interruption clavier (CTRL+C).
"""

import sys

# Variables globales
file_size = 0  # Somme totale des tailles de fichiers
status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0}  # Compteur par code HTTP

try:
    # Lecture ligne par ligne depuis stdin
    for i, line in enumerate(sys.stdin, 1):
        # Découper la ligne en mots
        splited = line.split(" ")

        # Vérifier que la ligne est valide (au moins deux éléments)
        if len(splited) < 2:
            continue

        # Mettre à jour le compteur pour le code HTTP si valide
        if splited[-2] in status_codes:
            status_codes[splited[-2]] += 1

        # Ajouter la taille du fichier au total
        try:
            file_size += int(splited[-1])
        except ValueError:
            pass  # Ignorer les erreurs si la taille n'est pas un entier valide

        # Afficher les statistiques toutes les 10 lignes
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for key, value in sorted(status_codes.items()):
                if value > 0:
                    print("{}: {}".format(key, value))

finally:
    # Afficher les statistiques finales avant de quitter
    print("File size: {}".format(file_size))
    for key, value in sorted(status_codes.items()):
        if value > 0:
            print("{}: {}".format(key, value))
