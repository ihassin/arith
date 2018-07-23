#include <stdio.h>
#include "arith.h"

int main(int argc, char **argv)
{
    if(argc != 3)
    {
        printf("please enter two numbers to add\n");
        return(1);
    }

    char *first = argv[1];
    char *second = argv[2];

    if(!*first || !*second) {
        printf("please enter digits to add\n");
        return(2);
    }

    printf("Result: %s\n", add(first, second));
    return(0);
}
