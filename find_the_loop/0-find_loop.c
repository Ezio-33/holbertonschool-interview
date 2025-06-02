#include "lists.h"

/**
 * find_listint_loop - détecte une boucle dans une liste chaînée.
 * @head: pointeur vers la tête de la liste.
 *
 * Return: pointeur vers le début de la boucle ou NULL.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	if (!head || !(head->next))
		return (NULL);

	slow = head->next;
	fast = head->next->next;

	while (fast && fast->next)
	{
		if (slow == fast)
		{
			slow = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return (slow);
		}
		slow = slow->next;
		fast = fast->next->next;
	}

	return (NULL);
}
