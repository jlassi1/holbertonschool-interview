#include "lists.h"
/**
 *find_listint_loop - find loop in linked list
 *@head: pointer to linked list
 *
 *Return: node when start the loop or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow_p = head, *fast_p = head;


while (slow_p && fast_p && fast_p->next)
{
	slow_p = slow_p->next;
	fast_p = fast_p->next->next;
	if (slow_p == fast_p)
	{

		slow_p = head;

		while (slow_p != fast_p)
		{
			slow_p = slow_p->next;
			fast_p = fast_p->next;
		}

		return (slow_p);
	}

	}

	return (NULL);
}

