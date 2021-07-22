#include "binary_trees.h"
/**
 * max - fucntion return the max int
 * @a: int
 * @b: int
 * Return: max integer between a and b
 */
int max(int a, int b)
{
	return (a >= b) ? a : b;
}
/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree
 */
int height(binary_tree_t *tree)
{
	int hl, hr;

	if (!tree)
		return (0);
	hl = height(tree->left);
	hr = height(tree->right);
	return 1 + max(hl, hr);
}
/**
 * is_avl - recursively checks if tree is AVL
 * @tree: pointer to current root
 * @min: current min val
 * @max: current max val
 * Return: 1 if is AVL else 0
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
	int a, b;

	if (!tree)
		return (1);

	a = height(tree->left);

	b = height(tree->right);

	if (abs(a - b) > 1)
		return (0);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_avl(tree->left, min, tree->n - 1) &&
		is_avl(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_avl - checks is tree is AVL
 * @tree: pointer to root node
 * Return: 1 if AVL else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_avl(tree, INT_MIN, INT_MAX));
}

