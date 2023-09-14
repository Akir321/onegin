#include <assert.h>
#include <stdio.h>
#include <ctype.h>
#include "sorts.h"
#include "reading.h"


int myStrCmp(const void *s1, const void *s2)
{
    assert(s1);
    assert(s2);

    const char *str1 = ((const str *)s1)->str;
    const char *str2 = ((const str *)s2)->str;

    while (!isalpha(*str1) && *str1 != '\0' && *str1 != '\n') { str1++; }
    while (!isalpha(*str2) && *str2 != '\0' && *str2 != '\n') { str2++; }

    while (*str1 == *str2 && *str1 != '\0' && *str1 != '\n')
    {
        str1++;
        str2++;
        while (!isalpha(*str1) && *str1 != '\0' && *str1 != '\n') { str1++; }
        while (!isalpha(*str2) && *str2 != '\0' && *str2 != '\n') { str2++; }
    }
    return *str1 - *str2;
}

int myStrBackCmp(const void *s1, const void *s2)
{
    assert(s1);
    assert(s2);

    const char *str1 = ((const str *)s1)->str;
    const char *str2 = ((const str *)s2)->str;

    long long i1 = (long long)(((const str *)s1)->size - 1);
    long long i2 = (long long)(((const str *)s2)->size - 1);

    while (!isalpha(str1[i1]) && i1 >= 0) { i1--; }
    while (!isalpha(str2[i2]) && i2 >= 0) { i2--; }

    while (str1[i1] == str2[i2] && i1 >= 0 && i2 >= 0)
    {
        i1--;
        i2--;
        while (!isalpha(str1[i1]) && i1 >= 0) { i1--; }
        while (!isalpha(str2[i2]) && i2 >= 0) { i2--; }
    }
    return str1[i1] - str2[i2];
}
