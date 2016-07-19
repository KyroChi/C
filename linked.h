#include <stdlib.h>
#include <stdio.h>

/*
 * Singally linked list
 * only allows for forwards list traversal
 */
typedef struct linked_list * llptr;
typedef struct linked_list {
  int value;
  llptr next;
} LinkList;

/*
 * Doublely linked list
 * allows for forewards and backwards list traversal
 */
typedef struct double_linked_list * dllptr;
typedef struct double_linked_list {
  int value;
  dllptr next;
  dllptr prev;
} DLinkList;

/* **linked.c function declerations** */
void printll (llptr list);
void llpush (llptr list, int value);
int llpop (llptr list);
llptr llshift (llptr list, int value);
int llunshift (llptr list);
int * lltoa (llptr list);

/* double linked list functions */
void printdll (dllptr list);
void appdll (dllptr list, int value);
