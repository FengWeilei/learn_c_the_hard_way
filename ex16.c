#include <stdio.h>
#include <assert.h> // assert()
#include <stdlib.h> // malloc() free()
#include <string.h> //strdup()

//combine four elements to a new compound type. It's similar to a row of a database or a class in an object-oriented programming.
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person)); // use malloc to ask the OS for a piece of raw memory.
    assert(who != NULL); // use assert to make sure we do have the memory

    // initialize each field of struct Person using the x->y syntax, to say what part of the structure I want to set.
    who->name = strdup(name); // returns a pointer to a new string which is aduplicate of the string name.
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who) //destroy the Person structure.
{
    assert(who != NULL);
    free(who->name);
    free(who);  // avoid a memory leak
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name); // x->y syntax to get the field from the structure to print it.
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char const *argv[]) {
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
    printf("Joe is at memory location %p:\n", joe); //get the address of the pointer.
    Person_print(joe);
    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    joe->age += 20;
    joe->height += 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    Person_destroy(joe);  //destroy the structure, frees the memory space.
    Person_destroy(frank);
    return 0;
}
