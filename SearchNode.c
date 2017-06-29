#include<stdio.h>

// Author : Indresh(kmr.ndrsh@gmail.com)
// Linked list with simple manually created nodes

// Search element "SearchX" in a given linked list


/* #############
   OUTPUT:

   10-->20-->30-->40-->50-->NULL

   ############ */

struct node
 { int data;
   struct node *next;       // self refrential structure.
 };


typedef struct node *NODE;		// NODE is user defined datatype of struct type

// function prototype

void show_list(NODE first);      

void SearchElement(int SearchX,NODE IndexPtr);

int main()
{
NODE head;
int SearchX;
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

show_list(head);

// call SearchElement() to find element, entered via either by command line or as an input from user
// This example shows an input from the user

printf("Enter data node to be searched: ");
scanf("%d",&SearchX);

SearchElement(SearchX,head);




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

void SearchElement(int SearchX,NODE IndexPtr)
 {
  if(IndexPtr==NULL)			//Check, if list is empty
    printf("List is empty");
  else
   { do
      { if(IndexPtr->data==SearchX)
         { printf("\nKey Found\n");
           break;
         }
        IndexPtr=IndexPtr->next;
      }while(IndexPtr!=NULL);

     if(IndexPtr==NULL)
      printf("\nKey not found\n");
   } 
  
 }

