/*
 * Trying to write a linked list
 */

#include "linked.h"

/*
 *
 */
void printll (llptr list)
{
  while (list->next) {
    printf("%i ", list->value);
    list = list->next;
  }
  printf("%i\n", list->value);
}

/*
 * Push a value to the end of the linked list
 * append value to the linked list
 */
void llpush (llptr list, int value)
{
  llptr new_entry = malloc(sizeof(llptr));
  new_entry->value = value;
  new_entry->next = NULL;

  while (list->next)
    list = list->next;
  
  list->next = new_entry;
}

/*
 * Pop the last value off the linked list
 * removes the value from the ll too
 */
int llpop (llptr list)
{
  int value;
  llptr last = list;
  
  while(list->next) {
    last = list;
    list = list->next;
  }

  last->next = NULL;

  value = list->value;
  free(list);
  return value;
  
}
 
/*
 * Shift or pre-pend a value to the list
 * use as l = llshift(l, int) returns a llptr to the modified list not void
 */
llptr llshift (llptr list, int value)
{
  llptr new_entry = malloc(sizeof(llptr));
  
  new_entry->value = value;
  new_entry->next = list;

  return new_entry;
}

int llunshift (llptr list)
{
  return 1;
}

/*
 * Linked list to array
 * make a linked list into an array
 */
int * lltoa (llptr list)
{
  int i, j, *array;
  llptr org = list;
  
  i = 1;
  while (list->next) {
    list = list->next;
    i++;
  }

  list = org;

  array = malloc(i * sizeof(int));
  
  for (j = 0; j < i; j++) {
    array[j] = list->value;
    list = list->next;
  }

  return array;
  
}

void llrm (llptr list, llptr entry)
{
  while (list->next != entry)
    list = list->next;

  list->next = entry->next;
}

/*
 * Free all the links in a linked list
 */
void freell (llptr list)
{
  llptr last;
  llptr * allptr;
  int i, j;
  
  allptr = malloc(sizeof(llptr));
  i = 1;
    
  while(list->next) {
    allptr = realloc(allptr, sizeof(allptr) + sizeof(llptr));
    allptr[i] = list;
    list = list->next;
    i++;
  }
    
  allptr[i] = list;
    
  for (j = 0; j <= i; j++)
    free(allptr[j]);
  
  free(allptr);
}

/*
 * Print all the values in a doublely linked list
 */
void printdll (dllptr list)
{
  while (list->next) {
    printf("%i ", list->value);
    list = list->next;
  }
  printf("%i\n", list->value);
}

/*
 *
 */
void appdll (dllptr list, int value)
{

}
