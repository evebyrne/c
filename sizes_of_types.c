#include <stdio.h>
#include <assert.h>

void test(){
    assert(1==1);
    printf("passed tests\n");
}

int main(){  
//    short = 2
//    long = 8
//    int = 4
   unsigned short int usi = 432;  /* fully qualified -- unsigned short int */
   unsigned short us = 432;
   short si = 432;                /* short int */
   unsigned long uli = 432;       /* unsigned long int */
   long l = 432;
   long int li = 432;
   int i = 432;
   unsigned int ui = 432;

   printf("size of unsigned short int: %d\n", sizeof(usi));
   printf("size of unsigned short: %d\n", sizeof(us));
   printf("size of short: %d\n", sizeof(si));
   printf("size of unsigned long: %d\n", sizeof(uli));
   printf("size of long: %d\n", sizeof(l));
   printf("size of long int: %d\n", sizeof(li));
   printf("size of int: %d\n", sizeof(i));
   printf("size of unsigned int: %d\n", sizeof(ui));



   return 0;
}
