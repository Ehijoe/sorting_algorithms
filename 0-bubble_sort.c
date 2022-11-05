#include "sort.h"


/**
 * bubble_sort - Sort an array using bubble sort
 * @array: Pointer to the start of the array
 * @size: Lenght of the array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, tmp;

	for (i = size - 1; i >= 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
