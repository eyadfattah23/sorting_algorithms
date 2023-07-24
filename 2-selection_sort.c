#include "sort.h"
/**
 * swap_ints - swaps 2 integers
 * @x: 1st integer
 * @y: 2nd integer
 */
void swap_ints(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * selection_sort - sort an array of ints using selection sort
 * @array: array of ints to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t minidx, i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minidx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[minidx] > array[j])
			{
				minidx = j;
			}
		}
		if (minidx != i)
		{
			/* code */
			swap_ints(&array[minidx], &array[i]);
			print_array(array, size);
		}
	}
}
