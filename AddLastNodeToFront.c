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

   Linked List
   After:
   50--> 10--> 20--> 30--> 40--> NULL

   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };


typedef struct node *NODE;		// NODE is user defined datatype of struct type

// function prototype

void show_list(NODE first);      
NODE add_lst_nd_to_front(NODE IndexPtr);

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

head=add_lst_nd_to_front(head);

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

NODE add_lst_nd_to_front(NODE IndexPtr)
 {
  /* Copy the address of IndexPtr(act as head) to first pointer
     since IndexPtr pointer will traverse to end  */

  NODE first=NULL,prev=NULL;
  first=IndexPtr; 

  if(IndexPtr==NULL)			//Check, if list is empty,return NULL
   return NULL;

  if(IndexPtr->next==NULL)		// If , only one node present, return that node
   return first;
  else
   { while(IndexPtr->next!=NULL)              
      { prev=IndexPtr;
        IndexPtr=IndexPtr->next;
      }
     
     prev->next=NULL;                   // Assign Second last node as null
     IndexPtr->next=first;		// Point last node to where first is pointing
   } 

  first=IndexPtr;			// point 'first' to where IndexPtr is pointing, to make last node as first node in the list

  return first;				 // return address of first node
 }
