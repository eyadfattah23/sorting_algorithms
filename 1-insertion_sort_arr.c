#include "sort.h"
int swap(int *x, int *y, int array[], size_t size)
{
	int tmp = *x;

	if (x == y)
		return (0);
	*x = *y;
	*y = tmp;
	print_array(array, size);
	return (1);
}

void insertion_sort_array(int *array, size_t size)
{
	size_t i, j;
	int key;

	for (i = 1; i < size; i++)
	{
		key = array[i];
		j = i;
		while (j && array[j - 1] > key)
		{
			swap(&array[j], &array[j - 1], array, size);
			j -= 1;
		}
	}
}
