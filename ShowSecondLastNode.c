#include<stdio.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes
// Display second last node in the linked list


/* #############
   OUTPUT:

   10-->20-->30-->40-->50-->NULL

   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };


typedef struct node *NODE;		// NODE is user defined datatype of struct type

void show_list(NODE first);      // function prototype

NODE SecondLastNode(NODE first);

int main()
{
NODE head,head_copy;
struct node a={10,NULL};

struct node b={20,NULL};
struct node c={30,NULL};
struct node d={40,NULL};
struct node e={50,NULL};

a.next=&b;
b.next=&c;
c.next=&d;
d.next=&e;

// Call show_list() function to display nodes in the linked list
head_copy=head;
head=&a;
show_list(head);
NODE _PointToSecondLastNode=SecondLastNode(head);
printf("The second last node is %d\n",_PointToSecondLastNode->data);

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

NODE SecondLastNode(NODE first)
 { NODE prev=NULL;
   // Check if list is empty or has only one node in list (both conditions need to be checked)

   if(first==NULL||first->next==NULL)
     return NULL;
   else
     { while(first->next!=NULL)
        { prev=first;
          first=first->next;
        }
     }

   return prev;
 }

   


