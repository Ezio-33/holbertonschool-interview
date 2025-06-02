#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - nœud d'une liste simplement chaînée
 * @n: entier
 * @next: pointe vers le prochain nœud
 *
 * Description: Structure pour un nœud d'une liste chaînée simple
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *add_nodeint(listint_t **head, const int n);
size_t print_listint_safe(const listint_t *head);
size_t free_listint_safe(listint_t **h);
listint_t *find_listint_loop(listint_t *head);

#endif /* LISTS_H */
