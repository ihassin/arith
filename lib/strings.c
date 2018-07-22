#include <string.h>

#include "addition.h"

char *strrev(char *string)
{
    char *startPtr = string;
    size_t len = strlen(string);
    char *endPtr = string + len - 1;

    while(endPtr >= startPtr)
    {
        char c = *startPtr;
        *startPtr++ = *endPtr;
        *endPtr-- = c;
    }
    return(string);
}
