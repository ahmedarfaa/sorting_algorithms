#include "sort.h"
#include <stdio.h>


/**
 * bubble_sort - sorting an-arr of integers in Ascending order
 * @arr: array of integer
 * @size: size of the arr
 */
void bubble_sort(int *arr, size_t size)
{
	size_t i;
	int temp, sorted;

	if (!arr || size == 0)
		return;

	do {
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				sorted = 0;
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				print_array(arr, size);
			}
		}

	} while (sorted == 0);
}
