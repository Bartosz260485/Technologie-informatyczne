#include <iostream>
#define SIZE 5    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.

int main() {
    printf("TABLICE\n");
    int tablice[SIZE];
    printf("podaj numery do tablicy\n");
    for (int i=0;i<SIZE;i++) {
        scanf_s("%d",&tablice[i]);
    }
    for (int i=0;i<SIZE;i++) {
        printf("Tablice[%d]=%d\n",i,tablice[i]);
    }
    int copy[SIZE];
    for (int i=0;i<SIZE;i++) {
        copy[i]=tablice[i];
    }
    int *min = &tablice[0];
    for (int i=0;i<SIZE;i++) {
        if (*min>tablice[i]) {
            min = &tablice[i];
        }
    }
    printf("min=%d\n",*min);
    int *max = &tablice[0];
    for (int i=0;i<SIZE;i++) {
        if (*max<tablice[i]) {
            max = &tablice[i];
        }
    }
    printf("max=%d\n",*max);
    int sum=0;
    for (int i=0;i<SIZE;i++) {
        sum+=tablice[i];

    }
    printf("sum=%d\n",sum);
    float avrg =(float)sum/SIZE;
    printf("avrage=%.2f\n",avrg);

    int temp =0;
    for (int i=0;i<SIZE;i++) {
        for (int j=0;j<SIZE-1;j++) {
            if (copy[j]>copy[j+1]) {
                temp = copy[j];
                copy[j]=copy[j+1];
                copy[j+1]=temp;
            }
        }
    }
    for (int i=0;i<SIZE;i++) {
        printf("tablice[%d]=%d\n",i,copy[i]);
    }


        float med=0;
        if (SIZE%2==0) {
            med = (float)(copy[SIZE/2]+copy[SIZE/2-1])/2;
        }

        else {
            med = copy[SIZE/2];
        }
        printf("med=%.2f\n",med);

}
