#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Script qui lit des logs depuis l'entrée standard (stdin)
et affiche des statistiques :
- Taille totale des fichiers
- Nombre de lignes par code HTTP valide
Les statistiques sont affichées toutes les 10 lignes ou
lors d'une interruption clavier (CTRL+C).
"""
import sys

taille_fichier = 0
codes_statut = {"200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i, ligne in enumerate(sys.stdin, 1):
        splited = ligne.split(" ")
        if len(splited) < 2:
            continue
        if splited[-2] in codes_statut:
            codes_statut[splited[-2]] += 1
        taille_fichier += eval(splited[-1])
        if i % 10 == 0:
            print("Taille du fichier: {}".format(taille_fichier))
            for cle, valeur in sorted(codes_statut.items()):
                if valeur > 0:
                    print("{}: {}".format(cle, valeur))
finally:
    print("Taille du fichier: {}".format(taille_fichier))
    for cle, valeur in sorted(codes_statut.items()):
        if valeur > 0:
            print("{}: {}".format(cle, valeur))
