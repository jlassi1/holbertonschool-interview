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
 *siftDown - sift_down heap sort algorithm
 *@arr: array to sort
 *@n: integer
 *@i: integer
 *@size: size of array
 *
 */

void siftDown(int *arr, int n, int i, size_t size)
{

int max = i;
int leftChild = 2 * i + 1;
int rightChild = 2 * i + 2;

	/* If left child is greater than root */
	if (leftChild <= n && arr[leftChild] > arr[max] && arr[leftChild] > arr[max])
		max = leftChild;

	/* If right child is greater than max */
	if (rightChild <= n && arr[rightChild] > arr[max])
		max = rightChild;

	/* If max is not root*/
	if (max != i)
	{
		swap(&arr[i], &arr[max]);
		siftDown(arr, i, max, size);
		print_array(arr, size);

	}
return;
}

/**
 * heap_sort-function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 *
 * @array: The array to sort it
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
int i, j;

	if (!array || size <= 1)
		return;
	for (i = (int)size - 1; i > 0; i--)
	{
		for (j = i; j >= 0; j--)
		{
			siftDown(array, i, j, size);
		}
		print_array(array, size);
		swap(&array[0], &array[i]);
	}
}
