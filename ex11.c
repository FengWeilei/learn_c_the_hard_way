#include <stdio.h>

int main(int argc, char const *argv[]) {
    int numbers[4] = { 0 };  // a chortcut for C, it'll fill in the rest with 0.
    char name[4] = { 'a' }; // '\0' character is special and won't display.

    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
    printf("name each: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
    printf("name: %s\n", name);

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    name[0] = 'B';
    name[1] = 'L';
    name[2] = 'F';
    name[3] = '\0';

    printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);

    printf("name each: %c%c%c%c\n", name[0], name[1], name[2], name[3]);
    printf("name: %s\n", name); // Two syntaxes doing the same thing. C does not differentiate them.

    char *another = "VEFC";  // Better use this syntax. "" and '' is not the same
    printf("another: %s\n", another);
    printf("another each: %c %c %c %c\n", another[0], another[1], another[2], another[3]);
    return 0;
}
