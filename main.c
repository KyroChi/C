#include <stdlib.h>
#include <stdio.h>

#include "ds.h"
#include "heap.h"
#include "sorts.h"
#include "khelper.h"
#include "ordstats.h"

/* If you don't know what main is may I reccomend cracking a book... */

int main (int argc, char ** argv)
{
        xorll_t *list = new_xor_list();
        int *a = 0, *b = 0, *c = 0;
        int d = 10;
        int e = 25;
        int f = 32;
        a = &d;
        b = &e;
        c = &f;
        xor_list_insert(list, a);
        xor_list_insert(list, b);
        xor_list_insert(list, c);
        xor_list_print_int(list);
        xor_reverse_list(list);
        xor_list_print_int(list);
        xor_list_insert_int(list, 6);
        xor_list_insert_int(list, 25);
        xor_list_insert_int(list, 24);
        xor_list_print_int(list);
        xor_reverse_list(list);
        xor_list_print_int(list);
        xor_list_remove_entry(list, xor_list_search_int(list, 6));
        xor_list_print_int(list);
}
