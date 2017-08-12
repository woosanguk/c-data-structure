#include <stdio.h>

void printArray(int value[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int value[], int count) {
    int min = 0;
    for (int i = 0; i < count; i++) {
        min = i;
        for (int j = i + 1; j < count; j++) {
            if (value[j] < value[min]) {
                min = j;
            }
            swap(&value[min], &value[i]);
        }
    }
}


int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};

    printf("Before sort\n");
    printArray(values, 8);

    selectionSort(values, 8);

    printf("After sort\n");
    printArray(values, 8);

    return 0;
}