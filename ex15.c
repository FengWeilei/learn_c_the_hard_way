#include <stdio.h>

// Pointers, Dreaded Pointers

int main(int argc, char *argv[]) {
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan", "Frank",
        "Mary", "John", "Lisa"
    };
    int count = sizeof(ages) / sizeof(int); //Get the size of ages for safety.
    int i = 0;
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    int *cur_age = ages;  // create a pointer that points at ages.
    char **cur_name = names; //  ** for a pointer to (a pointer to char) type. // name is two-dimensional.
    printf("The size of cur_age pointer: %d\n", sizeof(cur_age)); //will get 4, rather the size of what it is points at.
    printf("The size of ages(The cur_age pointed at): %d\n", sizeof(ages));
    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));
    }
    printf("---\n");

    for (i = 0; i < count; i++) {
        printf("%s is %d yrears old again.\n", cur_name[i], cur_age[i]);
    }
    printf("---\n");

    for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++){
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    printf("The address of cur_age: %p\n", cur_age); // Get the address of cur_age pointed at.
    return 0;
}
