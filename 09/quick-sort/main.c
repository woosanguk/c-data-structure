#include <stdio.h>

void printArray(int values[]) {
    for (int i = 0; i < sizeof(values); i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partitionQuickSort(int *values, int start, int end) {
    int pivot = 0, left = 0, right = 0;
    left = start;
    right = end;
    pivot = end;
    while(left < right){
        while(left < right && values[left] < values[pivot]){
            left++;
        }
        while(left < right && values[right] >= values[pivot]){
            right--;
        }
        if (left < right){
            swap(&values[left], &values[right]);
        }
    }
    swap(&values[pivot], &values[right]);
    return right;
}

void quickSort(int values[], int start, int end) {
    int pivot = 0;
    if (start < end) {
        pivot = partitionQuickSort(values, start, end);
        quickSort(values, start, pivot - 1);
        quickSort(values, pivot + 1, end);
    }

}

int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(values);
    quickSort(values, 0, 7);
    printArray(values);

    return 0;
}