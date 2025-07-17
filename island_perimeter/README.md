# Island Perimeter

## Description

Ce projet contient une fonction qui calcule le périmètre d'une île décrite dans une grille 2D.

## Fonctionnalité

- `island_perimeter(grid)`: Retourne le périmètre de l'île dans la grille
  - `grid` est une liste de listes d'entiers
  - `0` représente l'eau
  - `1` représente la terre
  - Chaque cellule est carrée avec une longueur de côté de 1
  - Les cellules sont connectées horizontalement/verticalement (pas en diagonal)
  - La grille est rectangulaire, avec une largeur et hauteur ne dépassant pas 100
  - La grille est complètement entourée d'eau
  - Il n'y a qu'une seule île (ou rien)
  - L'île n'a pas de "lacs" (eau à l'intérieur qui n'est pas connectée à l'eau entourant l'île)

## Usage

```python
from 0-island_perimeter import island_perimeter

grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
print(island_perimeter(grid))  # Output: 12
```

## Fichiers

- `0-island_perimeter.py`: Contient la fonction principale
- `0-main.py`: Fichier de test
