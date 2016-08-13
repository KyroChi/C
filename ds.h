/* Stacks */
#define STACK_MAX 100

/* Stack data structure, first in last out */
typedef struct k_stack_s {

        void **values;
        int size;

} k_stack_t;

k_stack_t * new_stack (void);
int stack_empty (k_stack_t *stack);
void stack_push (k_stack_t *stack, void *data);
void stack_push_int (k_stack_t *stack, int data);
void * stack_pop (k_stack_t *stack);
void stack_print_int (k_stack_t *stack);

/* Queues */
#define QUEUE_MAX 100

/* Queue data structure, first in first out */
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

/* Singly linked list implementation */
#define SLL_SIZE 10

typedef struct sll * sllptr;
typedef struct sll {
        int key;
        sllptr next;
} SingleLinkedList;

void print_singly_linked_list (sllptr list);
sllptr new_singly_linked_entry (int value);
void insert_into_linked_list (sllptr list, int value);
sllptr search_singly_linked_list (sllptr list, int value);
void remove_from_singly_linked_list (sllptr list, sllptr entry);
sllptr reverse_singly_linked_list_bad (sllptr list);
sllptr reverse_singly_linked_list (sllptr list);

/* XOR Linked list entry */
typedef struct xorll_entry_s {

        void *data;
        struct xorll_entry_s *ptr;

} xorll_entry_t;

/* XOR Linked list with head and tail */
typedef struct xorll_s {

        xorll_entry_t *head;
        xorll_entry_t *tail;

} xorll_t;

xorll_t * new_xor_list (void);
void xor_list_insert (xorll_t *list, void *data);
void xor_list_insert_int (xorll_t *list, int data);
xorll_entry_t * xor_links (xorll_entry_t *link_1, xorll_entry_t *link_2);
void xor_list_print_int (xorll_t *list);
xorll_entry_t * xor_list_search_int (xorll_t *list, int find);
void xor_list_remove_entry (xorll_t *list,xorll_entry_t *entry);
void free_xor_list_entry (xorll_entry_t *entry);
void xor_reverse_list (xorll_t *list);
