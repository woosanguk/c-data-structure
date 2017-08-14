#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedqueue.h"
#include "arrayheap.h"

#define TRUE 1
#define FALSE 0

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

int compare(int a, int b) {
    if (a >= b) return TRUE;
    return FALSE;
}

int partitionQuickSort(int *a, int start, int end) {
    int pivot = 0, left = 0, right = 0;
    left = start;
    right = end;
    pivot = end;

    while (left < right) {
        while (left < right && compare(a[pivot], a[left]) == FALSE) {
            left++;
        }
        while (left < right && compare(a[right], a[pivot]) == FALSE) {
            right--;
        }
        if (left < right) {
            swap(&a[left], &a[right]);
        }
    }
    swap(&a[pivot], &a[right]);
    return right;
}

void quickSort(int a[], int start, int end) {
    int pivot = 0;
    if (start < end) {
        pivot = partitionQuickSort(a, start, end);
        quickSort(a, start, pivot - 1);
        quickSort(a, pivot + 1, end);
    }
}

void testQuickSort() {
    printf("===testQuickSort===\n");
    int a[] = {62, 48, 93, 78, 24, 65, 23, 9};
    printArray(a, 8);
    quickSort(a, 0, 7);
    printArray(a, 8);
}

void mergeSorInternal(int a[], int buffer[], int start, int mid, int end) {
    int i = 0, j = 0, k = 0, t = 0;
    i = start;
    j = mid + 1;
    k = start;
    while (i <= mid && j <= end) {
        if (compare(a[i], a[j]) == FALSE) {
            buffer[k] = a[j];
            j++;
        } else {
            buffer[k] = a[i];
            i++;
        }
        k++;
    }
    if (i > mid) {
        for (t = j; t <= end; t++, k++) {
            buffer[k] = a[t];
        }
    } else {
        for (t = i; t <= mid; t++, k++) {
            buffer[k] = a[t];
        }
    }
    for (t = start; t <= end; t++) {
        a[t] = buffer[t];
    }

}

void mergeSort(int a[], int buffer[], int start, int end) {
    int mid = 0;
    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(a, buffer, start, mid);
        mergeSort(a, buffer, mid + 1, end);
        mergeSorInternal(a, buffer, start, mid, end);
    }
}

void testMergeSort() {
    printf("===testMergeSort===\n");
    int a[] = {62, 48, 93, 78, 24, 65, 23, 9};
    int temp[8];
    printArray(a, 8);
    mergeSort(a, temp, 0, 7);
    printArray(a, 8);
}

void radixSort(int a[], int count, int radix, int digit) {
    int i = 0, bucket = 0, d = 0, factor = 1;
    Queue **ppQueue = NULL;
    QueueNode node = {0,};
    ppQueue = (Queue **) malloc(sizeof(Queue *) * radix);
    if (ppQueue == NULL) return;
    for (bucket = 0; bucket < radix; bucket++) {
        ppQueue[bucket] = createQueue();
    }
    for (d = 0; d < digit; d++) {
        for (i = 0; i < count; i++) {
            node.data = a[i];
            enqueue(ppQueue[(a[i] / factor) % radix], node);
        }
        i = 0;
        for (bucket = radix - 1; bucket >= 0; bucket--) {
            while (isQueueEmpty(ppQueue[bucket]) == FALSE) {
                QueueNode *pNode = dequeue(ppQueue[bucket]);
                if (pNode != NULL) {
                    a[i] = pNode->data;
                    i++;
                    free(pNode);
                }
            }
        }
        factor = factor * radix;
    }
    for (bucket = 0; bucket < radix; bucket++) {
        deleteQueue(ppQueue[bucket]);
    };
    free(ppQueue);
}

void testRadixSort() {
    printf("===testRadixSort===\n");
    int a[] = {62, 48, 93, 78, 24, 65, 23, 9};
    printArray(a, 8);
    radixSort(a, 8, 10, 2);
    printArray(a, 8);
}

void HeapSort(int a[], int count) {
    int i = 0;
    MinHeap *pHeap = NULL;
    HeapNode node;
    pHeap = createMaxHeap(count);
    if (pHeap == NULL) return;
    for (i = 0; i < count; i++) {
        node.key = a[i];
        insertMaxHeap(pHeap, node);
    };

//    displayHeap(pHeap);

    for (i = 0; i < count; i++) {
        HeapNode *pNode = deleteMaxHeapAH(pHeap);
        if (pNode != NULL) {
            a[i] = pNode->key;
            free(pNode);
        }
    }
}

void testHeapSort() {
    printf("===testHeapSort===\n");
    int a[] = {62, 48, 93, 78, 24, 65, 23, 9};
    printArray(a, 8);
    HeapSort(a, 8);
    printArray(a, 8);
}

int main() {
    testQuickSort();
    testMergeSort();
    testRadixSort();
    testHeapSort();
    return 0;
}