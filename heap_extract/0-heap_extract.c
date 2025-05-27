#include "binary_trees.h"

/**
 * swap - échange les valeurs de deux entiers.
 * @a: premier entier.
 * @b: second entier.
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * heapify - reconstruit le tas binaire max depuis un nœud donné.
 * @root: pointeur vers le nœud racine actuel.
 */
void heapify(heap_t *root)
{
	heap_t *largest = root, *left = root->left, *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;

	if (largest != root)
	{
		swap(&root->n, &largest->n);
		heapify(largest);
	}
}

/**
 * get_last_node - trouve le dernier nœud dans l'ordre en largeur.
 * @root: racine du tas.
 *
 * Return: pointeur vers le dernier nœud trouvé.
 */
heap_t *get_last_node(heap_t *root)
{
	heap_t *queue[10000];
	int front = 0, rear = 0;
	heap_t *last = NULL;

	queue[rear++] = root;
	while (front < rear)
	{
		last = queue[front++];
		if (last->left)
			queue[rear++] = last->left;
		if (last->right)
			queue[rear++] = last->right;
	}

	return (last);
}

/**
 * heap_extract - extrait la racine du tas max et reconstruit le tas.
 * @root: double pointeur vers la racine.
 *
 * Return: valeur extraite ou 0 si échec.
 */
int heap_extract(heap_t **root)
{
	int extracted_value;
	heap_t *last_node, *parent;

	if (!root || !*root)
		return (0);

	extracted_value = (*root)->n;
	last_node = get_last_node(*root);

	if (last_node == *root)
	{
		free(*root);
		*root = NULL;
		return (extracted_value);
	}

	/* Remplacer la racine par la valeur du dernier nœud */
	(*root)->n = last_node->n;

	/* Mettre à jour le parent du dernier nœud */
	parent = last_node->parent;
	if (parent->left == last_node)
		parent->left = NULL;
	else
		parent->right = NULL;

	free(last_node);
	heapify(*root);

	return (extracted_value);
}
