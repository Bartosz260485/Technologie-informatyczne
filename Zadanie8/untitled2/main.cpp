#include<iostream>
#include "Tab.h"

int tab[SIZE] = {1,2,3,4,5,6,7,8,9,10};

int main() {
    int choice = 0;
    do {
        printf("\n"); PrintMenu(); printf("\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: FillArray(tab, SIZE); break;
            case 2: PrintArray(tab, SIZE); break;
            case 3: printf( "%d",FindMin(tab, SIZE)); break;
            case 4: printf( "%d",FindMax(tab, SIZE)); break;
            case 5: printf( "%.2f",Average(tab, SIZE)); break;
            case 6: printf( "%.2f",Median(tab, SIZE)); break;
            case 7: SaveTable(tab, SIZE); break;
            case 8: LoadTable(tab, SIZE); break;
        }
    }while (choice != 0);
    return 0;
}


