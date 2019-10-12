#include "test_functions.h"
#include <stdio.h>

void square_int_list(int *n)
{
    *n *= *n;
}

void print_int_list(int *n)
{
    printf("%d\r\n", *n);
}
