#include <string.h>
#include <stdlib.h>
#include <sys/param.h>

#include "addition.h"

#define ABS(x)  ((x) <= 0 ? -(x) : (x))

char *add(char *first, char *second)
{
    size_t len1 = strlen(first);
    size_t len2 = strlen(second);
    size_t maxLen = MAX(len1, len2);

    char *addition = malloc(maxLen + 1 + ABS(len1 - len2));
    char *additionPtr = addition;

    char *firstPtr = first + len1 - 1;
    char *secondPtr = second + len2 - 1;

    memset(addition, 0, maxLen);

    char carry = 0;
    while((firstPtr >= first) && (secondPtr >= second))
    {
        char num1 = *firstPtr + carry - '0';
        char num2 = *secondPtr - '0';
        char sum = num1 + num2;

        if(sum >= 10)
        {
            *additionPtr++ = (sum - 10) + '0';
            carry = 1;
        } else
        {
            *additionPtr++ = sum + '0';
            carry = 0;
        }
        firstPtr--;
        secondPtr--;
    }

    if(carry)
    {
        *additionPtr++ = '1';
    }

    while(firstPtr >= first) {
        *additionPtr++ = *firstPtr--;
    }

    while(secondPtr >= second) {
        *additionPtr++ = *secondPtr--;
    }

    *additionPtr = 0;
    additionPtr = strrev(addition);
    return(additionPtr);
}
