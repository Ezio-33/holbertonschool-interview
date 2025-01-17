#include "binary_trees.h"

/**
 * binary_tree_size - Calcule la taille d'un arbre binaire
 * @tree: Pointeur vers la racine
 * Return: Taille de l'arbre
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);
    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_up - Réorganise le heap de bas en haut
 * @node: Nœud à partir duquel réorganiser
 */
void heapify_up(heap_t *node)
{
    heap_t *current = node;
    int temp;

    while (current->parent && current->n > current->parent->n)
    {
        temp = current->n;
        current->n = current->parent->n;
        current->parent->n = temp;
        current = current->parent;
    }
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud créé, NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *nouveau_noeud, *parent;
    size_t size, i;
    unsigned int mask;

    if (root == NULL)
        return (NULL);

    /* Si l'arbre est vide */
    if (*root == NULL)
        return (*root = binary_tree_node(NULL, value));

    /* Calcul de la taille et recherche de la position */
    size = binary_tree_size(*root);
    parent = *root;
    
    /* Trouve la position du prochain nœud */
    for (i = 1, mask = 1 << ((sizeof(size_t) * 8) - 1);
         !(mask & size); mask >>= 1)
        ;
    mask >>= 1;

    /* Parcours jusqu'à la position d'insertion */
    while (mask > 1)
    {
        if (size & mask)
            parent = parent->right;
        else
            parent = parent->left;
        mask >>= 1;
    }

    /* Création et insertion du nouveau nœud */
    nouveau_noeud = binary_tree_node(parent, value);
    if (nouveau_noeud == NULL)
        return (NULL);

    if (size & 1)
        parent->right = nouveau_noeud;
    else
        parent->left = nouveau_noeud;

    /* Réorganisation du heap */
    heapify_up(nouveau_noeud);
    
    return (nouveau_noeud);
}
