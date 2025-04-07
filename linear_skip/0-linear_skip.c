#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: The value to search for.
 *
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *current, *upper;

    if (list == NULL)
        return (NULL);

    current = list;

    /* Traverse the express lane */
    while (current->express && current->express->n <= value)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->express->index, current->express->n);
        current = current->express;
    }
    upper = current->express;

    /* Determine the end index for the message */
    size_t start_idx = current->index;
    size_t end_idx;

    if (upper)
    {
        end_idx = upper->index;
    }
    else
    {
        /* Find the last node's index */
        skiplist_t *tmp = current;
        while (tmp->next)
            tmp = tmp->next;
        end_idx = tmp->index;
    }
    printf("Value found between indexes [%lu] and [%lu]\n", start_idx, end_idx);

    /* Traverse the normal lane */
    while (current != upper)
    {
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        if (current->n == value)
            return (current);
        current = current->next;
    }

    /* Check the upper node if it exists */
    if (upper && upper->n == value)
    {
        printf("Value checked at index [%lu] = [%d]\n", upper->index, upper->n);
        return (upper);
    }

    return (NULL);
}
