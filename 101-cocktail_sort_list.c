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
	print_list(*head_ref);
}
/**
 * get_start - Get the start node
 * @end: end of the list
 * @scount: count of nodes to the new start
 * @list: list to go through
 * Return: start_node address
 */
listint_t *get_start(listint_t *end, int scount, listint_t **list)
{
	listint_t *start_node = *list;

	while (start_node && start_node != end->prev && scount)
	{
		start_node = start_node->next;
		scount--;
	}
	return (start_node);
}
/**
 * get_end - Get the end node
 * @start: end of the list
 * @ecount: count of nodes to the new end from tail
 * @list: list to go through
 * Return: end_node address
 */
listint_t *get_end(listint_t *start, int ecount, listint_t **list)
{
	listint_t *end_node = *list;

	while (end_node->next)
		end_node = end_node->next;

	while (end_node && end_node != start->next && ecount)
	{
		end_node = end_node->prev;
		ecount--;
	}
	return (end_node);
}
/**
 * cocktail_sort_list - Sort the list using cocktail_sort algorithm
 * @list: list to sortW
 */
void cocktail_sort_list(listint_t **list)
{
	int flag = 1, scount = 0, ecount = 0;
	listint_t *i, *start, *end;

	if (!list || !*list || !((*list)->next))
		return;
	while (flag)
	{
		start = get_start(end, scount, list);
		end = get_end(start, ecount, list);
		flag = 0;

		for (i = start; i != end->next && i; i = i->next)
		{
			if (i->next && i->n > i->next->n)
			{
				swap_nodes(list, i, i->next);
				i = i->prev;
				flag++;
			}
		}
		if (!flag)
			break;

		flag = 0;
		for (i = end; i != start && i; i = i->prev)
		{
			while (i->prev && i->n < i->prev->n)
			{
				swap_nodes(list, i->prev, i);
				i = i->next;
				flag++;
			}
		}
		scount++;
		ecount++;
	}
}
