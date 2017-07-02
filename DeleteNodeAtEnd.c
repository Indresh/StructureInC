#include<stdio.h>
#include<stdlib.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes

// Delete the last node in the linked list


/* #############
   OUTPUT:

   Linked List
   Before:
   10--> 20--> 30--> 40--> 50--> NULL
   The deleted node is 50

   Linked List
   After:
   10--> 20--> 30--> 40--> NULL
   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };


typedef struct node *NODE;		// NODE is user defined datatype of struct type

// function prototype

void show_list(NODE first);      
NODE DeleteNodeAtEnd(NODE IndexPtr);

int main()
{
NODE head;

/* Below Nodes can be dynamicaaly allocated using malloc() or calloc() function */

struct node a={10,NULL};
struct node b={20,NULL};
struct node c={30,NULL};
struct node d={40,NULL};
struct node e={50,NULL};

a.next=&b;
b.next=&c;
c.next=&d;
d.next=&e;

head=&a;		// head pointer pointing to first element in the list

// Call show_list() to display whole linked list

printf("\n\nLinked List\nBefore:\n"); 

show_list(head);

head=DeleteNodeAtEnd(head);

// Linked list is updated

printf("\nLinked List\nAfter:\n");

show_list(head);

return 0;
}

//show_list() function definition

void show_list(NODE first)
 {
  while(first!=NULL)
   { printf("%d--> ",first->data);
     first=first->next;
   }

  printf("NULL");			// explicitly print NULL as head pointer has reached end of the list
  printf("\n");
  
}

NODE DeleteNodeAtEnd(NODE IndexPtr)
 {
  /* Copy the address of IndexPtr(act as head) to first pointer
     since IndexPtr pointer will traverse to end  */

  NODE first=NULL;
  first=IndexPtr; 

  if(IndexPtr==NULL)			//Check, if list is empty,return NULL
   return NULL;
  else
   { while(IndexPtr->next->next!=NULL)              // Check two nodes at a time, a little faster
      IndexPtr=IndexPtr->next;

   } 

  printf("The deleted node is %d\n",IndexPtr->next->data);
  free(IndexPtr->next->next);

  IndexPtr->next=NULL;
      
  return first;				 // return address of first node
 }
