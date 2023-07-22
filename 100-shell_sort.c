#include "sort.h"
/**
 * _Swap - swaped 2 values.
 * @arr: arr for swap values.
 * @x: First index
 * @y: Second index
 */
void _Swap(int *arr, int x, int y)
{
	int temp;

	if (arr[x] != arr[y])
	{
		temp = arr[x];
		arr[x] = arr[y];
		arr[y] = temp;
	}
}

/**
 * shell_sort - sort the list & print the changes
 * @arr: array to sort.
 * @size: Size of arr
 */
void shell_sort(int *arr, size_t size)
{
	size_t h = 0,  x, y;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (x = h; x < size; x++)
			for (y = x; y >= h && arr[y] < arr[y - h]; y -= h)
				_Swap(arr, y, y - h);
		h /= 3;
		print_array(arr, size);
	}
}
