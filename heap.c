/*
 *            H E A P . C
 *
 */

/*
 * Nodeptr, Node and Tree data types pulled from heap.h
 */
#include "heap.h"

int main (int argc, char ** argv)
{
  Nodeptr a = new_node(0, 3);
  printf("%i\n", a->value);
}

/* Return a node pointer to the parent node to the given index. */
Nodeptr
parent (Tree * tree, int index)
{
  return tree->nodes[index / 2];
}

/*
 * Return a node pointer to the left child of the node at the given index.
 */
Nodeptr
left (Tree * tree, int index)
{
  return tree->nodes[2 * index];
}

/*
 * Return a node pointer to the right child of the node at the given index.
 */
Nodeptr
right (Tree * tree, int index)
{
  return tree->nodes[2 * index + 1];
}

Nodeptr
new_node(int index, int val)
{
  Nodeptr n;
  n->index = index;
  n->value = val;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void
add_to_tree(int val)
{
  
}
