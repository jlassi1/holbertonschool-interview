#include "lists.h"

/**
 *is_palindrome - returns 1 if a string is a palindrome and 0 if not
 *@head: double pointer to head node
 *Return: 1 if palindrome and 0 if is not
 */
int is_palindrome(listint_t **head)
{
listint_t *first, *right;

	if (!(*head) || (!(*head)->next))
		return (1);

right = *head;
	while (right->next)
		right = right->next;

first = *head;

	while (right >= first)
	{
		if (first->n == right->n)
		{
			first = first->next;
			right -= 2;
		}
		else
			return (0);
	}
return (1);
}

