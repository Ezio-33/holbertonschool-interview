#include "lists.h"

/**
 * check_cycle - Vérifie si une liste chaînée contient un cycle
 * @list: Pointeur vers la tête de la liste
 *
 * Return: 1 si un cycle est détecté, 0 sinon
 */
int check_cycle(listint_t *list)
{
	listint_t *lent = list;  /* Pointeur lent */
	listint_t *rapide = list; /* Pointeur rapide */

	while (rapide != NULL && rapide->next != NULL)
	{
		lent = lent->next;            /* Avance d'un pas */
		rapide = rapide->next->next; /* Avance de deux pas */

		if (lent == rapide) /* Les deux pointeurs se rencontrent */
			return (1);
	}
	return (0); /* Aucun cycle détecté */
}
