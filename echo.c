#include <stdio.h>

/* echo: echo command line args */
int main (int argc, char **argv)
{
  while(--argc) {
    printf("%s", *(++argv));
    if (argc-1) {
      printf(" ");
    }
  }
  printf("%c", '\n');
}
