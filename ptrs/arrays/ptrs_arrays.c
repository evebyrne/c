#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// 1. a variable declared as an array acts as a ptr to that type. 
//    when on its own pts to first element in array
// 2. ptrs can be indexed like an array

struct Mystruct{
  int intnum;
  float floatnum;
};

//  finds the float num in a struct which has an int num ==x
float fxn(struct Mystruct * pmystruct, int mystructsize, int x){
  int i;
  for(i=0;i<mystructsize;i++){
    if(pmystruct[i].intnum==x){
        return pmystruct[i].floatnum;
    }
  }
  return 0.0;
}

void test(){
    struct Mystruct array[4];
    assert(sizeof(array)==32);
    // dereference
    // size of first element in array
    assert(sizeof(*array)==8);
    int num_elements = sizeof(array)/sizeof(*array);
    assert(num_elements==4);
   
    float f = fxn(array, num_elements, 4);
    
    struct Mystruct *secondArray;
    // uninitialised values in c: if static then 0 
    // if local then anything...
    // so this is anything
    int   someSize;  
    int   ix;
    // continuous allocation(bc for an array all need to be beside eachother)
    // calloc(num_of_elements, size_of_elements)
    someSize = 10;
    secondArray = calloc(someSize, sizeof(secondArray));
    for(int i =0;i<someSize;i++){
        secondArray[i].intnum = i;
        secondArray[i].floatnum= .1*i;
        printf("%d\n",&secondArray[i]);

    }
    assert(secondArray[4].intnum==4);
    assert(secondArray[4].floatnum==0.4f);


    free(secondArray);
    printf("%d\n",&secondArray);

    printf("passed tests\n");
}

// these two ways of passing in a ptr to an array are equivalent
int get_first_element(int myarray[]){
    return myarray[0];
}

int get_second_element(int *myarray){
    return myarray[1];
}

void test_2(){
   int array[2] ={1,2};
   int first = get_first_element(array);
   assert(first==1);

   int second = get_second_element(array);
   assert(second==2);

}

void inc_dec(){
  long array[10];
  long *p = &array;
  for(int i=0;i<5;i++){
    *p++ = i;
    *p++ = i+1;
  }
  assert(array[0]==0);
  assert(array[9]==5);
}

int main(){  
   test();
   test_2();
   inc_dec();

   return 0;
}
