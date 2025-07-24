#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Structure d'un nœud d'arbre binaire
 *
 * @n: Entier stocké dans le nœud
 * @parent: Pointeur vers le nœud parent
 * @left: Pointeur vers l'enfant gauche
 * @right: Pointeur vers l'enfant droit
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

/* Prototypes des fonctions */
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
int binary_tree_is_avl(const binary_tree_t *tree);

/* Fonctions auxiliaires */
int binary_tree_height(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
