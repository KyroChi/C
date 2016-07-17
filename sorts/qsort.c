/*
 *            Q S O R T . C
 * 
 *      Authors: Kyle Chickering
 *    Description: qsort algorithem in c
 *            Usage:
 */

#include <stdio.h>
#include <string.h>

int main (int argc, char *argv)
{
  
}

void strsort (void *v[], int left, int right, int (*comp)(void *, void *))
{
  int i, last;
}

void swap (void *a[], int i, int j)
{
    void *temp = a[i];
        a[i] = a[j];
        a[j] = temp;
}
