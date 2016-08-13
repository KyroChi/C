/*
 *                                 E D S . C
 *
 * This file contains all of the elementry data structures as described in the
 * MIT press book 'Introduction to Algoritems' by Cormen et.al. The header file
 * for the functions defined in eds.c is ds.h and is also the header file for
 * the other data structrue implementation files.
 *
 * Authors: Kyle Chickering (kylechickering@yahoo.com)
 * Description: Stacks, Queues, Linked Lists and Binary Trees
 */

#include "ds.h"
#include "khelper.h"
#include <stdlib.h>
#include <stdio.h>

/*
 * Create a new stack data structure
 */
k_stack_t *
new_stack (void)
{
        k_stack_t *ptr = malloc(sizeof(stack_t));
        ptr->size = 0;
        ptr->values = malloc(STACK_MAX * sizeof(void*));
        return ptr;
}

/*
 * Check if the stack is empty
 */
int
stack_empty (k_stack_t *stack)
{
        if (stack->size == 0)
                return 1;

        return 0;
}

/*
 * Push a value onto the stack
 */
void
stack_push (k_stack_t *stack, void *data)
{
        stack->values[stack->size++] = data;
        return;
}

void
stack_push_int (k_stack_t *stack, int data)
{
        int *ptr = malloc(sizeof(int));
        *ptr = data;
        stack_push(stack, ptr); return;
}

/*
 * Pop value from the stack, no error checking for an empty stack
 */
void *
stack_pop (k_stack_t *stack)
{
        void *data = stack->values[stack->size - 1];
        free(stack->values[stack->size - 1]);
        stack->size--;
        return data;
}

/*
 * Assumes that the values being printed are integers
 */
void
stack_print_int (k_stack_t *stack)
{
        int size = stack->size;

        while (size)
                printf("%i ", *((int*) stack->values[--size]));

        printf("\n"); return;
}

/*
 * Allocate memory for a new queue
 */
QuPtr nqueue (void)
{
        QuPtr ptr = malloc(sizeof(Queue));
        ptr->head = ptr->tail = 0;
        return ptr;
}

/*
 * Add a value x to the queue queue
 */
void enqueue (QuPtr queue, int x)
{
        queue->values[queue->tail] = x;

        if (queue->tail == QUEUE_MAX) {
                queue->tail = 0;
                return;
        }

        queue->tail++;
}

/*
 * "cut" the queue line, adds an element at the head of the queue
 */
void cutq (QuPtr queue, int x)
{

}

/*
 * Leave the queue early, pulls the last element put in from the queue
 */
int leaveq (QuPtr queue)
{
        return 0;
}

/*
 * Get latest value from the queue. No error checking for an empty queue
 */
int dequeue (QuPtr queue)
{
        int out = queue->values[queue->head];

        if (queue->head == QUEUE_MAX)
                queue->head = 0;
        else
                queue->head++;

        return out;
}

/*
 * Print queue with highest prioirity first
 */
void pqueue (QuPtr queue)
{
        int current = queue->head;

        do
                printf("%i ", queue->values[current]);

        while (current++ != queue->tail);

        printf("\n");

}

/*
 * New linked list, no entry, use ptr->key = int
 */
llptr nlist (int value)
{
        llptr ptr = malloc(sizeof(llptr));
        ptr->next = NULL;
        ptr->prev = NULL;
        ptr->key = value;
        return ptr;
}

/*
 * search list for k, return NULL if k is not found
 */
llptr slist (llptr list, int k)
{
        do {
                if (list->key == k)
                        return list;
                else
                        list = list->next;

        } while (list);

        return NULL;
}

/*
 * Insert a list node into the list
 */
void ilist (llptr list, llptr k)
{
        while (list->next)
                list = list->next;

        list->next = k;
        k->prev = list;
}

/*
 * Print the values inside of a linked list starting at the list entry list
 */
void plist (llptr list)
{
        do {
                printf("%i ", list->key);
                list = list->next;
        } while (list);

        printf("\n");
}

/*
 * Remove entry from the list list
 */
void rmlist (llptr list, llptr entry)
{
        if (entry->prev)
                entry->prev->next = entry->next;

        if (entry->next)
                entry->next->prev = entry->prev;

        free(entry);
}

/* Print a singly linked list, should also work for doubly linked lists */
void print_singly_linked_list (sllptr list)
{
        do {
                printf("%i ", list->key);
                list = list->next;

        } while (list);

        printf("\n");
        return;
}

/* Creates a new singly linked list entry */
sllptr new_singly_linked_entry (int value)
{
        sllptr ptr = malloc(sizeof(sllptr));
        ptr->key = value;
        ptr->next = NULL;
        return ptr;
}

/* Insert a new intry into an existing singly linked list */
void insert_into_linked_list (sllptr list, int value)
{
        sllptr new = new_singly_linked_entry(value);

        while (list->next)
                list = list->next;

        list->next = new;
}

/* Search a singly linked list for the value value */
sllptr search_singly_linked_list (sllptr list, int value)
{
        do {

                if (list->key == value)
                        return list;
                list = list->next;

        } while (list);

        return NULL;
}

/* Remove an entry from a singly linked list */
void remove_from_singly_linked_list (sllptr list, sllptr entry)
{
        do {
                if (list->next == entry) {
                        list->next = entry->next;
                        free(entry);
                        return;
                }

                list = list->next;

        } while (list);
}

/* Reverse a singly linked list, use list = reverse_singly_linked_list */
sllptr reverse_singly_linked_list_bad (sllptr list)
{
        int ii = 0;
        int size = SLL_SIZE;
        sllptr * links = malloc(size * sizeof(sllptr)), out;

        do {
                if (ii == size) {
                        size += SLL_SIZE;
                        links = realloc(links, size * sizeof(sllptr));
                }

                links[ii] = list;
                list = list->next;

                ii++;

        } while (list);

        out = new_singly_linked_entry(links[ii - 1]->key);

        for (ii = ii - 2; ii >= 0; ii--)
                insert_into_linked_list(out, links[ii]->key);

        return out;
}

/* Much faster implementation for reversing a singly linked list */
sllptr reverse_singly_linked_list (sllptr list)
{
        sllptr new_list = 0, next;

        while(list) {
                next = list->next;
                list->next = new_list;
                new_list = list;
                list = next;
        }

        return new_list;
}

/*
 * Create a new XOR linked list
 */
xorll_t *
new_xor_list (void)
{
        xorll_t *ptr = malloc(sizeof(xorll_t));

        ptr->head = NULL;
        ptr->tail = NULL;

        return ptr;
}

/*
 * Insert a new element into the XOR linked list
 */
void
xor_list_insert (xorll_t *list, void *data)
{
        xorll_entry_t *prev, *new, *ptr = malloc(sizeof(xorll_entry_t));

        if (!list->head) {
                list->head = ptr;
                ptr->ptr = NULL;
        } else {
                ptr->ptr = xor_links(list->tail, NULL);

                new = ptr;
                prev = xor_links((list->tail)->ptr, NULL);
                (list->tail)->ptr = xor_links(prev, new);
        }

        ptr->data = data;
        list->tail = ptr;

        return;
}

void
xor_list_insert_int (xorll_t *list, int data)
{
        int *ptr = malloc(sizeof(int));
        *ptr = data;
        xor_list_insert(list, ptr);
        return;
}

/*
 * XORs two addresses in memory and returns the result. Do not refrence this new
 * address without first applying the XOR function. This can be used for
 * traversing the xor linked list and for creating the new xor list pointers.
 * This function should not be used outside of xor linked list functions unless
 * in the contex of something other than xor linked lists.
 */
xorll_entry_t *
xor_links (xorll_entry_t *link_1, xorll_entry_t *link_2)
{
        return (xorll_entry_t*) ((uintptr_t) link_1 ^ (uintptr_t) link_2);
}

/*
 * Assumes that the data contained in the xor list are pointers to integers,
 * this function will cause seg faults if the data is not an integer, there is
 * no error checking so be careful
 */
void
xor_list_print_int (xorll_t *list)
{
        xorll_entry_t *prev, *current, *next;

        prev = NULL;
        current = list->head;

        while (current) {
                printf("%i ", *((int*)current->data));
                next = xor_links(prev, current->ptr);
                prev = current;
                current = next;
        }

        printf("\n");
        return;
}

/*
 * Searches for an integer in the XOR list, this assumes that the values in the
 * XOR list are integers, returns NULL if no entries are found matching the
 * supplied integer.
 */
xorll_entry_t *
xor_list_search_int (xorll_t *list, int find)
{
        xorll_entry_t *prev, *current, *next;

        prev = NULL;
        current = list->head;

        while(current) {
                if (*((int*)current->data) == find) {
                        return current;
                }
                next = xor_links(prev, current->ptr);
                prev = current;
                current = next;
        }

        return NULL;
}

/*
 * Assumes that the entry being removed is actually a part of the linked list
 * no error checking
 */
void
xor_list_remove_entry (xorll_t *list, xorll_entry_t *entry)
{
        xorll_entry_t *prevprev, *prev, *current, *next, *nextnext;

        prev = NULL;
        current = list->head;

        while(current) {
                if (current == entry) {
                        next = xor_links(prev, current->ptr);
                        prev = xor_links(next, current->ptr);
                        nextnext = xor_links(current, next);
                        prevprev = xor_links(current, prev);

                        prev->ptr = xor_links(prevprev, next);
                        next->ptr = xor_links(nextnext, prev);

                        // free_xor_list_entry(current);
                        return;
                }
                next = xor_links(prev, current->ptr);
                prev = current;
                current = next;
        }
        return;
}

void
free_xor_list_entry (xorll_entry_t *entry)
{
        free(entry->ptr);
        free(entry->data);
        free(entry);
        return;
}

void
xor_reverse_list (xorll_t *list)
{
        xorll_entry_t *tmp = list->head;
        list->head = list->tail;
        list->tail = tmp;
        return;
}
