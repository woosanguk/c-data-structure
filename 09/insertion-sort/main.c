#include <stdio.h>

void printArray(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *b = temp;
}

void insertionSort(int values[], int count) {
    int i = 0, j = 0, temp = 0;
    for (i = 1; i < count; i++) {
        temp = values[i];
        j = i;
        while (j > 0 && values[j - 1] > temp) {
            values[j] = values[j - 1];
            j = j - 1;
        }
        values[j] = temp;
    }
}

int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(values, 8);
    insertionSort(values, 8);
    printArray(values, 8);

    return 0;
}