#!/usr/bin/python3

"""
Script qui lit des logs depuis l'entrée standard (stdin)
et affiche des statistiques :
- Taille totale des fichiers
- Nombre de lignes par code HTTP valide
Les statistiques sont affichées toutes les 10 lignes ou
lors d'une interruption clavier (CTRL+C).
"""

import sys


file_size = 0
status_codes = {"200": 0, "301": 0, "400": 0, "401": 0,
                "403": 0, "404": 0, "405": 0, "500": 0}

try:
    for i, line in enumerate(sys.stdin, 1):
        splited = line.split(" ")
        if len(splited) < 2:
            continue
        if splited[-2] in status_codes:
            status_codes[splited[-2]] += 1
        file_size += eval(splited[-1])
        if i % 10 == 0:
            print("File size: {}".format(file_size))
            for key, value in sorted(status_codes.items()):
                if value > 0:
                    print("{}: {}".format(key, value))
finally:
    print("File size: {}".format(file_size))
    for key, value in sorted(status_codes.items()):
        if value > 0:
            print("{}: {}".format(key, value))
