#include "lists.h"

/**
 * insert_node -  inserts a number into a sorted singly linked list.
 * @head: the head of the linked list
 * @number: the number data of the new node
 *
 * Return: the new node
 */
listint_t *insert_node(listint_t **head, int number){
if(!*head)
   return(NULL);
listint_t *tmp = *head, *node;

node = malloc(sizeof(listint_t));
if (node == NULL)
return (NULL);
node->n = number;
node->next = NULL;
if(tmp->n >= number || !tmp)
{
node->next = tmp;
return(node);
}
while (tmp->n < number)
{
tmp = tmp->next;
}

node->next = tmp->next;
tmp->next = node;
return(node);

}
