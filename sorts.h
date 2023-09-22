#ifndef SORTS_H
#define SORTS_H

#include <stdio.h>
#include "io.h"

/**
 * @brief compares the strings in lexicographical order
 * 
 * takes into account only letters, upper- and lowercase is considered equal
 * 
 * @param [in] s1 
 * @param [in] s2 
 * @return negative int if s1 < s2
 * @return 0 if s1 = s2
 * @return positive int if s1 > s2 
 */
int myStrCmp(const void *s1, const void *s2);

/**
 * @brief compares the strings in lexicographical order starting from the end of the string
 * 
 * takes into account only letters, upper- and lowercase is considered equal
 * 
 * @param [in] s1 
 * @param [in] s2 
 * @return negative int if s1 < s2
 * @return 0 if s1 = s2
 * @return positive int if s1 > s2 
 */
int myStrBackCmp(const void *s1, const void *s2);

/**
 * @brief qsort realisation for struct str type
 * 
 * @param [in, out] array 
 * @param [in] left 
 * @param [in] right 
 * @param [in] comp 
 */
void quickSort  (str *array, size_t left, size_t right, int (*comp)(const str *, const str *));

/**
 * @brief a function that changes the array in qsort and returns mid index
 * 
 * @param [in, out] array 
 * @param [in] left 
 * @param [in] right 
 * @param [in] comp 
 * @return size_t mid - the border where to partition the array 
 */
size_t partition(str *array, size_t left, size_t right, int (*comp)(const str *, const str *));

/**
 * @brief swaps the two struct str variables
 * 
 * @param [in, out] a 
 * @param [in, out] b 
 */
void swap(str *a, str *b);

/**
 * @brief returns minimum of two size_t variables
 * 
 * @param [in] a 
 * @param [in] b 
 * @return size_t 
 */
size_t min(size_t a, size_t b);

#endif //SORTS_H
