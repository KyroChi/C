#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
  int *a = malloc(sizeof(int));
  int *b = malloc(sizeof(int));
  int c, d;
  c = 5;
  d = 10;
  a = &c;
  b = &d;
  int *m = malloc(sizeof(int));
  m = (void*) ((long) a ^ (long) NULL);
  if (!((int*) ((long) a ^ (long) m)))
    printf("NULL\n");

  printf("%i\n", *((int*) ((long) m ^ (long) NULL)));
}
