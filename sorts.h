#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include "io.h"

int myStrCmp(const void *s1, const void *s2);

int myStrBackCmp(const void *s1, const void *s2);

void quickSort  (str *array, size_t left, size_t right, int (*comp)(const str *, const str *));

size_t partition(str *array, size_t left, size_t right, int (*comp)(const str *, const str *));

void swap(str *a, str *b);

#endif //SORTS_H
