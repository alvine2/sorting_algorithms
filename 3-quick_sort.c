#include "sort.h"

void swap_ints(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swap_ints - swap two integers in an array.
 * @a: the first integer to swap.
 * @b: the second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - order a subset of an array of integers according to
 *                    the lomuto partition scheme (last element as pivot).
 * @array: the array of integers.
 * @size: the size of the array.
 * @left: the starting index of the subset to order.
 * @right: the ending index of the subset to order.
 *
 * Return: the final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - implement quicksort algorithm through recursion.
 * @array: an array of integers to sort.
 * @size: the size of the array.
 * @left: the starting index of the array partition to order.
 * @right: the ending index of the array partition to order.
 *
 * Description: uses the Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, part - 1);
		lomuto_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: an array of integers.
 * @size: the size of the array.
 *
 * Description: uses Lomuto partition scheme. Prints
 *              the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
