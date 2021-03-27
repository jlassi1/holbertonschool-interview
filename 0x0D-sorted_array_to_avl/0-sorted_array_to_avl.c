#include "binary_trees.h"


/**
 * create_node - set the left AVL node of a parent node
 * @array: pointer to the 1st element of the array
 * @parent: pointer to the parent node of the tree
 * @start: start index
 * @end: end index
 * Return: pointer to the root of AVL node
 */
avl_t *create_node(int *array, avl_t *parent, size_t start, size_t end)
{
avl_t *tmp;
int mid;

	if (start > end)
		return (NULL);
	mid = (start + end) / 2;
	tmp = malloc(sizeof(avl_t));
	if (tmp == NULL)
		return (NULL);

	tmp->parent = parent;
	tmp->n = array[mid];

	if (tmp == NULL)
		return (NULL);
	tmp->left = create_node(array, tmp, start, mid - 1);
	tmp->right = create_node(array, tmp, mid + 1, end);

	return (tmp);
}

/**
 * sorted_array_to_avl -function that  builds an AVL tree from an array
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

return (create_node(array, NULL, 0, size - 1));

}
