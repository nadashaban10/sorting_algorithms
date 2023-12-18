#include "sort.h"

/**
 * quick_sort - function that sorts an array of integers
 *              in ascending order using the Quick sort algorithm
 * @array: array
 * @size: array's size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick(array, 0, size - 1, size);
}

/**
 * partition - partition
 * @array: array
 * @start: first element
 * @end: last element
 * @size: array's size
 * Return: i
 */
int partition(int *array, int start, int end, size_t size)
{
	int i = start - 1;
	int j = start;
	int pivot = array[end];
	int swapped = 0;

	for (; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swapped = array[i];
				array[i] = array[j];
				array[j] = swapped;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[end])
	{
		swapped = array[i + 1];
		array[i + 1] = array[end];
		array[end] = swapped;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick - quick sort
 * @array: given array
 * @lo: lower
 * @hi:higher
 * @size: array's size
 * Return: void
 */
void quick(int *array, int lo, int hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		quick(array, lo, pivot - 1, size);
		quick(array, pivot + 1, hi, size);
	}
}
