#include<stdio.h>


struct s1
 { int a;
   float b;
   char c;
 };

struct s1 obj1={10,2.5,'a'};       // initialization

int main()
 { printf("------------------------\n");
   printf("obj1.b=%f,  obj1.a=%d,  obj1.c=%c\n",obj1.b,obj1.a,obj1.c);
   struct s1 *node=&obj1;
   printf("(*node).a=%d, (*node).c=%c, (*node).b=%f\n",(*node).a,(*node).c,(*node).b);
   return 0;
 } 


