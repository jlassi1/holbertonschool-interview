#include <stdio.h>
#include <stdlib.h>
#include "search.h"

/**
 *search - search for the exact node
*@head: pointer for the skip list
*@x: value searching for
*Return: the node of that value or NULL if failed
*/

skiplist_t *search(skiplist_t *head, int x)
{
skiplist_t *current = head;
	while (current != NULL)
	{
	printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
	if (current->n == x)
		return (current);
	current = current->next;
	}
return (NULL);
}

/**
 * linear_skip - searches for a value in a sorted skip list of integers
* @list: skip list
* @value: value to search for
* Return: a pointer on the first node where value is located
*/
skiplist_t *linear_skip(skiplist_t *list, int value)
{
skiplist_t *node, *prev, *tmp;

node = list;
prev = list;
	if (list == NULL)
		return (NULL);
	for (node = list->express; node; node = node->express)
	{
	printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
	if (value <= node->n)
	{
		printf("Value found between indexes [%lu] and [%lu]\n",
		prev->index, node->index);
		return (search(prev, value));

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
		return (search(prev, value));
	}

return (node);
}
