#include <stdio.h>

void printArray(int values[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    };
    printf("\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int values[], int count) {
    int i = 0, j = 0;
    for (i = count - 1; i >=0; i--){
        for (j = 1; j <= i; j++){
            if (values[j - 1] > values[j]){
                swap(&values[j-1], &values[j]);
            }
        };
        printf("Step = %d, ", count - i);
        printArray(values, count);
    }
}



int main() {
    int values[] = {80, 50, 70, 10, 60, 20, 40, 30};
    printArray(values, 8);
    bubbleSort(values, 8);
    printArray(values, 8);
    printf("%d", values[-1]);
    return 0;
}