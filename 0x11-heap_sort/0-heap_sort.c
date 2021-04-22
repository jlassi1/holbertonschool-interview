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
int left = 2 * i + 1;
int right = 2 * i + 2;

/* If left child is greater than root */
if (left <= n && (right > n || arr[left] > arr[right]) && arr[left] > arr[max])
	max = left;

/* If right child is greater than max */
if (right <= n && arr[right] > arr[max] && arr[right] >= arr[left])
	max = right;

/* If max is not root*/
if (max != i)
{
	swap(&arr[i], &arr[max]);
	print_array(arr, size);
	siftDown(arr, i, max, size);

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
		swap(&array[0], &array[i]);
		print_array(array, size);
	}
}
