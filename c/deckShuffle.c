#include<stdio.h>
#include<stdlib.h>
#define MAX 32768 // sticking to the max length of the Integers and focusing on the logic to start with.

/* QUESTION:
You are given a deck containing 313 cards. While holding the deck:
  1. Take the top card off the deck and set it on the table
  2. Take the next card off the top and put it on the bottom of the deck in your hand.
  3. Continue steps 1 and 2 until all cards are on the table. This is a round.
  4. Pick up the deck from the table and repeat steps 1-3 until the deck is in the original order.

Write a program to determine how many rounds it will take to put the deck back into the original order.
This will involve creating a data structure to represent the order of the cards.
This program should be written in C.
It should take a number of cards in the deck as a command line argument and write the result to stdout.
*/

/* The high-level Algorithm is;
   1.) DECK is a QUEUE, add function adds the card to the rear-end of the deck, del fuction chops and returns the top element in the deck.
   2.) TABLE is a STACK, where the discarded top most card from the deck is stacked.
   3.) When the DECK is empty, the cards from the TABLE STACK is popped (top-most first) and pushed back into the DECK queue
   4.) Then the DECK is verified with ORIGINAL ARRAY of cards (numbers here); if it matches, end of program, else repeat step 1 to 3 again

   For this algorithm, The program runs in the O(n) for each shuffle (in terms of big-O notation).

*/

static int size; // size of the deck (passed as an argument to the program)
int i; // Iterator in all the for LOOPS in the program
int table[MAX]; // STACK
int deck[MAX]; // QUEUE
int top = -1; // EMPTY STACK
int front= 0; //EMPTY QUEUE
int rear = 0; // EMPTY QUUE

/* This Function is used to finally verify the deck to original order */
int isAlligned(int arr[])
{
  for (i=0;i<size-1;i++)
  {
    if(arr[i]!=deck[i]) return 0;
  }
  return 1;
}

/* To push the cards into TABLE stack */
void push(int elem)
{
  if(top == (MAX-1)) printf("Stack Overflow\n");
  else
  {
    top=top+1;
    table[top] = elem;
  }
}

/* To Pop the cards from the TABLE stack */
int pop()
{
  int retVal=0;
  // if top = -1, stack (table) empty.
  if(top != -1)
  {
    retVal=table[top];
    top=top-1;
  }
  return(retVal);
}

/* To add element(card) to the rear-end of the DECK queue */
void add(int elem)
{
  if(rear>MAX)
  {
    printf("QUEUE FULL!\n");
  }
  else
  {
    deck[rear]=elem;
    rear++;
  }
}

/* To chop the front-most element(card) from the queue */
int del()
{
  int retVal=0;
  // when front = rear, QUEUE(deck) is empty
  if(front != rear)
  {
    retVal=deck[front];
    front++;
  }
  return(retVal);
}

/* MAIN PROGRAM */
int main(char argc, char* argv[])
{
  int arr[atoi(argv[1])]; // to store the original array of elements (original sort of cards)
  int shuffleCount=0; // intially, shuffle count is zero
  int card; // temp variable to the hold the value of the card transiently

  // taking the number of cards from the argument list
  if(argc>1) size=atoi(argv[1]);
  printf("size of deck is: %d\n",size);

  // initializing the array and the deck.
  for(i=0;i<size;i++)
  {
    arr[i]=i+1;
    deck[i]=i+1;
  }

  // defining the front and rear to manipulate the deck array as a QUEUE data-structure.
  front= 0;
  rear = size;

  printf("ORIGINAL DECK ORDER:\n");
  for(i=0;i<size;i++) printf("%d ",deck[i]);

  do
  {
    // POPPING the first card from deck(QUEUE), pushing it into table stack, till deck is empty
    do
    {
      card=del();
      if(card) push(card);
      card=del();
      if(card) add(card);
    }
    while(card);

    shuffleCount++;

    // POPPING the cards from table(STACK) and pushing it into the DECK Queue for re-iteration, if necessary
    front= 0;
    rear = 0;
    do
    {
      card=pop();
      if(card) add(card);
    }while (card);

    // printf("\nDECK ORDER: \n");
    // for(i=0;i<size;i++) printf(" %d\t",deck[i]);
  }
  while (!isAlligned(arr));
  printf("\nThe Deck is back to original form after %d shuffles!\n",shuffleCount);
  return 0;
}
