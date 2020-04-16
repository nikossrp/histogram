#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

int main(int argc, char *argv[])
 { int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);
    Key v; Item item;
    STinit(maxN);
    printf("Enter 10 keys\n");  //from makefile it take as input 10 keys by default
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
