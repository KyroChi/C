#include <stdio.h>
#include <stdlib.h>

int ** array_of_array();

int main (int argc, char **argv)
{
  printf("%i\n", array_of_array()[0][0]);
}

int **
array_of_array ()
{
  int **arr;
  int *parr;
  arr = &parr;
  parr = malloc(sizeof(int));
  parr[0] = 5;
  return arr;
}
