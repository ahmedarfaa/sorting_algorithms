#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - sorts an arr of integers in ascending order
 * @arr: The array
 * @size: size of the arr
 */
void selection_sort(int *arr, size_t size)
{
	size_t x, stp, mini_indx;
	int tmp;

	for (stp = 0; stp < size - 1; stp++)
	{
		mini_indx = stp;
		for (x = stp + 1; x < size; x++)
		{
			if (arr[x] < arr[mini_indx])
				mini_indx = x;
		}

		if (mini_indx != stp)
		{
			tmp = arr[stp];
			arr[stp] = arr[mini_indx];
			arr[mini_indx] = tmp;
			print_array(arr, size);
		}
	}
}
