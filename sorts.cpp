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

    while (*str1 == *str2  && *str1 != '\0' && *str1 != '\n')
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

void quickSort(str *array, size_t left, size_t right, int (*comp)(const str *, const str *))
{
    assert(array);

    //printf("left = %lld, right = %lld\n", left, right);

    if (right <= left)
    {                      
        return ;
    }
    else if (right == left + 1)
    {
        if (comp(array + right, array + left) < 0)
        {
            swap(array + right, array + left);
            return ;
        }
    }

    size_t mid = partition(array, left, right, comp);
    quickSort(array, left, mid, comp);
    quickSort(array, mid + 1, right, comp);
}

size_t partition(str *array, size_t left, size_t right, int (*comp)(const str *, const str *))
{
    assert(array);

    size_t mid = (left + right) / 2;
    str pivot = array[mid];

    //printf("left = %lld, mid = %lld, right = %lld\n", left, mid, right);

    while (left < right)
    {
        // do we need (left < right) in while?
        while (comp(array + left,  &pivot) < 0) { left++;  }
        while (comp(array + right, &pivot) > 0) { right--; }

        if (left >= right)
        {
            break;
        }

        swap(array + right, array + left);
        //if      (right == mid)   mid = left;
        //else if (left  == mid)   mid = right;

        right--;
        left++;
    }
    return mid;
}

void swap(str *a, str *b)
{
    str temp = *a;
    *a = *b;
    *b = temp;
}
