#include <stdio.h>

void printa (int * array, int elements)
{
        for (int i = 0; i < elements; i++)
                printf("%i ", array[i]);

        printf("\n");
}
