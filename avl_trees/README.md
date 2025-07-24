# Projet AVL Trees

## Description

Ce projet implémente une fonction pour vérifier si un arbre binaire est un arbre AVL valide.

## Qu'est-ce qu'un arbre AVL ?

Un arbre AVL (Adelson-Velsky et Landis) est un arbre binaire de recherche auto-équilibrant où :

1. **Propriété BST** : Pour chaque nœud, toutes les valeurs du sous-arbre gauche sont inférieures à la valeur du nœud, et toutes les valeurs du sous-arbre droit sont supérieures.

2. **Propriété d'équilibre** : Pour chaque nœud, la différence de hauteur entre les sous-arbres gauche et droit ne peut jamais dépasser 1.

3. **Récursivité** : Chaque sous-arbre doit également être un arbre AVL valide.

## Fichiers du projet

- `binary_trees.h` : Fichier d'en-tête contenant les structures et prototypes
- `0-binary_tree_is_avl.c` : Implémentation principale de la fonction de vérification AVL
- `binary_tree_node.c` : Fonction pour créer de nouveaux nœuds
- `binary_tree_print.c` : Fonction pour afficher l'arbre (fournie pour les tests)
- `0-main.c` : Fichier de test principal
- `Makefile` : Fichier d'automatisation pour la compilation

## Compilation et utilisation

### Méthode 1 : Avec le Makefile (recommandé)

Le projet inclut un Makefile pour simplifier la compilation et l'exécution :

```bash
# Compiler le projet
make

# Ou compiler et exécuter directement
make test

# Nettoyer les fichiers générés
make clean
```

**Structure du Makefile :**

- `CC = gcc` : Spécifie le compilateur
- `CFLAGS = -Wall -Wextra -Werror -pedantic` : Options de compilation strictes
- `NAME = 0-is_avl` : Nom de l'exécutable généré
- `SOURCES = ...` : Liste des fichiers source à compiler

**Commandes disponibles :**

- `make` ou `make all` : Compile tous les fichiers sources
- `make test` : Compile puis exécute automatiquement le programme
- `make clean` : Supprime l'exécutable généré

### Méthode 2 : Compilation manuelle

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 0-main.c 0-binary_tree_is_avl.c -L. -lavl -o 0-is_avl
```

### Exécution

```bash
./0-is_avl
```

## Fonctionnement de l'algorithme

La fonction `binary_tree_is_avl` vérifie trois conditions :

1. **Vérification BST** : Utilise une fonction auxiliaire récursive pour s'assurer que l'arbre respecte les propriétés d'un arbre binaire de recherche.

2. **Calcul du facteur d'équilibre** : Pour chaque nœud, calcule la différence de hauteur entre les sous-arbres gauche et droit.

3. **Vérification récursive** : S'assure que tous les sous-arbres sont également des arbres AVL valides.
