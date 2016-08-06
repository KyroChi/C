#include "ds.h"
#include "khelper.h"

#include <stdlib.h>
#include <stdio.h>

/*
 * Create a new stack data structure
 */
StackPtr nstack (void)
{
        StackPtr ptr = malloc(sizeof(Stack));
        ptr->size = 0;
        return ptr;
}

/*
 * Check if the stack is empty
 */
int stack_empty (StackPtr stack)
{
        if (stack->size == 0)
                return 1;

        return 0;
}

/*
 * Push a value onto the stack
 */
void spush (StackPtr stack, int x)
{
        stack->values[stack->size++] = x;
}

/*
 * Pop value from the stack, no error checking for an empty stack
 */
int spop (StackPtr stack)
{
        return stack->values[--stack->size];
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
