/*
 * insertion.c
 * 
 * provides insertion sorting for arrays
 */

#include <stdio.h>

void isort (int *, int);

int main ()
{
  int array[] = {5, 4, 3, 2, 1};
  isort (array, 5);
  for (int i = 0; i < 5; i++) {
    printf ("%i\n", array[i]);
  }
}

void isort (int *arr, int len)
{
  int i;
  for (i = 1; i < len; i++) {
    int key = arr[i];
    int j = i - 1;
    while (i > 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

