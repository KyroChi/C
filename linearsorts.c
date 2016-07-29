/*
 *                     L I N E A R S O R T S . C
 *
 * This file contians sorting algorithms that run in linear time, namely
 * counting sort and radix sort.
 */

#include <stdio.h>
#include <stdlib.h>
#include "khelper.h"

/*
 * array is the array to be sorted, k is the integer in range [0..k - 1] to be
 * sorted.
 */
int * counting_sort (int * array, int len, int k)
{
        int * tmp, * out, i, j;

        tmp = malloc(k * sizeof(int));
        out = malloc(len * sizeof(int));

        for (i = 0; i < k; i++)
                tmp[i] = 0;

        for (j = 0; j < len; j++)
                ++tmp[array[j]];

        for (i = 1; i < k; i++)
                tmp[i] = tmp[i] + tmp[i - 1];

        for (j = len - 1; j >= 0; j--) {
                out[--tmp[array[j]]] = array[j];
        }

        free(tmp);
        return out;
}
