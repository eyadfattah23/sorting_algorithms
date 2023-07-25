#include "sort.h"
/**
 * swap_nodes - swaps 2 nodes in a doubly linked list
 * @head_ref: head of the list
 * @node1: node to swap
 * @node2: node to swap
 */
void swap_nodes(listint_t **head_ref, listint_t *node1, listint_t *node2)
{
	if (node1 == node2)
		return;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
	if (node2->prev != NULL)
		node2->prev->next = node2;
	else
		*head_ref = node2;

	if (node1->next != NULL)
		node1->next->prev = node1;
}
/**
 * insertion_sort_list - sorts a linked list by insertion sort algorithm
 * @list: list to sort
 */
void insertion_sort_list(listint_t **list)
{
	int key;
	listint_t *hole, *node;

	if (!list || !*list || !((*list)->next))
		return;

	for (node = (*list)->next; node; node = node->next)
	{
		key = node->n;
		hole = node;

		while (hole->prev && (hole->prev->n > key))
		{
			swap_nodes(list, hole->prev, hole);
			if (hole->prev && hole->prev->n < key)
				hole = hole->prev;
			print_list(*list);
		}
	}
}
