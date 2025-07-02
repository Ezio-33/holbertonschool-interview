#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node at the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		tmp = *list;
		while (tmp->next != *list)
			tmp = tmp->next;
		tmp->next = new_node;
		new_node->prev = tmp;
		new_node->next = *list;
		(*list)->prev = new_node;
	}

	return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning of
 * a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node, *tmp;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		tmp = *list;
		while (tmp->next != *list)
			tmp = tmp->next;
		new_node->next = *list;
		new_node->prev = tmp;
		(*list)->prev = new_node;
		tmp->next = new_node;
		*list = new_node;
	}

	return (new_node);
}
