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

    FILE *f =  fopen(fileOut, "w");
    fputs("hello world\n", f);

    readTextFromFile(fileIn, &text);
    //FILE *f =  fopen(fileOut, "w");
    //if (!f) { perror("main(): fopen()"); return 1; }
    printText(text.strings, text.nLines);
    printf("\n\n");
    printTextToFile(&text, f);
    //fputc('a', f);
    fputs("hello world\n", f);
    fprintf(f, "abc\n\n");

    qsort(text.strings, text.nLines, sizeof(str), myStrCmp);
    printText(text.strings, text.nLines);
    printf("\n\n");
    //printTextToFile(&text, f);
    //fprintf(f, "\n\n");

    qsort(text.strings, text.nLines, sizeof(str), myStrBackCmp);
    printText(text.strings, text.nLines);
    //printTextToFile(&text, f);
    //fprintf(f, "\n\n");

    //fputs(text.buffer, f);

    fclose(f);
    destroyTextArray(&text);
}
