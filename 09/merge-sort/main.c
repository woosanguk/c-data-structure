#include <stdio.h>

void printArray(int a[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void mergeSortInternal(int a[], int buffer[], int start, int middle, int end) {
    int i = 0, j = 0, k = 0, t = 0;
    i = start;
    j = middle + 1;
    k = start;
    while (i <= middle && j <= end) {
        if (a[i] <= a[j]) {
            buffer[k] = a[i];
            i++;
        } else {
            buffer[k] = a[j];
            j++;
        }
        k++;
    }
    if (i > middle) {
        for (t = j; t <= end; t++, k++) {
            buffer[k] = a[t];
        }
    } else {
        for (t = i; t <= middle; t++, k++) {
            buffer[k] = a[t];
        };
    }

    for (t = start; t <= end; t++) {
        a[t] = buffer[t];
    }
}

void mergeSort(int a[], int buffer[], int start, int end) {
    int middle = 0;
    if (start < end) {
        middle = (start + end) / 2;
        mergeSort(a, buffer, start, middle);
        mergeSort(a, buffer, middle + 1, end);
        mergeSortInternal(a, buffer, start, middle, end);
    }
}

int main() {
    int a[] = {80, 50, 70, 10, 60, 20, 40, 30};
    int pBuffer[8];
    printArray(a, 8);
    mergeSort(a, pBuffer, 0, 7);
    printArray(a, 8);

    return 0;
}