#include <stdlib.h>
#include <stdio.h>

/* Function declerations */
int heap_parent (int index);
int heap_left (int index);
int heap_right (int index);

/* max heaps */
void max_heapify(int * heap, int index, int heap_size);
void build_max_heap (int * heap, int heap_size);
int heap_maximum (int * array);
int heap_extract_max (int * array, int heap_size);
void heap_increase_key (int * array, int index, int key);
void max_heap_insert (int * array, int heap_size, int key);

/* min heaps */
void min_heapify(int * heap, int index, int heap_size);
void build_min_heap (int * heap, int heap_size);
int heap_minimum (int * array);
int heap_extract_min (int * array, int heap_size);
void heap_decrease_key (int * array, int index, int key);
void min_heap_insert (int * array, int heap_size, int key);

void heap_sort (int * array, int length);
