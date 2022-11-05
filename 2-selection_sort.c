#include "sort.h"


/**
 * selection_sort - Sort an array using selection sort
 * @array: Pointer to the start of the array
 * @size: Length of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		int min;
		size_t min_idx;

		min_idx = i;
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				min_idx = j;
			}
		}
		if (min_idx != i)
		{
			int tmp;

			tmp = array[i];
			array[i] = min;
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
