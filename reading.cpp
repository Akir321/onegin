#include <stdio.h>
#include <assert.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "reading.h"
#include "colors.h"

int readTextFromFile(const char *fileName, textArray *text)
{
    assert(text);
    assert(fileName);

    text->size = fileSize(fileName) + 1;
    if (!text->size)  
    { 
        perror("ERROR");
        return 1; 
    }
    //printf("size = %lld\n", text->size);

    FILE *f = fopen(fileName, "r");
    if (!f)      
    { 
        perror("ERROR"); 
        return 1; 
    }

    text->buffer = readToBuffer(f, text->size);
    if (!text->buffer) 
    { 
        perror("ERROR"); 
        return 1; 
    }
    fclose(f);

    //printStr(text->buffer, text->size);

    splitBufToStrings(text);
    if (!text->strings) 
    { 
        perror("ERROR"); 
        return 1; 
    }

    return 0;
}

int fileSize(const char *name)
{
    assert(name);

    struct stat stats = {};
    if (stat(name, &stats) == -1)
    {
        return -1;
    }

    int size = stats.st_size;
    return size;
}

char *readToBuffer(FILE *f, size_t size)
{
    assert(f);

    char *buffer = (char *)calloc(size, sizeof(char));
    if (buffer == NULL)
    {
        return NULL;
    }
    fread(buffer, sizeof(char), size, f);

    return buffer;
}

void printStr(char *str, size_t size)
{
    assert(str);

    for (size_t i = 0; i < size; i++)
    {
        printf("(%d)%c", str[i], str[i]);
    }
}

int splitBufToStrings(textArray *text)
{
    assert(text);
    assert(text->buffer);

    text->nLines = countLines(text->buffer);
    text->strings = (str *)calloc(text->nLines, sizeof(str));

    if (text->strings == NULL)
    {
        return 1;
    }

    text->strings++->str = text->buffer;
    size_t line = 1;
    size_t strSize = 1;

    for (size_t i = 0 ; *(text->buffer + i) != '\0'; i++)
    {
        //printf("separating the line, current elem is (%d)\n", *(text->buffer + i));
        if (*(text->buffer + i) == '\n')
        {
            while (*(text->buffer + i + 1) == '\n')
            {
                i++;
            }
            //printf("*buffer is '\\n'\n");
            //printf("strings  = %p\n", text->strings);
            //printf("*strings = %p\n", text->strings->str);

            text->strings->str = text->buffer + i + 1;
            //printf("*strings = %p\n", text->strings->str);
            (text->strings - 1)->size = strSize - 1;
            strSize = 0;

            text->strings++;
            line++;
        }
        strSize++;
    }
    (text->strings-1)->size = strSize - 1;

    text->strings -= line;
    text->nLines = line;
    return 0;
}

size_t countLines(const char *buffer)
{
    assert(buffer);

    size_t count = 0;
    while (*buffer != '\0')
    {
        if (*buffer == '\n')
        {
            count++;
        }
        buffer++;
    }
    return count + 1; 
}

void printText(str *text, size_t nLines)
{
    assert(text);

    for (size_t i = 0; i < nLines; i++)
    {
        putchar('<');
        printf(MAGENTA);
        myPuts(text[i].str);
        printf(DEFAULT_COLOR);
        putchar('>');
        printf(CYAN);
        printf(", size = %lld address = %p\n", text[i].size, text[i].str);
        printf(DEFAULT_COLOR);
    }
}

void myPuts(const char *str)
{
    assert(str);

    for ( ; *str != '\0' && *str != '\n'; str++)
    {
        putchar(*str);
    }
    putchar('\n');
}

void myFPuts(const char *str, FILE *f)
{
    assert(str);
    assert(f);

    for ( ; *str != '\0' && *str != '\n'; str++)
    {
        fputc(*str, f);
    }
    fputc('\n', f);
}

void printTextToFile(const textArray *text, FILE *f)
{
    assert(f);
    assert(text);

    for (size_t i = 0; i < text->nLines; i++)
    {
        myFPuts(text->strings[i].str, f);
    }
}

void destroyTextArray(textArray *text)
{
    assert(text);

    if (text->buffer)
    {
        free(text->buffer);
        text->buffer = NULL;
    }

    if (text->strings)
    {
        free(text->strings);
        text->strings = NULL;
    }

    text->size   = -1;
    text->nLines = -1;
}
