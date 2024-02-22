#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays of array[].
 * First sub-array is array[l..m]
 * Second sub-array is array[m+1..r]
 * @array: The array to be sorted
 * @l: Left index of the sub-array
 * @m: Middle index of the sub-array
 * @r: Right index of the sub-array
 */
void merge(int *array, size_t l, size_t m, size_t r)
{
    size_t i, j, k;
    size_t n1 = m - l + 1;
    size_t n2 = r - m;

    int *left = malloc(sizeof(int) * n1);
    int *right = malloc(sizeof(int) * n2);

    if (!left || !right)
    {
        free(left);
        free(right);
        return;
    }

    for (i = 0; i < n1; i++)
        left[i] = array[l + i];

    for (j = 0; j < n2; j++)
        right[j] = array[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right[j];
        j++;
        k++;
    }

    free(left);
    free(right);
}

/**
 * merge_sort_recursive - Recursive function to perform merge sort
 * @array: The array to be sorted
 * @l: Left index of the sub-array
 * @r: Right index of the sub-array
 */
void merge_sort_recursive(int *array, size_t l, size_t r)
{
    if (l < r)
    {
        size_t m = l + (r - l) / 2;

        merge_sort_recursive(array, l, m);
        merge_sort_recursive(array, m + 1, r);

        printf("Merging...\n");
        printf("[left]: ");
        print_array(array + l, m - l + 1);
        printf("[right]: ");
        print_array(array + m + 1, r - m);
        merge(array, l, m, r);
        printf("[Done]: ");
        print_array(array + l, r - l + 1);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge Sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    merge_sort_recursive(array, 0, size - 1);
}
