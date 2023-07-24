#include "sort.h"

void swapNodes(listint_t **headRef, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
	{
		return;
	}

	if (node1->prev != NULL)
	{
		node1->prev->next = node2;
	}
	else
	{
		*headRef = node2;
	}

	if (node2->next != NULL)
	{
		node2->next->prev = node1;
	}

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *i = *list;
	listint_t *j, *key, *head = *list;

	if (!list || !*list || i->next == NULL)
		return;

	for (i = i->next; i; i = i->next)
	{
		key = i;
		j = i->prev;

		while (j && ((j->prev->n) > (key->n)))
		{
			swapNodes(&head, j, j->next);
			j = j->prev;
		}
		j->next = key;
	}
}
