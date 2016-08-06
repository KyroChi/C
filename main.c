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
        llptr list = nlist(5);
        ilist(list, nlist(4));
        if (slist(list, 4))
                printf("Yay its here\n");

        plist(list);
        rmlist(list, slist(list, 4));
        plist(list);
}
