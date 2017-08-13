#include <stdio.h>

void printArray(int a[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void shellInsertionSort(int a[], int start, int end, int interval) {
    int i = 0;
    int item = 0, index = 0;
    for (i = start + interval; i <= end; i = i + interval) {
        item = a[i];
        index = i - interval;
        while ((index >= start) && item < a[index]) {
            a[index + interval] = a[index];
            index = index - interval;
        }
        a[index + interval] = item;
    }
}

void shellSort(int a[], int count) {
    int i = 0, interval = 0;
    interval = count / 2;
    while (interval >= 1) {
        for (i = 0; i < interval; i++) {
            shellInsertionSort(a, i, count - 1, interval);
        }
        interval = interval / 2;
    }
}

int main() {
    int a[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(a, 8);
    shellSort(a, 8);
    printArray(a, 8);
    return 0;
}