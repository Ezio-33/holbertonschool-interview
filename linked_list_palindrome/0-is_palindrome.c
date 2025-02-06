#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * reverse_list - Inverse une liste chaînée
 * @head: Double pointeur vers la tête de liste
 * Return: Pointeur vers la nouvelle tête inversée
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *current = head;
	listint_t *next = NULL;

	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
}

/**
 * compare_halves - Compare deux moitiés de liste
 * @first: Première moitié de la liste
 * @second: Seconde moitié inversée
 * Return: 1 si identiques, 0 sinon
 */
int compare_halves(listint_t *first, listint_t *second)
{
	while (second != NULL)
	{
		if (first->n != second->n)
			return 0;
		first = first->next;
		second = second->next;
	}
	return 1;
}

/**
 * is_palindrome - Vérifie si une liste est un palindrome
 * @head: Double pointeur vers la tête de liste
 * Return: 1 si palindrome, 0 sinon
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *prev_slow = *head;
	listint_t *second_half, *mid_node = NULL;
	int result = 1;

	if (*head == NULL || (*head)->next == NULL)
		return 1;

	/* Trouver le milieu avec fast/slow pointers */
	while (fast != NULL && fast->next != NULL)
	{
		fast = fast->next->next;
		prev_slow = slow;
		slow = slow->next;
	}

	/* Gestion des listes impaires */
	if (fast != NULL)
	{
		mid_node = slow;
		slow = slow->next;
	}

	/* Séparation et inversion de la seconde moitié */
	second_half = slow;
	prev_slow->next = NULL; 
	second_half = reverse_list(second_half);

	/* Comparaison des deux moitiés */
	result = compare_halves(*head, second_half);

	/* Reconstruction de la liste originale (optionnel) */
	second_half = reverse_list(second_half);
	if (mid_node != NULL)
	{
		prev_slow->next = mid_node;
		mid_node->next = second_half;
	}
	else
	{
		prev_slow->next = second_half;
	}

	return result;
}
