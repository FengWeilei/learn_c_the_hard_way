#include <stdio.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor { BLUE_EYES, BORWN_EYES, BLACK_EYES, OTHER_EYES } EyeColor;

const char *EYE_COLOR_NAMES[] = { "Blue", "Green", "Brown", "Black", "Other" };

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[])
{
    Person you = { .age = 0 };
    int i = 0;
    char *in = NULL;

    printf("What's your First Name?\n");
    // fgets reads a string from the input. in this case stdin. make sure not overflow the given buffer.
    in = fgets(you.first_name, MAX_DATA - 1, stdin);
    // in = fscanf(stdin, "%50s", you.first_name);  // read to much and eat our enter key. (skip the last_name option.)
    check(in != NULL, "Failed to read first name.");
    printf("What's your Last Name?\n");
    in = fgets(you.last_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read last name.");
    printf("How old are you?\n");
    int rc = fscanf(stdin, "%d", &you.age); // give the address of you.age so that fscanf has a pointer to it and can modify it.
    check(rc > 0, "You have to enter a number.");

    printf("What color are your eyes:\n");
    for (i = 0; i <= OTHER_EYES; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }
    printf("> \n");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes); // atoi to convert str to int, if not using fscanf.
    check(rc > 0, "You have to enter a number.");
    you.eyes = eyes - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");
    printf("How much do you make an hour? ");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number.");
    printf("----- RESULTS ------\n");
    printf("First Name: %s\n", you.first_name);
    printf("Last_Name: %s\n", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

    return 0;
error:
    return -1;
}
