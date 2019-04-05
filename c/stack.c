#include<stdio.h>

static int size;

// BUILDING A LINKED LIST
typedef struct List
{
   int value;
   struct List *next;
}llist;

// PUSH FUNCTION
llist *push(llist *head, int n)
{
  llist *elem=NULL;
  elem = (llist *) malloc(sizeof(llist));
  printf("pushing %d into the stack!\n",n);
  elem->value=n;
  elem->next=head;
  return elem;
}

int main()
{
  /* TOP is the floating head, last is the last element of the stack, 
     Intially No Element, TOP and LAST point to NULL;
     After that TOP keeps floating, with every new element added,
     while last stays put at the dead end */

  llist *top=NULL;
  llist *last=NULL;
  top = (llist *) malloc(sizeof(llist));
  last = (llist *) malloc(sizeof(llist));
  top=last;

  printf("Adding elements to the list!\n");
  do
  {
    top=push(top,++size);
  }while(size<5);

  printf("Size of the list is %d\n",size);
  do
  {
    printf("poping from the stack!\n");
    printf("%d\n",top->value);
  }
  while(top=top->next); 
  free(last);
  free(top);
}
