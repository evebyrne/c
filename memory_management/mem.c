#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void *calloc(size_t nmemb, size_t size);
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);

void calloc_(){
// continuous allocation    
    int *p = (int*)calloc(10, sizeof(int));
    assert(p != NULL);
    printf("p: %d\n", p);

    for(int i=0;i<12;i++){
        printf("&p[%d]: %d\t",  i, &p[i]);
        printf("p[%d]: %d\n", i, p[i]);
    }
    
    p[0] = 9;
    p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    p[10] = 10;

    printf("\n");
    free(p);
    for(int i=0;i<12;i++){
        printf("&p[%d]: %d\t",  i, &p[i]);
        printf("p[%d]: %d\n", i, p[i]);
    }
    
}

void malloc_(){
    printf("\nmalloc\n");
    int *p = malloc(8*sizeof(int));
    assert(p != NULL);
    printf("p: %d\n", p);
    for(int i=0;i<12;i++){
        printf("&p[%d]: %d\t",  i, &p[i]);
        printf("p[%d]: %d\n", i, p[i]);
    }
    printf("\n");

    p[0] = -1;
    p[1] = 1;
    p[2] = 2;
    p[7] = 7;
    p[8] = 8;
    p[10] = 10;
    printf("*p: %d\n", *(p+1*sizeof(int)));
    
    for(int i=0;i<12;i++){
        printf("&p[%d]: %d\t",  i, &p[i]);
        printf("p[%d]: %d\n", i, p[i]);
    }
    free(p);
}

int main(){
    
    calloc_();
    malloc_();

    return 0;
}