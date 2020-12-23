#include "binary_trees.h"
/**
 * swap - sawpe the value of 2 nodes
 * @n1: node 1
 * @n2: node2
 * 
 * Return: void
 */

void swap(heap_t* n1, heap_t* n2)
{
	int tmp = n2->n;

		n2->n = n1->n;
		n1->n = tmp;
		n1 = n2;
}

/**
 * insert_node - functin to insert a node in the right position
 * @node: pointer to node
 * @lvl: the insertion node level
 * @m: integer
 *
 * Return: a pointer to the node to insert
 */

heap_t *insert_node(heap_t **node, int value)
{
	binary_tree_t *new_node, *temp;

	
	temp = *node;
	while (temp)
	{
		if (value < temp->n)
		{
			if (temp->left == NULL)
			{
				new_node = binary_tree_node(temp, value);
				temp->left = new_node;
				return (new_node);
			}
			temp = temp->left;
		}
		else if (value > temp->n)
		{
			if (temp->right == NULL)
			{
				new_node = binary_tree_node(temp, value);
				temp->right = new_node;
				return (new_node);
			}
			temp = temp->right;
		}
		else
			return (NULL);
	}
	return (*node);

}


/**
 * heap_insert - a function to insert a value into a Max binary heap
 * @root: a double pointer to the heap root node
 * @value: value to be inserted
 *
 * Return: the pointer to the inserted new node, otherwise NULL
 */

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;
	

	if (!root)
		return (NULL);

	if (!(*root))
	{
		new_node = binary_tree_node(*root, value);
		*root = new_node;
		return (new_node);
	}


	new_node = (heap_t *) insert_node(root, value);



	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap(new_node->parent, new_node);
		new_node = new_node->parent;
	}

	return (new_node);
}
