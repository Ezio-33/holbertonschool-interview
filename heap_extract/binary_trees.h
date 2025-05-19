#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

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
size_t binary_tree_height(heap_t *root);
void find_replacement(heap_t *root, size_t niveau, heap_t **dernier);
void free_and_replace(heap_t **root, heap_t **gauche,
                      heap_t **droite, heap_t **dernier);
void heapify(heap_t **root, heap_t *actuel, int *continuer);

#endif /* BINARY_TREES_H */
