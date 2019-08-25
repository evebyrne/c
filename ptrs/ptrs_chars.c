#include <stdio.h>
#include <assert.h>

// Strings = array of chars with terminating 0
void test(){
    static const char *myFormat = "Total Amount Due: %d";
    static const char myFlower[] = { 'P', 'e', 't', 'u', 'n', 'i', 'a', '\0' };
    static const char *myColors[] = {
    "Red", "Orange", "Yellow", "Green", "Blue", "Violet" };

    printf("passed tests\n");
}

int main(){  
   test();
   return 0;
}
