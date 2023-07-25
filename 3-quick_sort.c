#include "sort.h"

/**
 * swap - A function to swap elements in an array.
 *
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_sort - Function to sort an array
 * using the Lomuto partitioning scheme.
 *
 * @arr: Pointer to the array.
 * @size: Size of the array.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 */
void lomuto_sort(int *arr, size_t size, int low, int high)
{
	int *pivot = arr + high;
    	int i, j;

    if (high <= low)
        return;

    for (i = j = low; j < high; j++)
    {
        if (arr[j] < *pivot)
        {
            if (i < j)
            {
                swap(arr + j, arr + i);
                print_array(arr, size);
            }
            i++;
        }
    }

    if (arr[i] > *pivot)
    {
        swap(arr + i, pivot);
        print_array(arr, size);
    }

    lomuto_sort(arr, size, low, i - 1);
    lomuto_sort(arr, size, i + 1, high);
}

/**
 * quick_sort - Function to sort an array using
 * the quick sort algorithm.
 *
 * @array: Pointer to the array.
 * @size: Size of the array.
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    lomuto_sort(array, size, 0, size - 1);
}

