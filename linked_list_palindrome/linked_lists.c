#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint - Affiche tous les éléments d'une liste listint_t
 * @h: Pointeur vers la tête de la liste
 * Return: Nombre de nœuds
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
 * add_nodeint_end - Ajoute un nœud à la fin de la liste
 * @head: Double pointeur vers la tête de liste
 * @n: Valeur à stocker dans le nouveau nœud
 * Return: Adresse du nouveau nœud
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));
	listint_t *current;

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	if (!*head)
		*head = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
	return (new_node);
}

/**
 * free_listint - Libère la mémoire de la liste
 * @head: Pointeur vers la tête de liste
 */
void free_listint(listint_t *head)
{
	listint_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
