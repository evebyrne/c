#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

// In c the order of the file matters!! This needs to be above the struct so the struct 
// knows what enum colour is 
enum colour {
    black, white, brown, red, gold, purple, roan, blonde, blue, grey
};

struct Dog
{
    // need to be sure name/breed will fit into 200/100 chars
    // are always reserving this amount of memory regardless of actual size of the name
    char name[200];
    char breed[100];
    // age will never be negative
    int unsigned age;
    enum colour colour_coat;
};

struct Cat{ 
   char *name;
   char *breed;
};

typedef struct {
    char *name;
    unsigned int population;
} Warren;

typedef struct {
    char name[100];
    char warren[100];    
} Rabbit;

typedef struct {
    char name[100];
    Warren warren;
} WarrenRabit;


void test_warren(){
    Warren warren={"Watership Down", 10};
    WarrenRabit rabbit = {"Hazel", warren};

    assert(strcmp(warren.name, "Watership Down")==0);
    assert(warren.population==10);
    assert(strcmp(rabbit.name, "Hazel")==0);
    // cant compare structs directly, need to compare fields directly
    assert(strcmp(rabbit.warren.name, warren.name)==0);
    assert(rabbit.warren.population==warren.population);

    printf("passed warren test\n");
}

void test_rabbit(){
    Rabbit rabbit;
    strcpy(rabbit.name, "Bluebell");
    strcpy(rabbit.warren, "Sandleford");

    assert(strcmp(rabbit.name, "Bluebell")==0);
    assert(strcmp(rabbit.warren, "Sandleford")==0);

    printf("passed rabbit test\n");
}
void test_rabbit_2(){
    Rabbit rabbit = {"Bluebell", "Sandleford"};
    
    assert(strcmp(rabbit.name, "Bluebell")==0);
    assert(strcmp(rabbit.warren, "Sandleford")==0);

    printf("passed rabbit test 2\n");
}

void test_cat(){
    struct Cat cat;
    char * name = "Jaffa";
    char* breed  = "tabby";
    // malloc allocates requested memory and returns a ptr to it
    // +1 for null terminator
    cat.name= malloc(strlen(name)+1);
    cat.breed= malloc(strlen(breed)+1);
    strcpy(cat.name, name);
    strcpy(cat.breed, breed);
    // strcmp: < 0: str1 <str2
    // =0 str1 == str2
    // >0 str1> str2
    assert(strcmp(cat.name, name)==0);
    assert(strcmp(cat.breed, breed)==0);

// Dynamically allocated memory created with either calloc() or malloc() 
// doesn't get freed on their own.
//  You must explicitly use free() to release the space.
// https://stackoverflow.com/questions/654754/what-really-happens-when-you-dont-free-after-malloc

    free(cat.name);
    free(cat.breed);
    printf("passed cat test\n");

}
void test_hooper(){
   struct Dog dog;
   dog.age=1;
// Strings need double quotes otherwise will be seen as a char rather than array of 
// chars 
// Cant assign values to arrays but can copy in
   strcpy(dog.breed, "cavachon");
   strcpy(dog.name, "Hooper");
   dog.colour_coat = red;

   assert(dog.age==1);
   assert(strcmp(dog.name, "Hooper")==0);
   assert(strcmp(dog.breed, "cavachon")==0);

   printf("passed dog test\n");
}

void test(){
    test_hooper();
    test_cat();
    test_rabbit();
    test_rabbit_2();
    test_warren();
    printf("passed all tests\n");
}

int main(){  
   test();

   return 0;
}

