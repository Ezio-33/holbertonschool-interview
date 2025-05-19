#include "binary_trees.h"

/**
 * heap_extract - Extrait la racine d'un Max Binary Heap.
 * @root: double pointeur vers la racine du tas.
 * Return: valeur extraite, 0 en cas d'échec.
 */

int heap_extract(heap_t **root)
{
	int valeur = 0, continuer = 1;
	size_t hauteur = 0, niveau = 0;
	heap_t *gauche = NULL, *droite = NULL, *dernier = NULL;

	if (!root || !*root)
		return (0);

	valeur = (*root)->n;
	gauche = (*root)->left;
	droite = (*root)->right;

	hauteur = binary_tree_height(*root);
	for (niveau = 0; niveau <= hauteur; niveau++)
		find_replacement(*root, niveau, &dernier);

	free_and_replace(root, &gauche, &droite, &dernier);

	while (dernier && continuer)
		heapify(root, dernier, &continuer);

	return (valeur);
}

size_t binary_tree_height(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + binary_tree_height(root->left));
}

void find_replacement(heap_t *root, size_t niveau, heap_t **dernier)
{
	if (!root)
		return;
	if (niveau == 0)
		(*dernier) = root;
	find_replacement(root->left, niveau - 1, dernier);
	find_replacement(root->right, niveau - 1, dernier);
}

void free_and_replace(heap_t **root, heap_t **gauche,
					  heap_t **droite, heap_t **dernier)
{
	if (*dernier == *root)
	{
		free(*root);
		*root = NULL;
		*dernier = NULL;
		return;
	}
	if ((*dernier)->parent->left == (*dernier))
		(*dernier)->parent->left = NULL;
	else if ((*dernier)->parent->right == (*dernier))
		(*dernier)->parent->right = NULL;

	(*dernier)->parent = NULL;
	free(*root);
	*root = *dernier;

	if ((*gauche) != (*dernier))
	{
		(*dernier)->left = (*gauche);
		if (*gauche)
			(*gauche)->parent = (*dernier);
	}
	if ((*droite) != (*dernier))
	{
		(*dernier)->right = (*droite);
		if (*droite)
			(*droite)->parent = (*dernier);
	}
}

void heapify(heap_t **root, heap_t *actuel, int *continuer)
{
	heap_t *max = actuel, *gauche = actuel->left, *droite = actuel->right;

	if (gauche && gauche->n > max->n)
		max = gauche;
	if (droite && droite->n > max->n)
		max = droite;
	if (actuel == max)
	{
		*continuer = 0;
		return;
	}
	max->parent = actuel->parent;
	if (!actuel->parent)
		*root = max;
	else if (actuel->parent->left == actuel)
		actuel->parent->left = max;
	else
		actuel->parent->right = max;

	actuel->left = max->left;
	if (max->left)
		max->left->parent = actuel;
	actuel->right = max->right;
	if (max->right)
		max->right->parent = actuel;

	if (max == gauche)
	{
		max->right = droite;
		if (droite)
			droite->parent = max;
		max->left = actuel;
	}
	else
	{
		max->left = gauche;
		if (gauche)
			gauche->parent = max;
		max->right = actuel;
	}
	actuel->parent = max;
}
