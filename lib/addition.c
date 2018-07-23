#include <string.h>
#include <stdlib.h>
#include <sys/param.h>

#include "arith.h"

#define ABS(x)  ((x) <= 0 ? -(x) : (x))

char *add(char *first, char *second)
{
    size_t len1 = strlen(first);
    size_t len2 = strlen(second);
    size_t maxLen = MAX(len1, len2);

    char *addition = malloc(maxLen + 1 + ABS(len1 - len2));
    char *additionPtr = addition;

    char *numberPtr = first + len1 - 1;
    char *fromPtr = second + len2 - 1;

    memset(addition, 0, maxLen);

    char borrow = 0;
    while((numberPtr >= first) && (fromPtr >= second))
    {
        char num1 = *numberPtr + borrow - '0';
        char num2 = *fromPtr - '0';
        char sub = num1 + num2;

        if(sub >= 10)
        {
            *additionPtr++ = (sub - 10) + '0';
            borrow = 1;
        } else
        {
            *additionPtr++ = sub + '0';
            borrow = 0;
        }
        numberPtr--;
        fromPtr--;
    }

    if(borrow)
    {
        *additionPtr++ = '1';
    }

    while(numberPtr >= first) {
        *additionPtr++ = *numberPtr--;
    }

    while(fromPtr >= second) {
        *additionPtr++ = *fromPtr--;
    }

    *additionPtr = 0;
    additionPtr = strrev(addition);
    return(additionPtr);
}

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
