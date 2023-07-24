
/**
 * swap - swaps 2 integers
 * @x: 1st integer
 * @y: 2nd integer
 */
void swap_ints(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
