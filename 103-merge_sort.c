#include "sort.h"

/**
 * merge_subarr - Function to merge two sorted subarrays into a single sorted array.
 *
 * @subarr: Pointer to the subarray of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @front: The front index of the subarray.
 * @midIndex: The middle index of the subarray.
 * @back: The ending index of the subarray.
 */
void merge_subarr(int *subarr, int *buff, size_t front, size_t mid, size_t back)
{
    size_t i, j, k = 0;

    printf("Merging...\n[left]: ");
    print_array(subarr + front, mid - front);

    printf("[right]: ");
    print_array(subarr + mid, back - mid);

    for (i = front, j = mid; i < mid && j < back; k++)
        buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
    for (; i < mid; i++)
        buff[k++] = subarr[i];
    for (; j < back; j++)
        buff[k++] = subarr[j];
    for (i = front, k = 0; i < back; i++)
        subarr[i] = buff[k++];

    printf("[Done]: ");
    print_array(subarr + front, back - front);
}

/**
 * sort_recursive - Implement the merge sort algorithm through recursion.
 *
 * @subarr: Pointer to the subarray of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The ending index of the subarray.
 */
void sort_recursive(int *subarr, int *buff, size_t front, size_t back)
{
    size_t mid;

    if (back - front > 1)
    {
        mid = front + (back - front) / 2;
        sort_recursive(subarr, buff, front, mid);
        sort_recursive(subarr, buff, mid, back);
        merge_subarr(subarr, buff, front, mid, back);
    }
}

/**
 * merge_sort - Sort an array of integers in ascending order using the merge sort algorithm.
 *
 * @array: Pointer to the array of integers to sort.
 * @size: Size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (array == NULL || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (buffer == NULL)
        return;

    sort_recursive(array, buffer, 0, size);

    free(buffer);
}
