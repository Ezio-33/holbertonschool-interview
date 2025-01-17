#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Crée un nouveau nœud d'arbre binaire
 * @parent: Pointeur vers le nœud parent
 * @value: Valeur à stocker dans le nouveau nœud
 * Return: Pointeur vers le nouveau nœud, ou NULL en cas d'échec
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *nouveau_noeud;

	nouveau_noeud = malloc(sizeof(binary_tree_t));
	if (nouveau_noeud == NULL)
		return (NULL);

	nouveau_noeud->n = value;
	nouveau_noeud->parent = parent;
	nouveau_noeud->left = NULL;
	nouveau_noeud->right = NULL;

	return (nouveau_noeud);
}
