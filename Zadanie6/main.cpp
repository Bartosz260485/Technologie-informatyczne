#include <iostream>
#include <cstring>
#include <stdlib.h>
void usage(char *programName) {
    printf("Usage: %s number1 operation number\n", programName);
    printf("Available operations:\n");
    printf("\tadd\n");
    printf("\n");
    printf("\tsub\n");
    printf("\n");
    printf("\tmul\n");
    printf("\n");
    printf("\tmul\n");
    printf("\n");
    printf("\tdev\n");
    printf("\n");
}

int main(int argc, char* argv[]) {

    int number1 = 0;
    int number2 = 0;
    int result = 0;

    if (argc == 4) {
        number1 = atoi(argv[1]);
        number2 = atoi(argv[3]);

        if (!strcmp("add", argv[2])) {
            result = number1 + number2;
            printf("%d + %d = %d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("sub", argv[2])) {
            result = number1 - number2;
            printf("%d - %d = %d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("mul", argv[2])) {
            result = number1 * number2;
            printf("%d x %d = %d\n", number1, number2, result);
            return 0;
        }
        if (!strcmp("dev", argv[2])) {
            if(!strcmp("0",argv[3])) {
                printf("dont devine by 0");
                return 0;
            }
            else{
                result = number1 / number2;
                printf("%d / %d = %d\n", number1, number2, result);
                return 0;
            }
        }

    }

    usage(argv[0]);

    return 0;
}
