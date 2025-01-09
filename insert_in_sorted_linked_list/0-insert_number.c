#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Insère un nombre dans une liste chaînée triée
 * @head: Pointeur vers le pointeur de la tête de la liste
 * @number: Nombre à insérer
 * Return: Adresse du nouveau nœud ou NULL si échec
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *nouveau, *courant;

	nouveau = malloc(sizeof(listint_t));
	if (nouveau == NULL)
		return (NULL);

	nouveau->n = number;
	nouveau->next = NULL;

	if (*head == NULL || (*head)->n >= number)
	{
		nouveau->next = *head;
		*head = nouveau;
		return (nouveau);
	}

	courant = *head;
	while (courant->next != NULL && courant->next->n < number)
		courant = courant->next;

	nouveau->next = courant->next;
	courant->next = nouveau;

	return (nouveau);
}

