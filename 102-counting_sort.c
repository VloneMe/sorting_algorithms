#include "sort.h"

/**
 * get_max_elem - function to get the maximum value in an array
 * @array: An array
 * @size: The size of the array
 *
 * Return: The maximum integer in the array
 */
int get_max_elem(int *array, int size)
{
	int max_value, i;

	for (max_value = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}
	return (max_value);
}

/**
 * counting_sort - function to sort an array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: An array to be sorted
 * @size: The size of the array
 *
 * Description: Prints the counting of an array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sortedArr, max, i;

	if (array == NULL || size < 2)
		return;

	sortedArr = malloc(sizeof(int) * size);
	if (sortedArr == NULL)
		return;
	max = get_max_elem(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sortedArr);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sortedArr[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sortedArr[i];

	free(sortedArr);
	free(count);
}
