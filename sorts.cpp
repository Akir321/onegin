#include <assert.h>
#include <stdio.h>
#include "sorts.h"
#include "reading.h"


int myStrCmp(const void *s1, const void *s2)
{
    assert(s1);
    assert(s2);

    const char *str1 = ((const string *)s1)->str;
    const char *str2 = ((const string *)s2)->str;

    while (*str1 == *str2 && *str1 != '\0' && *str1 != '\n')
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int myStrCmp2(const void *s1, const void *s2)
{
    assert(s1);
    assert(s2);

    const char *str1 = ((const string *)s1)->str;
    const char *str2 = ((const string *)s2)->str;

    int i1 = 0, i2 = 0;
    while (str1[i1] == str2[i2] && str1[i1] != '\0' && str1[i1] != '\n')
    {
        i1++;
        i2++;
    }
    return str1[i1] - str2[i2];
}
