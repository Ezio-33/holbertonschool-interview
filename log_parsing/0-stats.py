#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Script qui lit des logs depuis stdin et affiche des statistiques toutes
les 10 lignes ou lors d'une interruption clavier (CTRL+C).

Format attendu des logs :
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>

Exemple :
127.0.0.1 - [2025-02-13] "GET /projects/260 HTTP/1.1" 200 1024

Statistiques affichées :
- Taille totale des fichiers : File size: <total size>
- Nombre de lignes par code HTTP valide : <status code>: <count>
"""

import sys

# Initialisation des variables globales
file_size = 0  # Somme totale des tailles de fichiers
status_codes = {  # Dictionnaire pour compter les occurrences par code HTTP
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}

try:
    # Lecture ligne par ligne depuis stdin
    for i, line in enumerate(
            sys.stdin, 1):  # i est le numéro de ligne (commence à 1)
        # Divise la ligne en parties séparées par des espaces
        splited = line.split(" ")

        # Validation basique : vérifier que la ligne a au moins deux éléments
        if len(splited) < 2:
            continue

        # Mise à jour du compteur pour le code HTTP si valide
        if splited[-2] in status_codes:  # Avant-dernier élément : code HTTP
            status_codes[splited[-2]] += 1

        # Mise à jour de la taille totale
        try:
            # Dernier élément : taille du fichier
            file_size += int(splited[-1])
        except ValueError:
            continue  # Ignore les lignes où la taille n'est
            # pas un entier valide

        # Affichage des statistiques toutes les 10 lignes valides
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for key, value in sorted(
                    status_codes.items()):  # Trié par clé (code HTTP)
                if value > 0:  # Affiche uniquement les codes rencontrés
                    print("{}: {}".format(key, value))

finally:
    # Affichage final après interruption ou fin d'entrée
    print("File size: {}".format(file_size))
    for key, value in sorted(status_codes.items()):
        if value > 0:
            print("{}: {}".format(key, value))
