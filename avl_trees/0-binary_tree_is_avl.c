#include "binary_trees.h"
#include <limits.h>

/**
 * binary_tree_height - Mesure la hauteur d'un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre à mesurer
 *
 * Return: Hauteur de l'arbre, 0 si tree est NULL
 */
int binary_tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (1 + left_height);
	else
		return (1 + right_height);
}

/**
 * binary_tree_balance - Mesure le facteur d'équilibre d'un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 *
 * Return: Facteur d'équilibre, 0 si tree est NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) -
		binary_tree_height(tree->right));
}

/**
 * is_bst_helper - Fonction auxiliaire pour vérifier si un arbre est un BST
 * @tree: Pointeur vers le nœud à vérifier
 * @min: Valeur minimale autorisée
 * @max: Valeur maximale autorisée
 *
 * Return: 1 si l'arbre est un BST valide, 0 sinon
 */
int is_bst_helper(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (is_bst_helper(tree->left, min, tree->n) &&
		is_bst_helper(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Vérifie si un arbre binaire est un BST valide
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 *
 * Return: 1 si tree est un BST valide, 0 sinon
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_bst_helper(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_is_avl - Vérifie si un arbre binaire est un arbre AVL valide
 * @tree: Pointeur vers le nœud racine de l'arbre à vérifier
 *
 * Description: Un arbre AVL est un arbre binaire de recherche
 * auto-équilibrant où la différence de hauteur entre les sous-arbres
 * gauche et droit ne peut jamais dépasser 1 pour chaque nœud.
 *
 * Return: 1 si tree est un arbre AVL valide, 0 sinon
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int balance;

	if (tree == NULL)
		return (0);

	/* Vérifier si c'est un BST valide */
	if (!binary_tree_is_bst(tree))
		return (0);

	/* Calculer le facteur d'équilibre */
	balance = binary_tree_balance(tree);

	/* Vérifier si le facteur d'équilibre est dans la plage acceptable */
	if (balance < -1 || balance > 1)
		return (0);

	/* Vérifier récursivement les sous-arbres gauche et droit */
	if (tree->left && !binary_tree_is_avl(tree->left))
		return (0);

	if (tree->right && !binary_tree_is_avl(tree->right))
		return (0);

	return (1);
}
