#!/usr/bin/python3
"""
Script qui lit des logs depuis stdin et affiche des statistiques toutes
les 10 lignes ou lors d'une interruption clavier (CTRL+C).
"""

import sys
import re
import signal

# Variables globales pour les statistiques
total_size = 0
status_counts = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}
line_count = 0

# Expression régulière pour valider une ligne de log
log_pattern = re.compile(
    r"^\d+\.\d+\.\d+\.\d+ - \[.*?\] \"GET /projects/260 HTTP/1\.1\" (\d+) (\d+)$"
)

def print_stats():
    """
    Affiche les statistiques accumulées :
    - Taille totale des fichiers
    - Nombre de lignes par code HTTP valide
    """
    print(f"File size: {total_size}")
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print(f"{code}: {status_counts[code]}")

def signal_handler(sig, frame):
    """
    Gestionnaire d'interruption clavier (CTRL+C).
    Affiche les statistiques avant de quitter.
    """
    print_stats()
    sys.exit(0)

# Associer le gestionnaire au signal SIGINT
signal.signal(signal.SIGINT, signal_handler)

try:
    for line in sys.stdin:
        line = line.strip()
        match = log_pattern.match(line)

        if match:
            # Extraire le code status et la taille du fichier
            status_code = int(match.group(1))
            file_size = int(match.group(2))

            # Mettre à jour les statistiques globales
            total_size += file_size
            if status_code in status_counts:
                status_counts[status_code] += 1

            line_count += 1

            # Afficher les stats toutes les 10 lignes valides
            if line_count % 10 == 0:
                print_stats()

except KeyboardInterrupt:
    # Gérer l'interruption clavier proprement
    print_stats()
    raise

finally:
    # Afficher les stats finales avant de quitter
    print_stats()
