#include <stdio.h>

int main()
{
    int a, b;
    char op;
    float result;

    int *pa = &a;
    int *pb = &b;
    char *pop = &op;
    float *p_result = &result;

    printf("Enter the first number: ");
    scanf("%d", pa);

    printf("Enter the second number: ");
    scanf("%d", pb);

    printf("Enter the operator (+, -, *, /): ");
    scanf(" %c", pop);

    if (*pop == '+')
        printf("Result: %d\n", *pa + *pb);

    if (*pop == '-')
        printf("Result: %d\n", *pa - *pb);

    if (*pop == '*')
        printf("Result: %d\n", *pa * *pb);

    if (*pop == '/')
    {
        if (*pb != 0)
        {
            *p_result = (float)*pa / *pb;
            printf("Result: %.2f\n", *p_result);
        }
        else
        {
            printf("Cannot divide by zero!\n");
        }
    }

    return 0;
}