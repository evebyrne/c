#include <stdio.h>
#include <assert.h>
/*
Dereferencing a ptr that points to an invalid memory location causes a fatal error
often reported as a segfault
*/ 
struct Mystruct{
  int intnum;
  float floatnum;
};

void test(){
    int a,b;
    int *p;
    
    a = 10;
    p = &a;
    assert(a == *p);
    b = *p;
    p = &b;
    assert(b==a);
    assert(b == *p);

    *p = 12;
    assert(b==12);

    printf("passed tests\n");
}

void struct_test(){
    struct Mystruct astruct;
    struct Mystruct* pastruct;
    
    pastruct = &astruct;
    // equivalent ways
    (*pastruct).intnum = 12;
    // "the floatnum that pastruct points to"
    pastruct->floatnum = 13.0;

    assert(astruct.intnum == 12);
    assert(astruct.floatnum == 13.0);
}

int main(){  
   test();
   struct_test();

   return 0;
}
