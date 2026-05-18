#include <stdio.h>

void toLowercase(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        if (source[i] >= 'A' && source[i] <= 'Z') {
            destination[i] = source[i] + ('a' - 'A');
        } else {
            destination[i] = source[i];
        }
        i++;
    }
    destination[i] = '\0';
}

void toUppercase(char source[], char destination[]) {
    int i = 0;
    while (source[i] != '\0') {
        if (source[i] >= 'a' && source[i] <= 'z') {
            destination[i] = source[i] - ('a' - 'A');
        } else {
            destination[i] = source[i];
        }
        i++;
    }
    destination[i] = '\0';
}

int countChars(char word[]) {
    int counter = 0;
    while (word[counter] != '\0') {
        counter++;
    }
    return counter;
}

int main() {
    char word[256];
    char lowercase_word[256];
    char uppercase_word[256];

    while (1) {
        printf("Enter word: ");

        fgets(word, 256, stdin);

        if (word[0] == '\n') {
            printf("End of program.\n");
            break;
        }

        int i = 0;
        while (word[i] != '\0') {
            if (word[i] == '\n') {
                word[i] = '\0';
                break;
            }
            i++;
        }

        toLowercase(word, lowercase_word);
        toUppercase(word, uppercase_word);
        int length = countChars(word);

        printf("1) Lowercase: %s\n", lowercase_word);
        printf("2) Uppercase: %s\n", uppercase_word);
        printf("3) Character count: %d\n", length);
        printf("----------------------------------------\n");
    }

    return 0;
}