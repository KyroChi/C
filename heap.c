/*
 *                                H E A P . C
 *
 * Heap related algorithms. This file contains simple standard heap and priority
 * queue related functions. The functions implemeted here assume that the heap
 * or priority queue is represented as an array of integers, where each index in
 * the array corresponds to the same index as the heap node containing the
 * integer. Some functions implemented here assume that the supplied heap or
 * array is already in a max or min heap state prior to being passed to the
 * calling function.
 *
 * All implementaions contained in this file are based off of the psuedo-code
 * provided in the textbook "Introduction to Algorithms" by Cormen et.al, third
 * edition. This book is published by the MIT press and pdf versions can be
 * found online or physical copies may be purchased online.
 */

#include "linked.h"
#include "sorts.h"

/*
 * Returns the index of the parent node to the node at index i in a heap.
 */
int heap_parent (int index)
{
  return index / 2;
}

/*
 * Retun the index of the left child node to the node at index i in the heap.
 */
int heap_left (int index)
{
  return 2 * index;
}

/*
 * Return the index of the right child node to the node at index i in the heap.
 */
int heap_right (int index)
{
  return 2 * index + 1;
}

/*
 * Takes the element at the given index and inserts it into its correct location
 * in the heap. This function assumes that the array is a max heap.
 * int * array: The heap.
 * int index: The index of the element to be heapified.
 * int heap_size: The number of elements in the heap.
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
 * Takes the element at the givin index and inserts it into its correct location
 * in the heap. This function assumes the array is a min heap.
 * int * array: The heap,
 * int index: The index of the element to be hepified.
 * int heap_size: The number of elements in the heap.
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
 * Takes an array and builds a maximum heap from the elements. The heap follows
 * the constraint that A[i] <= A[parent(i)].
 * int * array: The array being converted to a heap.
 * int heap_size: The number of elements in the heap (array).
 */
void build_max_heap (int * array, int heap_size)
{
  for (int i = (heap_size - 1) / 2; i >= 0; i--)
    max_heapify(array, i, heap_size);
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

/*
 * Return the maximum value from the heap
 */
int heap_maximum(int * array)
{
  return array[0];
}

/*
 * Assumes a max heap, shifts max heap value, re-organizes new heap
 */
int heap_extract_max (int * array, int heap_size)
{
  int max;

  heap_size--;

  if (heap_size < 1) {
    printf("Heap Underflowed\n");
    return -2147483647;
  }

  max = array[0];
  array[0] = array[heap_size];
  heap_size--;
  max_heapify(array, 0, heap_size);
  return max;
}

/*
 * Increase the heap node at index i and have it placed in the heap
 */
void heap_increase_key (int * array, int index, int key)
{
  if (key < array[index]) {
    printf("\033[31mnew key is smaller than current key\033[0m\n");
    return;
  }

  array[index] = key;

  while (index > 0 && array[heap_parent(index)] < array[index]) {
    swap(array, index, heap_parent(index));
    index = heap_parent(index);
  }
}

/*
 * Inserts value at the head, ie the key must have a greater value than any
 * other value in the heap
 */
void max_heap_insert (int * array, int heap_size, int key)
{
  array[heap_size] = -2147483647;
  heap_increase_key(array, heap_size, key);
}

/*
 *
 */
int heap_minimum (int * array)
{
  return array[0];
}

/*
 * Assumes run on a min heap
 */
int heap_extract_min (int * array, int heap_size)
{
  int min;

  heap_size--;

  if (heap_size < 1) {
    printf("Heap Underflowed\n");
    return -2147483647;
  }

  min = array[0];
  array[0] = array[heap_size];
  heap_size--;
  min_heapify(array, 0, heap_size);
  return min;
}

void heap_decrease_key (int * array, int index, int key)
{
  if (key > array[index]) {
    printf("key is larger than current key");
    return;
  }

  array[index] = key;

  while (index > 0 && array[heap_parent(index)] > array[index]) {
    swap(array, index, heap_parent(index));
    index = heap_parent(index);
  }
}

void min_heap_insert (int * array, int heap_size, int key)
{
  array[heap_size] = 2147483647;
  heap_decrease_key(array, heap_size, key);
}
