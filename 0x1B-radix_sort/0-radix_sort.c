#include "sort.h"
/**
 * max_array - finds the max
 * @arr: the array
 * @s: its size
 *
 * Return: max
 */
int max_array(int *arr, size_t s)
{
	size_t i;
	int max = arr[0];

	for (i = 0; i < s; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
return (max);
}

/**
 * countingsort - sorts an array
 * @array: an array
 * @size: its size
 * @pst: the position of the digit
 *
 * Return: void
 */

void countingsort(int *array, size_t size, int pst)
{
size_t i;
int j, x, *occu, *output;

occu = malloc(sizeof(int) * (10));
	if (!occu)
		return;
	for (j = 0; j < 10; j++)
		occu[j] = 0;
	for (i = 0; i < size; i++)
	{
		j = (array[i] / pst) % 10;
		occu[j] += 1;
	}
	for (j = 0; j < 10; j++)
		occu[j] += occu[j - 1];

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(occu);
		return;
	}
	for (i = size - 1; (int)i >= 0 ; i--)
	for (j = 0; j < 10; j++)
	{
		if ((array[i] / pst) % 10 == j)
		{
			x = occu[j] - 1;
			occu[j] -= 1;
			output[x] = array[i];
		}
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
free(output);
free(occu);
}

/**
 *radix_sort-function that sorts an array with the Radix sort algorithm
 *
 *@array: the array of integer
 *@size: the size of the array
 *
 *Return:void
 */
void radix_sort(int *array, size_t size)
{
int max;
int post;

	if (!array || size < 2)
		return;

max = max_array(array, size);
	for (post = 1; max / post > 0; post *= 10)
	{
		countingsort(array, size, post);
		print_array(array, size);
	}
}
