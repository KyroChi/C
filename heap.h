#include <stdlib.h>
#include <stdio.h>

/* 
 * Pointer and structure for a tree node.
 * The node has an index and value, along with a pointer to the left and right
 * nodes.
 */
typedef struct node * Nodeptr;

typedef struct node {
  int index;
  int value;
  Nodeptr left;
  Nodeptr right;
} Node;

/*
 * Node tree, collection of indexed nodes
 * Contains a list of node pointers, indexed from top to bottom, and an array
 * who's values are associated with the indices. For example tree_array[0] will
 * return the value of the node at index 0. (Top most node)
 */
typedef struct tree * Treeptr;

typedef struct tree {
  Nodeptr * nodes;
  int * tree_array;
} Tree;

Nodeptr parent (Tree *, int);
Nodeptr left (Tree *, int);
Nodeptr right (Tree *, int);

Nodeptr new_node (int, int);

