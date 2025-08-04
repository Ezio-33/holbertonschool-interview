# Pascal's Triangle

## Description

Ce projet implémente une fonction qui génère le triangle de Pascal en Python.

Le triangle de Pascal est une disposition triangulaire de nombres où :

- Chaque ligne commence et se termine par 1
- Chaque autre nombre est la somme des deux nombres directement au-dessus de lui

## Fichiers

### `0-pascal_triangle.py`

Contient la fonction principale `pascal_triangle(n)` qui :

- Prend un entier `n` en paramètre
- Retourne une liste de listes représentant le triangle de Pascal avec `n` lignes
- Retourne une liste vide si `n <= 0`

### `0-main.py`

Fichier de test principal fourni dans les spécifications du projet.

## Exemple de sortie

```
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
```

## Algorithme

La fonction utilise une approche itérative :

1. Vérifie si `n <= 0` et retourne une liste vide le cas échéant
2. Initialise le triangle avec la première ligne `[1]`
3. Pour chaque ligne suivante :
   - Commence par 1
   - Calcule chaque élément intermédiaire comme la somme des deux éléments au-dessus
   - Termine par 1
   - Ajoute la ligne au triangle

## Complexité

- Temps : O(n²) - nous devons calculer n(n+1)/2 éléments
- Espace : O(n²) - pour stocker tous les éléments du triangle
