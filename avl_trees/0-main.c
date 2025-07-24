#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * basic_tree - Construit un arbre binaire de base pour les tests
 *
 * Return: Un pointeur vers l'arbre créé
 */
binary_tree_t *basic_tree(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 128);
	root->left->right = binary_tree_node(root->left, 54);
	root->right->right = binary_tree_node(root, 402);
	root->left->left = binary_tree_node(root->left, 10);
	return (root);
}

/**
 * main - Point d'entrée pour tester la fonction binary_tree_is_avl
 *
 * Return: Toujours 0 (Succès)
 */
int main(void)
{
	binary_tree_t *root;
	int avl;

	root = basic_tree();

	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Est-ce que %d est AVL: %d\n", root->n, avl);
	avl = binary_tree_is_avl(root->left);
	printf("Est-ce que %d est AVL: %d\n", root->left->n, avl);

	root->right->left = binary_tree_node(root->right, 97);
	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Est-ce que %d est AVL: %d\n", root->n, avl);

	root = basic_tree();
	root->right->right->right = binary_tree_node(root->right->right, 430);
	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Est-ce que %d est AVL: %d\n", root->n, avl);

	root->right->right->right->left = binary_tree_node(root->right->right->right, 420);
	binary_tree_print(root);
	avl = binary_tree_is_avl(root);
	printf("Est-ce que %d est AVL: %d\n", root->n, avl);
	return (0);
}
