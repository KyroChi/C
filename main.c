#include <stdlib.h>
#include <stdio.h>

#include "heap.h"
#include "linked.h"
#include "sorts.h"
#include "khelper.h"

int main (int argc, char ** argv)
{
        int heap[10] = {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
        printa(heap, 10);
        max_heapify(heap, 1, 10);
        printa(heap, 10);

        int heap2[7] = {1, 7, 3, 4, 5, 6, 2};
        printa(heap2, 7);
        min_heapify(heap2, 1, 7);
        printa(heap2, 7);

        int heap3[10] = {1, 34, 56, 87, 43, 23, 10, 11, 65, 99};
        printa(heap3, 10);
        build_max_heap(heap3, 10);
        printa(heap3, 10);

        build_min_heap(heap3, 10);
        printa(heap3, 10);

        heap_sort(heap3, 10);
        printa(heap3, 10);
}
