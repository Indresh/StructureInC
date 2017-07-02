#include<stdio.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes

// Add a node with data field 60 in between and before node with data field 30


/* #############
   OUTPUT:

   Linked List
   Before:
   10--> 20--> 30--> 40--> 50--> NULL

   Linked List
   After:
   10--> 20--> 60--> 30--> 40--> 50--> NULL
   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };


typedef struct node *NODE;		// NODE is user defined datatype of struct type

// function prototype

void show_list(NODE first);      
NODE AddNode_Before_NodeY(NODE IndexPtr,struct node _ToBeAdded);

int main()
{
NODE head;

/* Below Nodes can be dynamicaaly allocated using malloc() or calloc() function */

struct node a={10,NULL};
struct node b={20,NULL};
struct node c={30,NULL};
struct node d={40,NULL};
struct node e={50,NULL};

struct node f={60,NULL};		// Node to be added before node wih data field 30

a.next=&b;
b.next=&c;
c.next=&d;
d.next=&e;

head=&a;		// head pointer pointing to first element in the list

// Call show_list() to display whole linked list

printf("\n\nLinked List\nBefore:\n"); 

show_list(head);

head=AddNode_Before_NodeY(head,f);

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

NODE AddNode_Before_NodeY(NODE IndexPtr,struct node Add_This_Node)
 {
  /* Copy the address of IndexPtr(act as head) to first pointer
     otherwise, whole linked list address will be lost,
     since IndexPtr pointer will traverse to end  */

  // prev pointer will point one node behind to that of IndexPtr

  NODE first=NULL,prev=NULL;
  first=IndexPtr; 

  if(IndexPtr==NULL)			//Check, if list is empty, then return Add_This_Node itself
   return NULL;
  else
   { while(IndexPtr->next!=NULL)              // Traverse through list in case 30 is not found in the given linked list
      { if(IndexPtr->data!=30)          // 30 is hard-coded, this value can be read from standard input 
         { prev=IndexPtr;
           IndexPtr=IndexPtr->next;
         }
        else
         { Add_This_Node.next=prev->next;	// Add_This_Node.next=IndexPtr; (will also work)
           prev->next=&Add_This_Node;
           break;
         }
      }

     /* Here, code to handle a scenario when an element is not found in list
        can be implemented, then we cannot add node 60 in the liast at any position,
        In that case, return same list again, without any modification. */

     return first;				 // return address of first node
   }
 }

