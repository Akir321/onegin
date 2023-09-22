#ifndef IO_H
#define IO_H

#include <stdio.h>

const int NAME_ADD_LENGTH = 7;

/**
 * @brief a structure to keep a string pointer and str length
 * 
 */
struct str
{
    char *str;
    size_t size;
};

/**
 * @brief a structure that contains all the text parameters
 * 
 */
struct textArray 
{
    size_t size;
    size_t nLines;

    char *buffer;
    str *strings;
};

/**
 * @brief enum of errors with text
 * 
 */
enum errors
{
    FILE_ERROR = 1,
    MEMORY_ERROR = 2
};

/**
 * @brief destructor for struct textArray
 * 
 * @param [in] text 
 */
void destroyTextArray(textArray *text);

/**
 * @brief returns the file size from struct stat
 * 
 * @param [in] name 
 * @return int
 */
int fileSize(const char *name);

/**
 * @brief a constructor for struct textArray
 * 
 *      reads the text to a buffer and splits it to strings with char *
 * 
 * @param [in] fileName 
 * @param [in, out] text 
 * @return int 
 */
int readTextFromFile(const char *fileName, textArray *text);

/**
 * @brief reads text from FILE *f into a buffer, returns the buffer
 * 
 * @param [in] f 
 * @param [in] size 
 * @return char* buffer 
 */
char *readToBuffer(FILE *f, size_t size);

/**
 * @brief prints out size bytes of str with their codes
 * 
 * @param [in] str 
 * @param [in] size 
 */
void printStr(char *str, size_t size);

/**
 * @brief splits buffer from textArray to strings with char *
 * 
 * @param [in, out] text 
 * @return 0 if no error encountered
 * @return positive int - errors enum
 */
int splitBufToStrings(textArray *text);

/**
 * @brief count the amount of "c" symbols in "buffer"
 * 
 * @param [in] buffer 
 * @param [in] c 
 * @return size_t 
 */
size_t countChar(const char *buffer, char c);

/**
 * @brief writes the text (from str *strings) to stdout
 * 
 * @param [in] text 
 * @param [in] nLines 
 */
void printText(str *text, size_t nLines);

/**
 * @brief puts that works with '\\n' like with '\0'
 * 
 * @param [in] str 
 */
void myPuts(const char *str);

/**
 * @brief fputs that works with '\\n' like with '\0'
 * 
 * @param [in] str 
 * @param [in] f  file to write to
 */
void myFPuts(const char *str, FILE *f);

/**
 * @brief writes the text (from str *strings) to file
 * 
 * @param [in] text 
 * @param [in] f 
 */
void printTextToFile(const textArray *text, FILE *f);

#endif // IO_H
