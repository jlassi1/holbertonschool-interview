#include "list.h"

/**
 *add_node_begin- adds a new node at the beginning
 *of a double circular linked list
 *
 *@list: the list to modify 
 *
 *@str: the string to copy into the new node
 *
 *Return: Address of the newnode,or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
List *new_start = NULL;

	new_start = malloc(sizeof(List));
	if (!new_start)
		return (NULL);
	new_start->str = strdup(str);
	if (!new_start->str)
		return (NULL);
	if (!list || !(*list))
	{
		*list = new_start;
		(*list)->next = *list;
		(*list)->prev = *list;
		return (new_start);
	}
	new_start->next = *list;
	new_start->prev = (*list)->prev;
	(*list)->prev = new_start;
	new_start->prev->next = new_start;
	(*list) = new_start;
	return (new_start);
}

/**
 *add_node_end- adds a new node at the end
 *of a double circular linked list
 *
 *@list: the list to modify 
 *
 *@str: the string to copy into the new node
 *
 *Return: Address of the newnode,or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_end = NULL;
List *temp;

	new_end = malloc(sizeof(List));
	if (!new_end)
		return (NULL);
	new_end->str = strdup(str);
	if (!new_end->str)
		return (NULL);
	if (!list || !(*list))
	{
		*list = new_end;
		(*list)->next = *list;
		(*list)->prev = *list;
		return (new_end);
	}
	temp = *list;
	while (temp)
	{
		if (temp->next == *list)
			break;
		temp = temp->next;
	}
	new_end->next = temp->next;
	temp->next = new_end;
	new_end->prev = temp;
	new_end->next->prev = new_end;
	return  (new_end);
}
