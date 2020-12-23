#include "binary_trees.h"

/**
 * binary_tree_node- creates a binary tree node
 *
 * @parent:  is a pointer to the parent node of the node to create
 * @value: is the value to put in the new node
 *
 * Return: pointer to the new node, or NULL on failure
 *
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *p;

	p = malloc(sizeof(binary_tree_t));
		if (p == NULL)
			return (NULL);

	p->parent = parent;
	p->n = value;
	p->left = NULL;
	p->right = NULL;

return (p);

}