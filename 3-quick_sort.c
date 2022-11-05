#include "sort.h"


/**
 * swap - Swap two indexes of an array
 * @array: The array to change
 * @idx1: The first index
 * @idx2: The second index
 * @arr_start: The start of the original array
 * @size: The length of the array
 */
void swap(int *array, size_t idx1, size_t idx2, int *arr_start, size_t size)
{
	int tmp;

	if (idx1 == idx2)
		return;
	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
	print_array(arr_start, size);
}


/**
 * partition - Partition the array using the Lumoto scheme
 * @array: Pointer to the start of the array
 * @size: Length of the array
 * @arr_start: The start of the original array
 * @original_size: The size of the full array
 *
 * Return: The index of the element to partition by
 */
size_t partition(int *array, size_t size, int *arr_start, size_t original_size)
{
	int pivot;
	size_t i, j;

	pivot = array[size - 1];
	i = 0;
	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= pivot)
		{
			swap(array, i, j, arr_start, original_size);
			i++;
		}
	}
	swap(array, i, size - 1, arr_start, original_size);
	return (i);
}


/**
 * quick_sort_helper - Sort an array using quicksort
 * @array: Pointer to the start of the array
 * @size: Length of the array
 * @arr_start: The start of the original array
 * @original_size: The size of the entire array
 */
void quick_sort_helper(int *array, size_t size,
		       int *arr_start, size_t original_size)
{
	size_t p;

	if (size <= 1)
		return;
	p = partition(array, size, arr_start, original_size);

	quick_sort_helper(array, p, arr_start, original_size);
	quick_sort_helper(array + p + 1, size - p - 1, arr_start, original_size);
}


/**
 * quick_sort - Sort an array using quicksort
 * @array: Pointer to the start of the array
 * @size: Length of the array
 */
void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, size, array, size);
}
