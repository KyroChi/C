/*
 *                          Q U I C K S O R T . C
 *
 * An implementation of quicksort as described in the
 * "Introduction to Algorithms" book by Cormen et.al. Quicksort typically has
 * a better running time than the other sorting algorithems, however there exist
 * boundry cases where other sorting algorithms may be better suited for sorting
 * a given list. This file also contains an implementation of randomized
 * quicksort, which attempts to alleviate some of the pitfalls presented by
 * quicksort by randomly partitioning rather than going in a structured order.
 */

#include <stdlib.h> // for rand()
#include <time.h>
#include "sorts.h" // for swap()

/*
 * Quicksort your arrays. This is **normally** faster than heap sort but certain
 * boundry cases exist where heap sort will be faster to run. Sometimes even
 * insertion sort will beat quick sort, notably on almost sorted arrays.
 * int * array: The array to be sorted.
 * int head: The index of the first element.
 * int tail: The index of the last element.
 */
void quick_sort (int * array, int head, int tail)
{
        int q;

        if (head < tail) {
                q = partition(array, head, tail);
                quick_sort(array, head, q - 1);
                quick_sort(array, q + 1, tail);
        }
}

/*
 * Partition an array in place into two halves and return the index of the
 * number that lays between the high and low values. All indicies less than the
 * return value will have values that are less than the element at i. All the
 * elements to the right will have a value greater than the element at i.
 * int * array: The array to be partitioned.
 * int head: The index of the first element.
 * int tail: The index of the last element.
 */
int partition (int * array, int head, int tail)
{
        int x, i, j;

        x = array[tail];
        i = head - 1;

        for (j = head; j < tail; j++) {
                if (array[j] <= x) {
                        i++;
                        swap(array, i, j);
                }
        }

        swap(array, i + 1, tail);
        return i + 1;
}

/*
 *
 */
void random_quick_sort(int * array, int head, int tail)
{
        int q;

        if (head < tail) {
                q = random_partition(array, head, tail);
                random_quick_sort(array, head, q - 1);
                random_quick_sort(array, q + 1, tail);
        }
}

/*
 *
 */
int random_partition (int * array, int head, int tail)
{
        int i;
        srand(time(NULL));
        i = rand() % (tail + 1 - head) + head;

        swap(array, head, i);

        return partition(array, head, tail);
}
