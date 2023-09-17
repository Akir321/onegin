#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "sorts.h"

int main (int argc, const char *argv[])
{
    const char *fileIn  = "Onegin.txt";
    const char *fileOut = "sorted_onegin.txt";
    char *newFileOut = NULL;
    textArray text = {};

    if (argc > 1)
    {
        fileIn = argv[1];
        newFileOut = (char *)calloc(NAME_ADD_LENGTH + strlen(argv[1]) + 1, sizeof(char));
        strcat(newFileOut, "sorted_");
        strcat(newFileOut, argv[1]);
    }

    if (readTextFromFile(fileIn, &text) == FILE_ERROR)
    {
        printf ("Couldn't open file %s\n", fileIn);
        return 0;
    }
    FILE *f =  fopen(argc > 1 ? newFileOut : fileOut, "w");
    if (!f) 
    { 
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
