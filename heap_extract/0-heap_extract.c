#include "binary_trees.h"

/**
 * heap_extract - Extrait la racine d'un Max Binary Heap.
 * @root: double pointeur vers la racine du tas.
 *
 * Return: valeur extraite, 0 en cas d'échec.
 */
int heap_extract(heap_t **root)
{
	int valeur;
	size_t hauteur, niveau;
	heap_t *dernier = NULL, *gauche, *droite;

	if (!root || !*root)
		return (0);

	valeur = (*root)->n;
	gauche = (*root)->left;
	droite = (*root)->right;

	hauteur = binary_tree_height(*root);

	for (niveau = 0; niveau <= hauteur; niveau++)
		find_replacement(*root, niveau, &dernier);

	free_and_replace(root, &gauche, &droite, &dernier);

	heapify(root, *root);

	return (valeur);
}

/**
 * binary_tree_height - Mesure la hauteur d'un arbre binaire.
 * @root: pointeur vers la racine de l'arbre.
 *
 * Return: hauteur de l'arbre.
 */
size_t binary_tree_height(const heap_t *root)
{
	if (!root)
		return (0);
	return (1 + binary_tree_height(root->left));
}

/**
 * find_replacement - Trouve le dernier nœud selon un parcours en largeur.
 * @root: pointeur vers le nœud actuel.
 * @level: niveau actuel exploré.
 * @last: double pointeur vers le dernier nœud trouvé.
 */
void find_replacement(heap_t *root, size_t level, heap_t **last)
{
	if (!root)
		return;

	if (level == 0)
		*last = root;
	else
	{
		find_replacement(root->left, level - 1, last);
		find_replacement(root->right, level - 1, last);
	}
}

/**
 * free_and_replace - Libère la racine et la remplace par le dernier nœud.
 * @root: double pointeur vers la racine.
 * @left: double pointeur vers l'enfant gauche.
 * @right: double pointeur vers l'enfant droit.
 * @last: double pointeur vers le dernier nœud trouvé.
 */
void free_and_replace(heap_t **root, heap_t **left,
					  heap_t **right, heap_t **last)
{
	if (*last == *root)
	{
		free(*root);
		*root = NULL;
		return;
	}

	if ((*last)->parent->left == *last)
		(*last)->parent->left = NULL;
	else
		(*last)->parent->right = NULL;

	free(*root);
	*root = *last;
	(*last)->parent = NULL;

	if (*left != *last)
	{
		(*last)->left = *left;
		if (*left)
			(*left)->parent = *last;
	}

	if (*right != *last)
	{
		(*last)->right = *right;
		if (*right)
			(*right)->parent = *last;
	}
}

/**
 * heapify - Réarrange le tas pour maintenir la propriété Max Heap.
 * @root: double pointeur vers la racine.
 * @current: pointeur vers le nœud courant.
 */
void heapify(heap_t **root, heap_t *current)
{
	heap_t *max = current, *gauche = current->left, *droite = current->right;

	if (gauche && gauche->n > max->n)
		max = gauche;

	if (droite && droite->n > max->n)
		max = droite;

	if (current != max)
	{
		int tmp = current->n;

		current->n = max->n;
		max->n = tmp;
		heapify(root, max);
	}
}
