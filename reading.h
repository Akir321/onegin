#ifndef READING_H
#define READING_H

#include <stdio.h>

struct string
{
    char *str;
    size_t size;
};

struct textArray 
{
    size_t size;
    size_t nLines;

    char *buffer;
    string *strings;
};

void destroyTextArray(textArray *text);

int fileSize(const char *name);

int readTextFromFile(const char *fileName, textArray *text);

char *readToBuffer(FILE *f, size_t size);

void printStr(char *str, size_t size);

int splitBufToStrings(textArray *text);

size_t countLines(const char *buffer);

void printText(string *text, size_t nLines);

void myPuts(const char *str);

#endif // READING_H
