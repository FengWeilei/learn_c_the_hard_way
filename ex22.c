#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 23;  // static says that the variable is only used in this .c file.

int get_age() // taking the static variable THE_AGE
{
    return THE_AGE;
}

void set_age(int age) // You can't access THE_AGE directly, but these functions can.
{
    THE_AGE = age;
}

double update_ratio(double new_ratio) // takes a new ratio value, and returns the old one.
{
    static double ratio = 1.0;  // rarely used; static says the variable is only accessible from the function.

    double old_ratio = ratio;
    ratio = new_ratio;
    return old_ratio;
}

void print_size() // prints out what ex22.c thinks THE_SIZE is currently.
{
    log_info("I think size is: %d", THE_SIZE);
}
