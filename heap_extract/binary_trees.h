#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdlib.h>

/**
 * struct binary_tree_s - Nœud d'un arbre binaire.
 * @n: Valeur entière stockée dans le nœud.
 * @parent: Pointeur vers le nœud parent.
 * @left: Pointeur vers l'enfant gauche.
 * @right: Pointeur vers l'enfant droit.
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

int heap_extract(heap_t **root);
size_t binary_tree_height(const heap_t *root);
void find_replacement(heap_t *root, size_t level, heap_t **last);
void free_and_replace(heap_t **root, heap_t **left,
					  heap_t **right, heap_t **last);
void heapify(heap_t **root, heap_t *current);

#endif /* BINARY_TREES_H */
