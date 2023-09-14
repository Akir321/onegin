#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "reading.h"
#include "sorts.h"

int main ()
{
    const char *fileIn = "file.txt";
    textArray text = {};

    readTextFromFile(fileIn, &text);
    printText(text.strings, text.nLines);
    printf("\n\n");

    qsort(text.strings, text.nLines, sizeof(string), myStrCmp);
    printText(text.strings, text.nLines);

    destroyTextArray(&text);
}
