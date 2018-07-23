#include <string.h>
#include <stdlib.h>
#include <sys/param.h>

#include "arith.h"

char *substract(char *number, char *from)
{
    size_t len1 = strlen(number);
    size_t len2 = strlen(from);
    size_t maxLen = MAX(len1, len2);

    char *substraction = malloc(maxLen + 1);
    char *substractionPtr = substraction;

    char *numberPtr = number + len1 - 1;
    char *fromPtr = from + len2 - 1;

    memset(substraction, 0, maxLen);

    char carry = 0;
    char collect = 1;
    while((numberPtr >= number) && (fromPtr >= from))
    {
        char numDigit = *numberPtr - '0';
        char fromDigit = *fromPtr - '0' - carry;
        int sub = fromDigit - numDigit;

        if(sub < 0)
        {
            int newDigit = (fromDigit + 10 - numDigit);
            if(newDigit)
            {
                *substractionPtr++ = newDigit + '0';
            } else
            {
                collect = 0;
            }
            carry = 1;
        } else
        {
            *substractionPtr++ = sub + '0';
            carry = 0;
        }
        numberPtr--;
        fromPtr--;
    }

    if(carry)
    {
        *substractionPtr++ = *fromPtr-- - '1' + '0';
    }

    if(collect)
    {
        while(fromPtr >= from) {
            *substractionPtr++ = *fromPtr--;
        }
    }

    *substractionPtr = 0;
    while(substractionPtr > substraction)
    {
        if(*substractionPtr == '0')
        {
            *substractionPtr = 0;
        }
        substractionPtr--;
    }

    substractionPtr = strrev(substraction);
    return(substractionPtr);
}
