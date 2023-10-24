#include "sort.h"


/**
 * swp - swaps 2 values
 * @arr: a pointer to the beginning of the array to sort
 * @x: address of first value
 * @y: address of second value
 * @size: size of the array
 * Return: nothing
 */
void swp(int *arr, int *x, int *y, size_t size)
{
	if (*x != *y)
	{
		*x = *x + *y;
		*y = *x - *y;
		*x = *x - *y;
		print_array(arr, size);
	}
}



/**
 * partition - sorts the partitions in quick sort algorithms
 * @array: a pointer to the beginning of the array
 * @low: where to start looking in the array
 * @high: where to stop lookin in the array
 * @size: size of the array
 *
 * Return: the final index of the pivot
 */


int partition(int *array, int low, int high, size_t size)
{
	int i, j, pivot = array[high];

	for (i = j = low; j < high; j++)
		if (array[j] < pivot)
			swp(array, &array[j], &array[i++], size);
	swp(array, &array[i], &array[high], size);
	return (i);
}



/**
 * sort_quickly - recursively implements the quick_sort algorithm
 * @array: a pointer to the beginning of the array
 * @low: where to start looking in the array
 * @high: where to stop lookin in the array
 * @size: size of the array
 *
 * Return: the final index of the pivot
 */


void sort_quickly(int *array, int low, int high, size_t size)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);
		sort_quickly(array, low, pivot_index - 1, size);
		sort_quickly(array, pivot_index + 1, high, size);
	}
}




/**
 * quick_sort - sorts an array in ascending order
 * @array: a pointer to the beginning of the array
 * @size: size of the array
 *
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (!array)
		return;
	if (size < 2)
		return;
	sort_quickly(array, 0, size - 1, size);
}
