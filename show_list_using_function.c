#include<stdio.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes
// Display all nodes using a function


/* #############
   OUTPUT:

   10-->20-->30-->40-->50-->NULL

   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };

void show_list(struct node *head);      // function prototype

int main()
{
struct node *head;
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
head=&a;

show_list(head);
return 0;
}

//show_list() function definition

void show_list(struct node *head)
 {
  while(head!=NULL)
   { printf("%d--> ",head->data);
     head=head->next;
   }

  printf("NULL");			// explicitly print NULL as head pointer has reached end of the list
  printf("\n");
}
