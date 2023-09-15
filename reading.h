#ifndef READING_H
#define READING_H

#include <stdio.h>

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

void destroyTextArray(textArray *text);

int fileSize(const char *name);

int readTextFromFile(const char *fileName, textArray *text);

char *readToBuffer(FILE *f, size_t size);

void printStr(char *str, size_t size);

int splitBufToStrings(textArray *text);

size_t countLines(const char *buffer);

void printText(str *text, size_t nLines);

void myPuts(const char *str);

void myFPuts(const char *str, FILE *f);

void printTextToFile(const textArray *text, FILE *f);

size_t min(size_t a, size_t b);

#endif // READING_H
