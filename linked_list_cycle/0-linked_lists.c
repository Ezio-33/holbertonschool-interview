#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - Affiche tous les éléments d'une liste listint_t
 * @h: Pointeur vers la tête de la liste
 *
 * Return: Nombre de nœuds dans la liste
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *current = h;
	size_t count = 0;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
		count++;
	}
	return (count);
}

/**
 * add_nodeint - Ajoute un nouveau nœud au début d'une liste listint_t
 * @head: Double pointeur vers la tête de la liste
 * @n: Valeur à stocker dans le nouveau nœud
 *
 * Return: Adresse du nouveau nœud ou NULL en cas d'échec
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}

/**
 * free_listint - Libère une liste listint_t
 * @head: Pointeur vers la tête de la liste à libérer
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
