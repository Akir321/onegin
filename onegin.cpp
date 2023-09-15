#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "reading.h"
#include "sorts.h"

int main ()
{
    const char *fileIn  = "Onegin.txt";
    const char *fileOut = "sorted_onegin.txt";
    textArray text = {};

    readTextFromFile(fileIn, &text);
    FILE *f =  fopen(fileOut, "w");
    if (!f) 
    { 
        perror("main(): fopen()");
        return 1; 
    }

    quickSort(text.strings, 0, text.nLines - 1, (int (*)(const str *, const str *))myStrCmp);
    printTextToFile(&text, f);
    fprintf(f, "\n\n\n\n\n");

    quickSort(text.strings, 0, text.nLines - 1, (int (*)(const str *, const str *))myStrBackCmp);
    printTextToFile(&text, f);
    fprintf(f, "\n\n\n\n\n");

    fputs(text.buffer, f);

    fclose(f);
    destroyTextArray(&text);
}
