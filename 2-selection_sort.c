#include "sort.h"

/**
 * selection_sort - A function to sort an array using
 * the selection sort algorithm.
 *
 * @array: A given array to be sorted.
 * @size: Size of the array.
 */
void selection_sort(int *array, size_t size)
{
    unsigned int i, j, min_index;

    int temp;

    if (size < 2 || array == NULL)
        return;

    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (i != min_index)
        {
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
            print_array(array, size);
        }
    }
}
