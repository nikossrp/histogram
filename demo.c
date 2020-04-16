/* This code is from "Algorithms in C, Third Edition, by Robert Sedgewick, Addison-Wesley, 1998. */

#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

int main(int argc, char *argv[])
 { int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item;
    STinit(maxN);
    printf("Enter 10 keys\n");  //apo to makefile pairnei 10 keys.
    for (N = 0; N < maxN; N++)
      {
        if (sw) v = ITEMrand();
          else if (ITEMscan(&v) == EOF) break;
        key(item) = v; 
        STinsert(item);
 
      }
   // printf("head->N: %d\n", STcount());
    printf("\n");
    printf("Keys\tFrequency\n");
    STsort(ITEMshow); printf("\n");
 
 }
