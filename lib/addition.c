#include <string.h>
#include <stdlib.h>
#include <sys/param.h>
#include "addition.h"

#define MAX_DIGITS  4

char *add(char* first, char* second)
{
    size_t len1 = strlen(first);
    size_t len2 = strlen(second);
    int maxLen = MAX(len1, len2);

    char *firstPtr = first + len1 - 1;
    char *secondPtr = second + len2 - 1;

    char *addition = malloc(maxLen + 1);
    char *additionPtr = addition;

    memset(addition, 0, maxLen);

    int carry = 0;
    while((firstPtr >= first) && (secondPtr >= second))
    {
        int num1 = *firstPtr + carry - '0';
        int num2 = *secondPtr - '0';
        int sum = num1 + num2;

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
        *additionPtr++ = 1 + '0';
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

char *strrev(char* string)
{
    size_t len = strlen(string);
    char *rev = malloc(len + 1);
    char* revPtr = rev;

    memset(rev, 0, len + 1);

    char *stringPtr = string + len - 1;

    while(stringPtr >= string)
    {
        *revPtr++ = *stringPtr--;
    }
    return(rev);
}
