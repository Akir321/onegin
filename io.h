#ifndef IO_H
#define IO_H

#include <stdio.h>

const int NAME_ADD_LENGTH = 7;

struct str
{
    char *str;
    size_t size;
};

struct textArray 
{
    size_t size;
    size_t nLines;

    char *buffer;
    str *strings;
};

enum errors
{
    FILE_ERROR = 1,
    MEMORY_ERROR = 2
};

void destroyTextArray(textArray *text);

int fileSize(const char *name);

int readTextFromFile(const char *fileName, textArray *text);

char *readToBuffer(FILE *f, size_t size);

void printStr(char *str, size_t size);

int splitBufToStrings(textArray *text);

size_t countChar(const char *buffer, char c);

void printText(str *text, size_t nLines);

void myPuts(const char *str);

void myFPuts(const char *str, FILE *f);

void printTextToFile(const textArray *text, FILE *f);

size_t min(size_t a, size_t b);

#endif // IO_H
