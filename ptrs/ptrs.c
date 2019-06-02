#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*
Pointers = address
& = address of 
* = dereferencing = get reference to the value the ptr is pointing at
   and for declaration 
*/

struct mystruct{
  int intnum;
  float floatnum;
};

void test(){
  // Declaring 
  
  // ptr to an int
  int *p;
  // ptr to a struct of type mystruct
  struct mystruct *ptrstruct;
  // var1 = ptr to long, var2=long
  long * var1, var2;
  // ptr to a ptr to an int
  int **p2;

  // Assigning 
  int num = 2;
  struct mystruct estruct ={1,2};
  p = &num;
  ptrstruct = &estruct;
  p2 = &p;

  assert((*p)==num);
  assert((*ptrstruct).intnum==1);
  assert((*ptrstruct).floatnum==2);
  assert(*(*p2)==num);

  printf("passed tests\n");
}

void test_malloc(){
  // know that its a ptr to a struct of type mystruct so know how much memory
  // to allocate ??? 
  struct mystruct *estructptr;
  // returns ptr to dynamically allocated memory
  estructptr = malloc(sizeof estructptr);
  struct mystruct estruct={1,2};

  estructptr = &estruct;

  assert((*estructptr).intnum==estruct.intnum);
  assert((*estructptr).floatnum==estruct.floatnum);
}




int main(){  
   test();
   return 0;
}
