#include "lists.h"

/**
 *insert_node-inserts a number into a sorted singly linked list.
 *@head: the head of the linked list
 *@number: the number data of the new node
 *
 *Return: the new node
 */
listint_t *insert_node(listint_t **head, int number){

listint_t *tmp = *head, *node;

node = malloc(sizeof(listint_t));
if (node == NULL)
return (NULL);
node->n = number;
node->next = NULL;
if(!(*head) || (*head)->n > number)
{
node->next = *head;
return(node);
}
while (tmp->next->n < number)
{
tmp = tmp->next;
if(tmp->next == NULL)
break;
}

node->next = tmp->next;
tmp->next = node;
return(tmp);

}
