/*
 * Medians and order statistics
 */

#include "ordstats.h"
#include "sorts.h" // For random_partition()

int minimum (int * array, int len)
{
        int i, min = array[0];

        for (i = 1; i < len; i++)
                if (min > array[i])
                        min = array[i];

        return min;
}

int maximum (int * array, int len)
{
        int i, max = array[0];

        for (i = 1; i < len; i++)
                if (max < array[i])
                        max = array[i];

        return max;
}

/*
 * Selects the ith smallest element from the array array
 * array is the input array, start is the index of the first element, end is the
 * index of the last element and i is the ith posistion. For example 1 returns
 * the smallest value from the array while using the array's length returns the
 * largest.
 */
int randomized_select (int * array, int start, int end, int i)
{
        int middle, k;

        if (start == end)
                return array[start];

        middle = random_partition (array, start, end);

        k = middle - start + 1;

        if (i == k)
                return array[middle];

        else if (i < k)
                return randomized_select(array, start, middle - 1, i);

        else
                return randomized_select(array, middle + 1, end, i - k);
}
