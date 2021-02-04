
#include "lists.h"
/**
 *check_cycle -checks if a singly linked list has a cycle in it.
 *
 *@list: linked liste to checked
 *
 *Return: 1 if exist a cycle or 0 if not
 */
int check_cycle(listint_t *list)
{

listint_t *slow_p = list, *fast_p = list;


	while (slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if (slow_p == fast_p)
			return (1);

	}

			return (0);

}
