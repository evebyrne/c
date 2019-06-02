#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct Mystruct{
  int intnum;
  float floatnum;
};

static struct Mystruct mystruct1, mystruct2, mystruct3, mystruct4;

struct Mystruct* fxn(int num){
  struct Mystruct* pMyReturnStruct;
  if(num ==1) pMyReturnStruct = &mystruct1;
  else if(num==2) pMyReturnStruct = &mystruct2;
  else if(num==3) pMyReturnStruct = &mystruct3;
  else pMyReturnStruct = &mystruct4;

  return pMyReturnStruct;
}

struct Mystruct* badfxn(){
    struct Mystruct mystruct;
    struct Mystruct* pmystruct = &mystruct;

    return pmystruct;
}

struct Mystruct* mallocfxn(){
    struct Mystruct mystruct;
    struct Mystruct* pmystruct = malloc(sizeof pmystruct);
    pmystruct = &mystruct;

    return pmystruct;
}

void test_malloc_fxn(){
    struct Mystruct* pmystruct = mallocfxn();
}

void test_bad_fxn(){
    // this doesnt work...
    // struct Mystruct* pmystruct = badfxn();
}

void test(){
    struct Mystruct* pMyStruct = fxn(1);
    assert(pMyStruct == &mystruct1); 

    pMyStruct = fxn(4);
    assert(pMyStruct == &mystruct4); 



    assert(1==1);
    printf("passed tests\n");
}

int main(){  
   test();
   return 0;
}
