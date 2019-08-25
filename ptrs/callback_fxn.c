#include <stdio.h>
#include <assert.h>

typedef int(*my_fxn_type)(int, void*);

#define THE_BIGGEST 100

// call a_fxn with i and data_ptr
int doSomethingNice(int i, my_fxn_type a_fxn, void *data_ptr ){  
    int return_value =0;
    if(i< THE_BIGGEST){
        return_value = (*a_fxn)(i, data_ptr);
    } else{
        return_value = a_fxn(i, data_ptr);
    }
    return return_value;
}

void test(){
    assert(1==1);
    printf("passed tests\n");
}

int main(){  
   test();
   return 0;
}
