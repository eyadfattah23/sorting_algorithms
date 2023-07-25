#include "sort.h"

/**
 * swap - swaps 2 integers
 * @x: 1st integer
 * @y: 2nd integer
 * @array: array to print
 * @size: size of the array to print
 * Return: 1 if successful, 0 otherwise
 */
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

/**
 * partition - Divides an array into 2 sub-arrays based on pivot element
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array
 * @size: Size of the entire array
 *
 * Return: Index of the pivot element after partitioning
 */
size_t partition(int array[], int start, size_t end, size_t size)
{
	int pivot = array[end];
	size_t pindex = start, i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(&array[i], &array[pindex], array, size);
			pindex++;
		}
	}
	swap(&array[pindex], &array[end], array, size);
	return (pindex);
}
/**
 * Quick_Sort - Sorts an array of integers using the Quick Sort algorithm
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the sub-array to be sorted
 * @end: Ending index of the sub-array to be sorted
 * @size: Size of the entire array
 */
void Quick_Sort(int array[], int start, int end, size_t size)
{
	size_t pindex;

	if (start < end)
	{
		pindex = partition(array, start, end, size);
		Quick_Sort(array, start, pindex - 1, size);
		Quick_Sort(array, pindex + 1, end, size);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 *
 * @array: Pointer to the first element of the array to be sorted
 * @size: Size of the array to be sorted
 */
void quick_sort(int *array, size_t size)
{
	Quick_Sort(array, 0, size - 1, size);
}
