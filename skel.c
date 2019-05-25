#include <stdio.h>
#include <assert.h>

void test(){
    assert(1==1);
    printf("passed tests\n");
}

int main(){  
   test();
   return 0;
}
