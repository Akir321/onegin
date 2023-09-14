#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "reading.h"
#include "sorts.h"

int main ()
{
    const char *fileIn  = "file.txt";
    const char *fileOut = "sorted_onegin.txt";
    textArray text = {};

    readTextFromFile(fileIn, &text);
    FILE *f =  fopen(fileOut, "w");
    if (!f)
    {
        perror("main(): fopen()");
        return 1;
    }
    printText(text.strings, text.nLines);
    printf("\n\n");
    //printTextToFile(&text, f);
    fputc('a', f);
    fprintf(f, "abc\n\n");

    qsort(text.strings, text.nLines, sizeof(string), myStrCmp);
    printText(text.strings, text.nLines);
    printf("\n\n");
    //printTextToFile(&text, f);
    fprintf(f, "\n\n");

    qsort(text.strings, text.nLines, sizeof(string), myStrBackCmp);
    printText(text.strings, text.nLines);
    //printTextToFile(&text, f);
    fprintf(f, "\n\n");

    fputs(text.buffer, f);

    fclose(f);
    destroyTextArray(&text);
}
