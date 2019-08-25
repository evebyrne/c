#include <stdio.h>
#include <assert.h>

struct Mystruct{
  int intnum;
  float floatnum;
};


void test(){
    struct Mystruct array[20];
// init array
    for(int i=0;i<sizeof(array)/sizeof(*array);i++){
        array[i].intnum=i;
        array[i].floatnum=0.1*i;
        printf("%d\n", i);
    }
    assert(array[19].intnum==19);
    assert(array[19].floatnum==1.9f);
    
    printf("&array: %d\n", &array);
    printf("array: %d\n", array);

// iterate over array again with different ptr
    struct Mystruct *parray;
    // ++ parray = parray+8
    // ptr arithmetic is done on the size of the type being pointed to 
    // mystruct =8 
    // parray++ = parray+9
    for(parray=array;parray<array+20;++parray){
        // this doesn't work
        // parray->intnum=2;
        // parray->floatnum=2.2f;
        printf("parray: %d\n", parray);
        printf("*parray: %d\n", *parray);
        printf("parray->intnum: %d\n", parray->intnum);
        printf("parray->floatnum: %f\n", parray->floatnum);
        if(parray->intnum==5) break;
    }
    
    assert(5==parray-array);
    
    printf("passed tests\n");
}

int main(){  
   test();
   return 0;
}
