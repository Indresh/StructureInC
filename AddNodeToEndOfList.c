#include<stdio.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes


/* #############
   OUTPUT:

   Linked List
   Before:
   10--> 20--> 30--> 40--> 50--> NULL

   Linked List
   After:
   10--> 20--> 30--> 40--> 50--> 60--> NULL
   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };


typedef struct node *NODE;		// NODE is user defined datatype of struct type

// function prototype

void show_list(NODE first);      
NODE AddToLastNode(NODE IndexPtr,struct node _ToBeAdded);

int main()
{
NODE head;

/* Below Nodes can be dynamicaaly allocated using malloc() or calloc() function */

struct node a={10,NULL};
struct node b={20,NULL};
struct node c={30,NULL};
struct node d={40,NULL};
struct node e={50,NULL};

struct node f={60,NULL};

a.next=&b;
b.next=&c;
c.next=&d;
d.next=&e;

head=&a;		// head pointer pointing to first element in the list

// Call show_list() to display whole linked list

printf("\n\nLinked List\nBefore:\n"); 

show_list(head);

head=AddToLastNode(head,f);

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

NODE AddToLastNode(NODE IndexPtr,struct node Add_This_Node)
 {
  /* Copy the address of IndexPtr(act as head) to first pointer
     otherwise, whole linked list address will be lost,
     since IndexPtr pointer will traverse to end  */

  NODE first=IndexPtr; 

  if(IndexPtr==NULL)			//Check, if list is empty, then return Add_This_Node itself
   first=&Add_This_Node; 
  else
   { while(IndexPtr->next!=NULL)        // Reach till last node
       IndexPtr=IndexPtr->next;

     /* Once Last Node is reached, add the node represented by Add_This_Node object
        (here f is the node to be added, defined in main(), Add_This_Node 
        is formal parameter) */

      IndexPtr->next=&Add_This_Node;     // save address of Add_This_Node pointer in IndexPtr->next
   } 
 
  return first;				 // return address of first node
 }

