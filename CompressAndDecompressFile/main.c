#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rle.h"
int main() {
    int choice;
    char inputFile[100], outputFile[100];

    printf("Run-Length Encoding (RLE) Utility\n");
    printf("1. Compress a file\n");
    printf("2. Decompress a file\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFile);
    printf("Enter output file name: ");
    scanf("%s", outputFile);

    if (choice == 1) {
        Compress(inputFile, outputFile);
    } else if (choice == 2) {
        Decompress(inputFile, outputFile);
    } else {
        printf("Invalid choice. Please enter 1 or 2.\n");
    }
    return 0;
}
