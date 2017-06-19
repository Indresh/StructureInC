#include<stdio.h>

// including two structures, calling one structure into other.

struct s1
 { int a;
   float b;
   char c;
 };


struct s2
 { float d;
   struct s1 StrObj1;              // object pointing to structure s1
   int f;
 };

struct s2 obj2={10.25,10,5.3,'a',20};



//struct s1 StrObj1;        //initialization

int main()
 { printf("------------------------\n");
   printf("obj2.StrObj1.a=%d, obj2.StrObj1.c=%c, obj2.d=%f\n",obj2.StrObj1.a,obj2.StrObj1.c,obj2.d);
   struct s2 *node2=&obj2;
   printf("(*node2).StrObj1.a=%d, (*node2).d=%f, (node2->StrObj1).c=%c\n",(*node2).StrObj1.a,(*node2).d,(node2->StrObj1).c);
   return 0;
 } 


