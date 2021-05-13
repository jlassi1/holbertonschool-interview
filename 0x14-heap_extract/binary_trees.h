#ifndef BINARY_T
#define BINARY_T
/*-----------LIBRARY----------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>


/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;

void binary_tree_print(const binary_tree_t *);

/*---------PROTOTYPE-------------*/
int heap_extract(heap_t **root);
int get_size(heap_t *root);
void rebuild_heap(heap_t *node);
void heap_to_array(heap_t *tree, heap_t **root, int height);

#endif
