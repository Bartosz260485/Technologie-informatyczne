#include <stdio.h>
#include <stdlib.h>

// int main() {
//     FILE *filePointer = fopen("data.txt", "a");
//
//     if (filePointer == NULL) {
//         fprintf(stderr, "Error: Could not open the file for appending.\n");
//         exit(EXIT_FAILURE);
//     }
//
//     fprintf(filePointer, "Text appended to the end of the file.\n");
//
//     fclose(filePointer);
//     return EXIT_SUCCESS;
// }

// int main() {
//     char lineBuffer[100];
//     FILE *filePointer = fopen("data.txt", "r");
//
//     if (filePointer != NULL) {
//         while (fgets(lineBuffer, sizeof(lineBuffer), filePointer) != NULL) {
//             printf("%s", lineBuffer);
//         }
//         fclose(filePointer);
//     } else {
//         fprintf(stderr, "Error: Could not open the file for reading!\n");
//     }
//
//     return EXIT_SUCCESS;
// }

int main() {
    FILE *filePointer;
    char currentChar;
    int i;

    filePointer = fopen("alphabet.txt", "w+");

    if (filePointer == NULL) {
        fprintf(stderr, "Error: Could not open the file.\n");
        exit(EXIT_FAILURE);
    }

    for (currentChar = 'A'; currentChar <= 'Z'; currentChar++) {
        fputc(currentChar, filePointer);
    }

    puts("Successfully wrote letters A to Z to the file.");

    fseek(filePointer, -1, SEEK_END);

    printf("File content printed backwards:\n");

    for (i = 26; i > 0; i--) {
        currentChar = fgetc(filePointer);
        printf("%c", currentChar);
        fseek(filePointer, -2, SEEK_CUR);
    }

    printf("\n");

    fclose(filePointer);

    return EXIT_SUCCESS;
}