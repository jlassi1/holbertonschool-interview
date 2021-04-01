#include <stdlib.h>
#include <math.h>
#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers
 *
 * @head: Pointer to the head of the skip list to search in
 * @value: The value to search for
 *
 * Return: the node searching for or NULL if failed
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
skiplist_t *node, *prev, *tmp;
	node = head;
	prev = head;
	if (head == NULL)
		return (NULL);
	for (node = head->express; node; node = node->express)
	{
		printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
		if (value <= node->n)
		{
			printf("Value found between indexes [%lu] and [%lu]\n",
				prev->index, node->index);
			tmp = prev;
			while (tmp->next != node->next)
			{
				printf("Value checked at index [%lu] = [%d]\n", tmp->index, tmp->n);
				if (value == tmp->n)
					return (tmp);
				tmp = tmp->next;
			}
		}
		prev = prev->express;
	}
	if (prev->n < value)
	{
		tmp = prev;
		while (tmp->next)
			tmp = tmp->next;
		printf("Value found between indexes [%lu] and [%lu]\n",
			prev->index, tmp->index);
		while (prev)
		{
			printf("Value checked at index [%lu] = [%d]\n", prev->index, prev->n);
			if (value == prev->n)
				return (prev);
			prev = prev->next;
		}
	}
	return (node);
}
