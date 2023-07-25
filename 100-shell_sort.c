#include "sort.h"

/**
 * shell_sort - function to sort an array using shell sort algorithm
 * @a: pointer to an array
 * @size: size of an array
 */
void shell_sort(int *a, size_t size)
{
	int tmp;
	size_t i, intervals, j;

	for (intervals = 1; intervals < (size / 3);)
		intervals = intervals * 3 + 1;
	for (; intervals >= 1; intervals /= 3)
	{
		for (i = intervals; i < size; i += 1)
		{
			tmp = a[i];
			for (j = i; (j >= intervals) && (a[j - intervals] > tmp); j -= intervals)
			{
				a[j] = a[j - intervals];
			}
			a[j] = tmp;
		}
		print_array(a, size);
	}
}
