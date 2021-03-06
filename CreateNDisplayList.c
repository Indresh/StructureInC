#include<stdio.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes


/* #############
   OUTPUT:

   10-->20-->30-->40-->50-->NULL

   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };

int main()
{
struct node a={10,NULL};

struct node b={20,NULL};
struct node c={30,NULL};
struct node d={40,NULL};
struct node e={50,NULL};

a.next=&b;
b.next=&c;
c.next=&d;
d.next=&e;



 struct node *head;
  head=&a;
  while(head!=NULL)
   { 
    printf("%d-->",head->data);
    head=head->next;
   }
  printf("NULL");		// add NULL explicitly to print NULL, as head pointer has already reached NULL
  printf("\n");                     
  return 0;
}
