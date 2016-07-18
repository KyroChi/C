#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorts/sorts.h"

void unsort (int *, int);
void printarr (int *, int);

int main (int argc, char ** argv)
{
  int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  printarr(arr, 10);
  unsort(arr, 10);
  printarr(arr, 10);
}

void unsort (int * array, int len)
{
  int i, r, tmp;
  for (i = 0; i < len; i++) {
    r = rand() % len;
    tmp = array[i];
    array[i] = array[r];
    array[r] = tmp;
    srand(time(NULL) * i);
  }
}

void printarr (int * array, int len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", array[i]);
  printf("\n");
}
