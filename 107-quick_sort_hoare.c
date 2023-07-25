#include "sort.h"


/**
*Swap - a fn that swaps two elements
*@arr: array
*@itm1: item 1
*@itm2: item 2
*/
void Swap(int *arr, ssize_t itm1, ssize_t itm2)
{
	int tmp;

	tmp = arr[itm1];
	arr[itm1] = arr[itm2];
	arr[itm2] = tmp;
}
/**
 *hoare_partition - a fn that implement the hoare way
 *@arr: array
 *@first: first element
 *@last: last eleement
 *@size: array size
 *Return: position of last element
 */
int hoare_partition(int *arr, int first, int last, int size)
{
	int current = first - 1, finder = last + 1;
	int pvt = arr[last];

	while (1)
	{

		do {
			current++;
		} while (arr[current] < pvt);
		do {
			finder--;
		} while (arr[finder] > pvt);
		if (current >= finder)
			return (current);
		Swap(arr, current, finder);
		print_array(arr, size);
	}
}
/**
 *qk_sort - a function that implements the qksort
 *@arr: array
 *@frst: first element
 *@lst: last element
 *@size: size of array
 */
void qk_sort(int *arr, ssize_t frst, ssize_t lst, int size)
{
	ssize_t pstion = 0;

	if (frst < lst)
	{
		pstion = hoare_partition(arr, frst, lst, size);
		qk_sort(arr, frst, pstion - 1, size);
		qk_sort(arr, pstion, lst, size);
	}
}
/**
 *quick_sort_hoare - prepare the terrain to quicksort algorithm
 *@arr: array
 *@size: arr size
 */
void quick_sort_hoare(int *arr, size_t size)
{
	if (!arr || size < 2)
		return;
	qk_sort(arr, 0, size - 1, size);
}
