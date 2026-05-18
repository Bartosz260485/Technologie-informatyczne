//def funkcji
#include <iostream>
#include "Tab.h"

void FillArray(int arr[], int size) {
    printf("Podaj 10 wartosci: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void PrintArray(int array[], int size)
{
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", array[i]);
    }
}

int FindMax(int array[], int size) {
    int max = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int FindMin(int array[], int size) {
    int min = array[0];
    for (int i = 0; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

float Average(int array[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (float)sum / size;
}


float Median(int array[], int size) {
        int* copy = new int[size];
        for (int i = 0; i < size; i++) {
            copy[i] = array[i];
        }
        int temp = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size - 1; j++) {
                if (copy[j] > copy[j + 1]) {
                    temp = copy[j];
                    copy[j] = copy[j + 1];
                    copy[j + 1] = temp;
                }
            }
        }
        float med = 0;
        if (size % 2 == 0) {
            med = (float)(copy[size / 2] + copy[size / 2 - 1]) / 2.0;
        } else {
            med = copy[size / 2];
        }

        delete[] copy;
        return med;
    }

void PrintMenu() {
    printf("MENU\n");
    printf("1. Wypelnij tablice\n");
    printf("2. Wypisz tablice\n");
    printf("3. Znajdz minimum\n");
    printf("4. Znajdz maksimum\n");
    printf("5. Srednia\n");
    printf("6. Mediana\n");
    printf("0. Exit\n");
}
