#include "binary_trees.h"

/**
* new_node - create a new node
* @parent: node's parent
* @value: node's value
* Return: the new node
*/
avl_t *new_node(avl_t *parent, int value)
{
	avl_t *node;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->right = NULL;
	node->left = NULL;
	node->n = value;

	return (node);
}

/**
 * create_AVL - create an AVL tree from array
 * @array: pointer to the 1st element of the array
 * @parent: pointer to the parent node of the tree
 * @start: start index
 * @end: end index
 * Return: pointer to the root of AVL node
 */
avl_t *create_AVL(int *array, int start, int end, avl_t *parent)
{
avl_t *tmp;
int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	tmp = new_node(parent, array[mid]);

	if (tmp == NULL)
		return (NULL);
	tmp->left = create_AVL(array, start, mid - 1, tmp);
	tmp->right = create_AVL(array, mid + 1, end, tmp);

	return (tmp);
}

/**
 * sorted_array_to_avl -function that builds an AVL tree from an array
 *
 * @array:is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 *
 * Return: a pointer to the root node of the AVL tree, or NULL on failure
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{

if (!array || size < 1)
	return (NULL);
return (create_AVL(array, 0, (size - 1), NULL));

}
