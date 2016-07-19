#include <stdlib.h>
#include <stdio.h>

/* Function declerations */
int heap_parent (int index);
int heap_left (int index);
int heap_right (int index);

void max_heapify(int * heap, int index, int heap_size);
void build_max_heap (int * heap, int heap_size);

void min_heapify(int * heap, int index, int heap_size);
void build_min_heap (int * heap, int heap_size);

void heap_sort (int * array, int length);
