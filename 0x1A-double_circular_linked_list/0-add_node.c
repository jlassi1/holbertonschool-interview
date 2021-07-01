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
	if (!list || !str)
		return (NULL);
	    
	List *new_node = malloc(sizeof(List));
	new_node->str = malloc( strlen( str ) + 1 );
	if (!new_node || ! new_node->str)
		return (NULL);
	new_node->str = str; 

	if (!(*list))
	{
		*list = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return new_node;
	}

	new_node->prev = (*list)->prev;
	new_node->next = *list;
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;
	*list =	new_node;
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
	if (!list || !str)
		return (NULL);
	    
List *new_node = malloc(sizeof(List));
new_node->str = malloc( strlen( str ) + 1 );
	if (!new_node || ! new_node->str)
		return (NULL);
	new_node->str = str; 

	if (!(*list))
	{
		*list = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return new_node;
	}

	new_node->prev = (*list)->prev;
	new_node->next = *list;
	new_node->prev->next = new_node;
	new_node->next->prev = new_node;

	return new_node;

}

