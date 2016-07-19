/*
 *                    H E A P . C
 *
 * Heap related algorithms
 */

#include "heap.h"
#include "linked.h"
#include "sorts.h"

/* return the parent index in the heap */
int heap_parent (int index)
{
  return index / 2;
}

/*
 * Return a node pointer to the left child of the node at the given index.
 */
int heap_left (int index)
{
  return 2 * index;
}

/*
 * Return a node pointer to the right child of the node at the given index.
 */
int heap_right (int index)
{
  return 2 * index + 1;
}

/*
 * Move the element at index i to its appropriate location in the heap
 */
void max_heapify (int * heap, int index, int heap_size)
{
  int left, right, largest;
  left = heap_left(index);
  right = heap_right(index);

  if (left <= heap_size && heap[left] > heap[index])
    largest = left;
  else
    largest = index;

  if (right <= heap_size && heap[right] > heap[largest])
    largest = right;

  if (largest != index) {
    swap(heap, largest, index);
    max_heapify(heap, largest, heap_size);
  }
}

/*
 * Move the element at index i to its appropriate location in the heap
 */
void min_heapify (int * heap, int index, int heap_size)
{
  int left, right, smallest;
  left = heap_left(index);
  right = heap_right(index);

  if (left <= heap_size && heap[left] < heap[index])
    smallest = left;
  else
    smallest = index;

  if (right <= heap_size && heap[right] < heap[smallest])
    smallest = right;

  if (smallest != index) {
    swap(heap, smallest, index);
    min_heapify(heap, smallest, heap_size);
  }
}

/*
 * Build a max heap from an array
 */
void build_max_heap (int * heap, int heap_size)
{
  for (int i = (heap_size - 1) / 2; i >= 0; i--)
    max_heapify(heap, i, heap_size);
}

/*
 * Build a min heap from an array
 */
void build_min_heap (int * heap, int heap_size)
{
  for (int i = (heap_size - 1) / 2; i >= 0; i--)
    min_heapify(heap, i, heap_size);
}

/*
 * Sort an array using a heap
 */
void heap_sort (int * array, int length)
{
  length--;
  build_max_heap(array, length);

  for (int i = length; i > 0; i--) {
    swap(array, 0, i);
    length--;
    max_heapify(array, 0, length);
  }
}
