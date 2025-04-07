#include "search.h"

/**
 * linear_skip - Recherche une valeur dans une skip list
 * @list: Tête de la liste
 * @value: Valeur à trouver
 * Return: Nœud trouvé ou NULL
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list, *upper = NULL;

	if (!list)
		return (NULL);

	/* Traversée de la voie express */
	while (current->express && current->express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			  current->express->index, current->express->n);
		current = current->express;
	}
	upper = current->express;

	/* Gestion de l'affichage de la plage */
	if (upper)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			  upper->index, upper->n);
		printf("Value found between indexes [%lu] and [%lu]\n",
			  current->index, upper->index);
	}
	else
	{
		skiplist_t *last = current;

		while (last->next)
			last = last->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			  current->index, last->index);
	}

	/* Recherche linéaire */
	while (current != (upper ? upper->next : NULL))
	{
		printf("Value checked at index [%lu] = [%d]\n",
			  current->index, current->n);
		if (current->n == value)
			return (current);
		current = current->next;
	}

	return (NULL);
}
