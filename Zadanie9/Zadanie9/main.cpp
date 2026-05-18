#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int i, array_size;
    int *random_numbers;
    int min_value, max_value;

    srand((unsigned int)time(NULL));

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &array_size);

    printf("Enter the lower bound: ");
    scanf("%d", &min_value);

    printf("Enter the upper bound: ");
    scanf("%d", &max_value);

    random_numbers = (int *)malloc(array_size * sizeof(int));

    if (!random_numbers)
    {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < array_size; i++)
    {
        random_numbers[i] = (rand() % (max_value - min_value + 1)) + min_value;
    }

    for (i = 0; i < array_size; i++)
    {
        printf("%d\n", random_numbers[i]);
    }

    free(random_numbers);

    return EXIT_SUCCESS;
}