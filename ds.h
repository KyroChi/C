/* Stacks */
#define STACK_MAX 100

typedef struct stack * StackPtr;
typedef struct stack {
        int values[STACK_MAX];
        int size;
} Stack;

StackPtr nstack (void);
int stack_empty (StackPtr stack);
void spush (StackPtr stack, int x);
int spop (StackPtr stack);

/* Queues */
#define QUEUE_MAX 100

typedef struct queue * QuPtr;
typedef struct queue {
        int values[QUEUE_MAX];
        int head;
        int tail;
} Queue;

QuPtr nqueue (void);
void enqueue (QuPtr queue, int x);
int dequeue (QuPtr queue);
void pqueue (QuPtr queue);

/*
 * Doubly linked list implementation, create a nlist() and add new nodes to the
 * created linked list element with the ilist() function.
 */
typedef struct linked * llptr;
typedef struct linked {
        int key;
        llptr next;
        llptr prev;
} ListEntry;

llptr nlist (int value);
llptr slist (llptr list, int k);
void ilist (llptr list, llptr k);
void plist (llptr list);
void rmlist (llptr list, llptr entry);
