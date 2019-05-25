#include <stdio.h>
#include <assert.h>


int gcd(int m, int n){
   if(m<n){
      int t = n;
      n = m;
      m = t;
   }
   while(n!=0){
     printf("m:%d\n", m);
     printf("n:%d\n", n);
     int t = n;
     n = m % n;
     m = t;
   }
   return m;

}

void run_tests(){
   assert(5 == gcd(10,5));
   assert(10 == gcd(20,10));
   assert(6 == gcd(54,24));
   assert(3 == gcd(123,45));
   assert(1 == gcd(14537,345));
   assert(1 == gcd(-14537,345));
   assert(1 == gcd(45,67));
   assert(17 ==gcd(119,544));
 
   printf("passed tests\n");
}

int main()
{
   run_tests();
   return 0;
}




