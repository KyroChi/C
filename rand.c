#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sorts.h"

void unsort (int *, int);
void printarr (int *, int);

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
