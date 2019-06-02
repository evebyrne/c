#include <stdio.h>
#include <assert.h>

void test(){
    int a=10;
    void* p;
    p = &a;

// need to cast before can dereference
    assert(a==(*(int*)p));

    printf("passed tests\n");
}

int main(){  
   test();
   return 0;
}
