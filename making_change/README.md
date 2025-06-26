````markdown
# Projet: Rendre la monnaie

Ce projet fait partie de mon apprentissage en algorithmique dans le cadre de ma formation. L'objectif est de résoudre un problème classique de programmation dynamique: déterminer le nombre minimal de pièces nécessaires pour atteindre un montant donné.

## Description du projet

Le problème consiste à trouver le nombre minimal de pièces nécessaires pour faire un certain montant total, étant donné une liste de valeurs de pièces disponibles. Si le montant ne peut pas être atteint avec les pièces données, on doit retourner -1.

## Complexité

La complexité temporelle de cette solution est O(total \* n), où `n` est le nombre de types de pièces. Cela est dû aux deux boucles imbriquées : une pour chaque montant jusqu'à `total`, et une pour chaque type de pièce.

Cette approche est efficace pour des valeurs de `total` raisonnables, mais pourrait devenir lente pour de très grands montants.

```

```
````
