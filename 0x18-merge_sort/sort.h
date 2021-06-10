#ifndef _SORT_H_
#define _SORT_H_

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split_merge(int *array, int *arr, int first, int last);
void merging(int *array, int *arr, int first, int mid, int last);

#endif /* _SORT_H_ */