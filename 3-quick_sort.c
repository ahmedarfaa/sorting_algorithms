#include "sort.h"

/**
 * Swap_items - a function that Swaps items in the array.
 * @array: array.
 * @l: the left item indx.
 * @r: the right item indx.
 */
void Swap_items(int *array, size_t l, size_t r)
{
	int temp;

	if (array != NULL)
	{
		temp = array[l];
		array[l] = array[r];
		array[r] = temp;
	}
}

/**
 * Quick_sort_range - a function that sorts the sub-array
 * @array: the sub-array.
 * @low: starting indx.
 * @high: ending indx.
 * @size: array size.
 */
void Quick_sort_range(int *array, size_t low, size_t high, size_t size)
{
	size_t k, i;
	int pvt;

	if ((low >= high) || (array == NULL))
		return;
	pvt = array[high];
	k = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pvt)
		{
			if (k != i)
			{
				Swap_items(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}
	if (k != high)
	{
		Swap_items(array, k, high);
		print_array(array, size);
	}
	if (k - low > 1)
		Quick_sort_range(array, low, k - 1, size);
	if (high - k > 1)
		Quick_sort_range(array, k + 1, high, size);
}

/**
 * quick_sort - Sorts an array using quick sort algorithm
 * in an ascending order
 * @array: array to be sorted.
 * @size: size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		Quick_sort_range(array, 0, size - 1, size);
	}
}
