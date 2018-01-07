#include <stdio.h>
#include <ctype.h>

// forward declarations  Tell C we want to use these functions later.
int can_print_it(char ch);
void print_letters(char args[]);

void print_arguments(int argc, char *argv[])
{
    int i = 0;
    for (i =1; i < argc; i++){
        print_letters(argv[i]);
    }
}

void print_letters(char arg[]){
    int i = 0;
    for (i = 0; arg[i] != '\0'; i++){
        char ch = arg[i];

        if (can_print_it(ch)) {
            printf("'%c' == %d \n", ch, ch);
        }
    }
    printf("\n");
}

int can_print_it(char ch) // figure out the given character is a letter or a blank.
{
    return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[]) {
    print_arguments(argc, argv);
    return 0;
}
