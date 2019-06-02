#include <stdio.h>

//pass in address
//* = dereference 
void f(int *j) {
  (*j)++;
}

int main() {
  int i = 20;
  // p = address of i
  int *p = &i;
  f(p);
  printf("i = %d\n", i);

  return 0;
}
