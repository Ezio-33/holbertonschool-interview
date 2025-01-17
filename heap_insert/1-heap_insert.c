#include "binary_trees.h"

/**
 * binary_tree_size - Mesure la taille d'un arbre binaire
 * @tree: Pointeur vers la racine de l'arbre à mesurer
 * Return: Taille de l'arbre, 0 si tree est NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * heapify_up - Réorganise le heap de bas en haut
 * @node: Nœud à partir duquel commencer la réorganisation
 */
static void heapify_up(heap_t *node)
{
	int temp;

	while (node->parent && node->n > node->parent->n)
	{
		temp = node->n;
		node->n = node->parent->n;
		node->parent->n = temp;
		node = node->parent;
	}
}

/**
 * heap_insert - Insère une valeur dans un Max Binary Heap
 * @root: Double pointeur vers la racine du heap
 * @value: Valeur à insérer
 * Return: Pointeur vers le nœud inséré, ou NULL en cas d'échec
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	current = *root;
	while (current->left && current->right)
	{
		if (binary_tree_size(current->left) <= binary_tree_size(current->right))
			current = current->left;
		else
			current = current->right;
	}

	if (!current->left)
		current->left = new_node;
	else
		current->right = new_node;

	new_node->parent = current;

	heapify_up(new_node);

	return (new_node);
}
