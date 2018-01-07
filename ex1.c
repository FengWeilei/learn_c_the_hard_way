#include <stdio.h>/* include one file into this source file.
.h for header files, which contains lists of functions to use in the program
This can comment multiple lines.*/

int main(int argc, char const *argv[]) {
  int distance = 100;
  // This is also a comment //
  printf("You are %d miles away.\n", distance);
  return 0;
}

/* int : the main function returns an int;
main() take two parameters
{ : indicates the beginning of a block.
int distance =100; : a variable declaration and assignment at the same time.
; : statement ends in a ;
printf can take multiple arguments.
return from the main() that gives the operating system your exit value.
} : end of the block
*/

// $ make ex1  // look for the ex1.c, run the compiler to build ex1
// cc     ex1.c   -o ex1
// $ ./ex1  // ex1 is executable and run it.
// You are 100 miles away.
