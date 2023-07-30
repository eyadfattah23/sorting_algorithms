#include "sort.h"
/**
 * counting_sort - sort an array usinh counting sort algorithm
 * @array: the array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *output = malloc(sizeof(int) * size), *count;
	size_t i, max_val = array[0];

	if (!output)
		return;

	for (i = 1; i < size; i++)
		if ((size_t)array[i] > max_val)
			max_val = array[i];

	count = malloc(sizeof(int) * (max_val + 1));
	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i < max_val + 1; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (i = 1; i <= max_val; i++)
		count[i] += count[i - 1];

	print_array(count, max_val + 1);
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
	free(count);
}
