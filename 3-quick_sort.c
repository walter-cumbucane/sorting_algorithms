#include "sort.h"

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
	int pivot, i, j, swap;

	pivot = array[high];
	i = low - 1;
	for (j = low; j <= high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap = array[j];
			array[j] = array[i];
			array[i] = swap;
		}
	}
	swap = array[high];
	array[high] = array[i + 1];
	array[i + 1] = swap;
	print_array(array, size);
	return (i + 1);
}





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
