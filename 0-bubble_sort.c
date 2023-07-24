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
 * bubble_sort - sorts an array of integers using bubble sort
 * algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, flag;

	if (!array || !array[0] || !size || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] >= array[j + 1])
			{
				swap_ints(&array[j], &array[j + 1]);
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
