
#include <stdio.h>
#include <stdlib.h>
#include "Item.h"

typedef struct STnode* link;
//N einai oi komvoi pou exei apo katw tou o komvos
struct STnode { Item item; link l, r; int N; int f;};  //f = frequency of key

static link head, z;

link NEW(Item item, link l, link r, int N)
{ link x = malloc(sizeof *x);
    x->item = item; x->l = l; x->r = r; x->N = N; x->f = 1; //init frequency
    return x;
}

/* initialization operation */  
void STinit()
  { head = (z = NEW(NULLitem, NULL, NULL, 0)); }

/* count operation */
int STcount() { return head->N; }

/* search operation */
Item searchR(link h, Key v)
{ Key t = key(h->item);
    if (h == z) return NULLitem;
    if eq(v, t) return h->item;
    if less(v, t) return searchR(h->l, v);
             else return searchR(h->r, v);
}
  
Item STsearch(Key v)
{ return searchR(head, v); }


int  frequency(link x, Key v)
{
  return head->f;
}


link selectNode(link h,Key v) 
{

    Key t = key(h->item);
    if (h == z) return NULL;
    if eq(v, t) return h;
    if less(v, t) return selectNode(h->l, v);
             else return selectNode(h->r, v);
}


link STselectNode(int v)  //select the node with element v.
{ 
  return selectNode(head, v);
}


/* recursive insert operation */
link insertR(link h, Item item)
{ Key v = key(item), t = key(h->item); 
  link x;
    if (h == z) return NEW(item, z, z, 1);
    if (less(v, t))
         h->l = insertR(h->l, item);
    else h->r = insertR(h->r, item);
    (h->N)++; return h;
}
  
void STinsert(Item item)
{ 
  link x;
  if(STselectNode(item) != NULL) {  //if the item exist just increase the frequency.
    x = STselectNode(item);
    (x->f)++;
  } else{
    head = insertR(head, item);
  }
}


/* rotation auxiliary functions */
link rotR(link h)
  { link x = h->l; h->l = x->r; x->r = h;
    return x; }

link rotL(link h)
{ link x = h->r; h->r = x->l; x->l = h;
    return x; }


/* Insertion at the root, commented out, note that the counters at each node are not updated
link insertT(link h, Item item)
  { Key v = key(item);
    if (h == z) return NEW(item, z, z, 1);
    if (less(v, key(h->item)))
      { h->l = insertT(h->l, item); h = rotR(h); }
    else
      { h->r = insertT(h->r, item); h = rotL(h); }
    return h;
  }

void STinsert(Item item)
  { head = insertT(head, item); }

*/

/* sort operation */
void sortR(link h, void (*visit)(Item))
{
    if (h == z) return;
    sortR(h->l, visit);
    visit(h->item);printf("\t%d\n" , h->f); //print histogram.
    sortR(h->r, visit);
}
  
void STsort(void (*visit)(Item))
  { sortR(head, visit); }



/* select operation */
Item selectR(link h, int k)
  { 
    int t;
    if (h == z) return NULLitem;
    t = (h->l == z) ? 0 : h->l->N;
    if (t > k) return selectR(h->l, k);
    if (t < k) return selectR(h->r, k-t-1);
    return h->item;
  }

Item STselect(int k)  
  { return selectR(head, k); }

/* partition auxiliary function */
link partR(link h, int k)
  { int t = h->l->N;
    if (t > k )
      { h->l = partR(h->l, k); h = rotR(h); }
    if (t < k )
      { h->r = partR(h->r, k-t-1); h = rotL(h); }
    return h;
  }

/* recursive deletion operation */
link joinLR(link a, link b)
  {
    if (b == z) return a;
    b = partR(b, 0); b->l = a;
    return b;
  }
  
link deleteR(link h, Key v)
  { link x; Key t = key(h->item);
    if (h == z) return z;
    if (less(v, t)) h->l = deleteR(h->l, v);
    if (less(t, v)) h->r = deleteR(h->r, v);
    if (eq(v, t))
      { x = h; h = joinLR(h->l, h->r); free(x); }
    return h;
  }
  
void STdelete(Key v)
  { head = deleteR(head, v); }


