/*
 * Trying to write a linked list
 */

#include <stdlib.h>
#include <stdio.h>

struct ll {
  int val;
  struct ll * next;
};

struct dll {
  int val;
  struct dll * next;
  struct dll * prev;
};

void appll (struct ll * list, int val);
void rmlli (struct ll * list, int index);
void printll (struct ll * list);

int main (int argc, char ** argv)
{
  struct ll * list = malloc(sizeof(struct ll));
  list->val = 5;
  list->next = NULL;
  printll(list);
  appll(list, 8);
  appll(list, 7);
  appll(list, 18);
  appll(list, 37);
  
}

/*
 * Append to linked list
 */
void appll (struct ll * list, int val)
{
  struct ll * new_entry = malloc(sizeof(struct ll));

  while (list->next)
    list = list->next;
  
  new_entry->val = val;
  new_entry->next = NULL;
  list->next = new_entry;
}

/*
 * Print Linked List
 */
void printll (struct ll * list)
{
  while(list->next) {
    printf("%i ", list->val);
    list = list->next;
  } 
  printf("%i\n", list->val);
}
