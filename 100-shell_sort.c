#include "sort.h"

/**
 * shell_sort - sort an array using shell sort algorithm
 * @array: array to sort
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp, flag = 0;

	while (gap < size)
		gap = gap * 3 + 1;

	for (; gap; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j >= gap && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];

			array[j] = tmp;
		}
		if (flag)
			print_array(array, size);
		flag = 1;
	}
}
