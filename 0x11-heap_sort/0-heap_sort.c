#include "sort.h"

/**
 *swap-function swap two integer
 *@a: pointer integer
 *@b: pointer integer
 *
 */

void swap(int *a, int *b)
{
int tmp = *a;

	*a = *b;
	*b = tmp;
}
/**
 *heapify-The process of reshaping a binary tree into a Heap data structure
 *@arr: array to sort
 *@n: size of array
 *@i: index
 *
 */
void heapify(int arr[], int n, int i)
{
int max = i;
int leftChild = 2 * i + 1;
int rightChild = 2 * i + 2;

	/* If left child is greater than root */
	if (leftChild < n && arr[leftChild] > arr[max])
		max = leftChild;

	/* If right child is greater than max */
	if (rightChild < n && arr[rightChild] > arr[max])
		max = rightChild;

	/* If max is not root*/
	if (max != i)
	{
		swap(&arr[i], &arr[max]);

		/* heapify the affected sub-tree recursively */
		heapify(arr, n, max);

	}
}

/**
 * heap_sort-function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @arr: The array to sort it
 * @size: size of the array
 */
void heap_sort(int *arr, size_t size)
{
int i;
	/*Rearrange array (building heap)*/
	for (i = (int)size / 2 - 1; i >= 0; i--)
	{
		heapify(arr, (int)size, i);
		print_array((const int *)arr, size);
	}
	/*Extract elements from heap one by one*/
	for (i = (int)size - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]); /*Current root moved to the end*/
		print_array((const int *)arr, size);
		heapify(arr, i, 0); /*calling max heapify on the heap reduced*/
		print_array((const int *)arr, size);
	}
}
