#include <stdio.h>
#include <assert.h>

void replace_4(int *a, int *b, int *c, int *d){
    int ta = *a;
    *a = *b;
    *b = *c;
    *c = *d;
    *d = ta;
}

void test(){
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    replace_4(&a,&b,&c,&d);
    assert(a==2);
    assert(b==3);
    assert(c==4);
    assert(d==1);
    printf("passed tests\n");

}

int main(){  
   test();
   return 0;
}
