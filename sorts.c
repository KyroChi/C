/*
 *                                   S O R T S . C
 *
 * Sorting algorithems for sorting intergers
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

//int main ()
//{
//  int array[] = {3, 41, 52, 26, 38, 57, 9, 49};
//  bsort (array, 7);
//  for (int i = 0; i < 8; i++) {
//    printf("%i\n", array[i]);
//  }
//  return 0;
//}
//
/*
 * swap: swaps two members of an array
 */
void swap (int *array, int b, int c)
{
  int tmp = array[b];
  array[b] = array[c];
  array[c] = tmp;
}

/*
 * ssort: sorts an array of integers using the selection sort method
 */
void ssort (int *a, int len)
{
  int ii, jj, low;
  for(ii = 0; ii < len; ii++) {
    low = ii;
    for(jj = ii + 1; jj < len; jj++) {
      if (a[jj] < a[low]) {
	low = jj;
      }
    }
    if (a[ii] != a[low]) {
      swap (a, ii, low);
    }
  }
}

/*
 * isort: sorts and array of integers using the insertion sort method
 */
void isort (int *a, int len)
{
  int ii;
  for (ii = 1; ii < len; ii++) {
    int key = a[ii];
    int jj = ii - 1;
    while (ii > 0 && a[jj] > key) {
      a[ii + 1] = a[jj];
      jj = jj - 1;
    }
    a[jj + 1] = key;
  }
}

/*
 * msort: sorts an array of integers recusivly using merge
 */
void msort (int *array, int left, int right)
{
  int middle;
  if (left < right) {
    middle = (right + left) / 2;
    msort(array, left, middle);
    msort(array, middle + 1, right);
    merge(array, left, middle, right);
  }
}

/*
 * merge: merge two sorted arrays
 * int *array: The array to have a section merged
 * int left: The index of the first element in the section of the array to
 * be merged. 
 * int middle: The index of the middle element in the section of the array
 *  to be merged. In even arrays this will be the last element of the first 
 * half.
 * int right: The index of the last element in the section of the array to
 * be merged.
 * return: void
 */
void merge (int *array, int left, int middle, int right)
{
  int i, j, k;
  int n1 = middle - left + 1;
  int n2 = right - middle;
  int *l_array, *r_array;
  
  l_array = malloc(n1 * sizeof(int));
  r_array = malloc(n2 * sizeof(int));

  for (i = 0; i < n1; i++)
    l_array[i] = array[left + i];
  for (j = 0; j < n2; j++)
    r_array[j] = array[middle + j + 1];

  k = left;
  i = 0;
  j = 0;
  
  while (i < n1 && j < n2) {
    if (l_array[i] <= r_array[j]) {
      array[k] = l_array[i];
      i++;
    } else {
      array[k] = r_array[j];
      j++;
    }
    k++;
  }
  
  while (i < n1) {
    array[k] = l_array[i];
    i++; k++;
  }
  
  while (j < n2) {
    array[k] = r_array[j];
    j++; k++;
  }

  free(l_array);
  free(r_array);
}

/*
 * bsort: sort using bubble sort, the most efficient sorting algorithem of
 * all time :D O(n^2)
 */
void bsort (int *array, int last_index)
{
  int i, j;
  for (i = 0; i < last_index; i++)
    for (j = last_index; j > i + 1; j--)
      if (array[j] < array[j - 1])
	swap(array, j, j - 1);
}




