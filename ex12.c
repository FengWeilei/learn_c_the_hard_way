#include <stdio.h>

int main(int argc, char const *argv[]) {
    int areas[] = { 10, 12, 13, 14, 20 };
    char name[] = "Feng"; // I want an array of type that is initialized to {...}
    char full_name[] = {
        'F', 'e', 'n', 'g',
        ' ', 'W', 'e', 'i',
        'l', 'e', 'i', '\0'
    };

    areas[0] = 100;
    name[0] = 'f';
    full_name[5] = 'w';
    printf("The size of an int: %u\n", sizeof(int)); //%u unsigned int
    printf("The size of areas (int[]): %u\n", sizeof(areas)); //sizeof(): how big things are in bytes.
    printf("The first element of areas: %d\n", areas[0]);
    printf("The number of ints in areas: %u\n", sizeof(areas) / sizeof(int));
    printf("The size of name (char[]): %u\n", sizeof(name)); // 4 + /0
    printf("The size of full_name (char[]): %u\n", sizeof(full_name));
    printf("The number of chars: %u\n", sizeof(full_name) / sizeof(char));
    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);
    return 0;
}
