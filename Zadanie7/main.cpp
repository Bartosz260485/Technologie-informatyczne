#include <stdio.h>

void to_lowercase(char source[], char target[]) {
    int i = 0;
    while (source[i] != '\0') {
        if (source[i] >= 'A' && source[i] <= 'Z') {
            target[i] = source[i] + ('a' - 'A');
        } else {
            target[i] = source[i];
        }
        i++;
    }
    target[i] = '\0';
}

void to_uppercase(char source[], char target[]) {
    int i = 0;
    while (source[i] != '\0') {
        if (source[i] >= 'a' && source[i] <= 'z') {
            target[i] = source[i] - ('a' - 'A');
        } else {
            target[i] = source[i];
        }
        i++;
    }
    target[i] = '\0';
}

int count_length(char word[]) {
    int counter = 0;
    while (word[counter] != '\0') {
        counter++;
    }
    return counter;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <word1> <word2> ...\n", argv[0]);
        return 1;
    }

    for (int j = 1; j < argc; j++) {
        char *word = argv[j];
        int length = count_length(word);

        char lower_word[length + 1];
        char upper_word[length + 1];

        to_lowercase(word, lower_word);
        to_uppercase(word, upper_word);

        printf("Analyzed word: %s\n", word);
        printf("1) Lowercase: %s\n", lower_word);
        printf("2) Uppercase: %s\n", upper_word);
        printf("3) Character count: %d\n", length);
        printf("----------------------------------------\n");
    }

    return 0;
}