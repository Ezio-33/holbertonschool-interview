#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Script qui lit des logs depuis l'entrée standard (stdin)
et affiche des statistiques :
- Taille totale des fichiers
- Nombre de lignes par code HTTP valide
Les statistiques sont affichées toutes les 10 lignes ou lors
d'une interruption clavier (CTRL+C).
"""

import sys

# Variables globales
taille_totale = 0  # Somme totale des tailles de fichiers
codes_status = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0}  # Compteur des codes HTTP valides

try:
    # Lecture ligne par ligne depuis stdin
    for i, ligne in enumerate(sys.stdin, 1):
        # Découper la ligne en mots
        decoupe = ligne.split(" ")

        # Vérifier que la ligne est valide (au moins deux éléments)
        if len(decoupe) < 2:
            continue

        # Mettre à jour le compteur pour le code HTTP si valide
        if decoupe[-2] in codes_status:
            codes_status[decoupe[-2]] += 1

        # Ajouter la taille du fichier au total
        try:
            taille_totale += int(decoupe[-1])
        except ValueError:
            pass  # Ignorer les erreurs si la taille n'est pas un entier valide

        # Afficher les statistiques toutes les 10 lignes
        if i % 10 == 0:
            print("Taille totale: {}".format(taille_totale))
            for code, valeur in sorted(codes_status.items()):
                if valeur > 0:
                    print("{}: {}".format(code, valeur))

finally:
    # Afficher les statistiques finales avant de quitter
    print("Taille totale: {}".format(taille_totale))
    for code, valeur in sorted(codes_status.items()):
        if valeur > 0:
            print("{}: {}".format(code, valeur))
