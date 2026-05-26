#include <stdio.h>
#include "utils.h"

void clearInputBuffer() {

    int c;

    while ((c = getchar()) != '\n' && c != EOF);

}

void pauseProgram() {

    printf("\nPress Enter to continue...");
    getchar();

}
