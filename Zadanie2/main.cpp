#include <iostream>
int sum(int *a, int *b) {
    printf("%d+%d=%d\n",*a,*b,*a+*b);
    return 0;
}
int sub(int *a, int *b) {
    printf("%d-%d=%d\n",*a,*b,*a-*b);
    return 0;
}
int mul(int *a, int *b) {
    printf("%d*%d=%d\n",*a,*b,*a* *b);
    return 0;
}
int div(int *a, int *b) {
    if (*b == 0) {
        printf("division by zero\n");
        return 0;
    }
    printf("%d/%d=%d\n",*a,*b,*a/ *b);
    return 0;
}

int main() {
    printf("=====CALCULATOR=======\n");
    int a=0;
    int b=0;
    int *ARRAY1=NULL;
    int *ARRAY2=NULL;
    printf("Enter the first number:\n");
    scanf_s("%d",&a);
    ARRAY1 = &a;
    printf("Enter the second number:\n");
    scanf_s("%d",&b);
    ARRAY2 = &b;
   sum(ARRAY1,ARRAY2);
    sub(ARRAY1,ARRAY2);
    mul(ARRAY1,ARRAY2);
    div(ARRAY1,ARRAY2);
    return 0;
}