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

}

int f1(struct Mystruct *pStruct, int i, long *lp){
    return i;
}

int f2(struct Mystruct *pStruct, int *mValue){
    int j;
    long array[25];
    long *pAA;
     
    pAA = &array[13];
    j = f1( pStruct, *mValue, pAA );
    return j;
}

void test_f1_f2(){
    struct Mystruct astruct;
    struct Mystruct *pastruct = &astruct;
    int mvalue = 1;
    // dont forget the *******
    int *pmvalue= &mvalue;
    int f = f2(pastruct, pmvalue);
    assert(f==1);
}

int main(){  
   test();
   test_malloc_fxn();
   test_f1_f2();

   printf("passed tests\n");
   return 0;
}
