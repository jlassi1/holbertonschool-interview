#include "sort.h"

/**
 * merging - merges two subarrays 
 * @array: the array to sorted
 * @arr: the temporary array that contains subarrays
 * @start: index of start element in the start subarray
 * @middel: index of start element in the second subarray and the end of the first  
 * @end: index of end element in second subarray
 */
void merging(int *array, int *arr, int start, int middel, int end)
{
int i = start, j = middel, k = start;

printf("Merging...\n");
printf("[left]: ");
print_array((const int *)&arr[start], middel - start);
printf("[right]: ");
print_array((const int *)&arr[middel], end - middel + 1);
while (i < middel && j <= end)
{
if (arr[i] < arr[j])
{
array[k] = arr[i];
i++;
k++;
}
else
{
array[k] = arr[j];
j++;
k++;
}
}
while (i < middel)
{
array[k] = arr[i];
i++;
k++;
}
while (j <= end)
{
array[k] = arr[j];
j++;
k++;
}
printf("[Done]: ");
for (i = start; i <= end; i++)
arr[i] = array[i];
print_array((const int *)&array[start], end - start + 1);
}

/**
 * split_merge - splits the arr into subarrays
 * @array: the array of integers
 * @arr: the copy of array
 * @start: index of start element
 * @end: index of end element
 */
void split_merge(int *array, int *arr, int start, int end)
{
int size, middel;

size = end - start + 1;
if (size < 2)
return;
middel = (size / 2) + start;
split_merge(array, arr, start, middel - 1);
split_merge(array, arr, middel, end);
merging(array, arr, start, middel, end);
}

/**
 * merge_sort - sort an arr of int with top-down merge sort algorithm
 * @array: the array of integers
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
int i;
int *arr;

if (!array || size < 2)
return;
arr = malloc(sizeof(int) * size);
if (!arr)
return;
for (i = 0; i < (int)size; i++)
arr[i] = array[i];

split_merge(array, arr, 0, (int)(size - 1));
free(arr);
}
