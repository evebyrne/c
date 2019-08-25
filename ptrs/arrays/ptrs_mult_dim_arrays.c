#include <stdio.h>
#include <assert.h>


void multid_array(){
    float A[6][8]= {1,2,3,4,5,6,7,8,0,1,2,3,4,5,6,7};
    float *pf; 
    pf= &A[0][0]; 
    assert(*(pf+1)==2);
    assert(*(pf+8)==0);
    

    printf("passed tests\n");
}

void multid_array_diff_row_lengths(){
    // 1 2 3 4 
    // 1 2
    // 1 2 3 4 5 6
    int array[24]={1,2,3,4,1,2,1,2,3,4,5,6};
    // array of ptrs
    int *A[3];
    A[0] = array;
    A[1] = array+4;
    assert(*(2+A) == *(A+2));
    2[A] = array+6;

    assert(A[0][0]==1);
    assert(A[0][3]==4);
    assert(A[2][2]==3);
    assert(A[2][-2]==1);

}

int main(){  
   multid_array();
   multid_array_diff_row_lengths();

   return 0;
}
