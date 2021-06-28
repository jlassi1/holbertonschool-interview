#include "list.h"

/**
 *add_node_end- adds a new node at the end of a double circular linked list
 *
 *@list: the list to modify 
 *
 *@str: the string to copy into the new node
 *
 *Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
List *new_node = malloc(sizeof(List));
List *tmp = *list;
	if (new_node == NULL)
        	return (NULL);

	new_node->str = str;
	new_node->next = NULL;

    
    	if (!(*list))
    	{
		new_node->prev = NULL;
		*list = new_node;
		return new_node;
    	}
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
	return new_node;

}

/**
 *add_node_begin- adds a new node at the beginning of a double circular linked list
 *
 *@list: the list to modify 
 *
 *@str: the string to copy into the new node
 *
 *Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	    
List *new_node = malloc(sizeof(List));

	if (new_node == NULL)
		return (NULL);

	new_node->str = str;
	new_node->next = *list;
	new_node->prev = NULL;
    
	if (!(*list))
	{
		*list = new_node;
		return new_node;
	}
	(*list)->prev = new_node;
	(*list) = new_node;
	return new_node;

}

