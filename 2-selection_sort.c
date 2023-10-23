#include "sort.h"

/**
 * smallest - returns the index of the smallest value in an array
 * @array: a pointer to the beginning of the array
 * @size: size of the array
 * @i: starting point in the array
 *
 * Return: index of the smallest value in the array
 */

size_t smallest(int *array, size_t size, size_t i)
{
	size_t j;
	int smallest;
	int small_index;

	for (j = i; j < size; j++)
	{
		if (j == i)
		{
			smallest = array[j];
			small_index = j;
			continue;
		}
		if (smallest > array[j])
		{
			smallest = array[j];
			small_index = j;
		}
	}
	return (small_index);
}

/**
 * selection_sort - sorts an array in ascending order
 * @array: a pointer to the beginning of the array
 * @size: size of the array
 *
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, index;
	int swap = 0;

	if (!array)
		return;
	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		index = smallest(array, size, i);
		if (i == index)
			continue;
		swap = array[i];
		array[i] = array[index];
		array[index] = swap;
		print_array(array, size);
	}
}
