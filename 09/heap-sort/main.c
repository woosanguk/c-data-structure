#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"


void printArray(int a[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    };
    printf("\n");
}

void heapSort(int a[], int count) {
    int i = 0;
    MinHeap *pHeap = NULL;
    HeapNode node;
    pHeap = createMinHeap(count);
    if (pHeap == NULL) return;
    for (i = 0; i < count; i++) {
        node.key = a[i];
        insertMinHeap(pHeap, node);
    };

    for (i = 0; i < count; i++){
        HeapNode *pNode = deleteMinHeapAH(pHeap);
        if (pNode != NULL){
            a[i] = pNode->key;
            free(pNode);
        }
    }
    deleteMinHeap(pHeap);
//    displayHeap(pHeap);


}

int main() {
    int values[] = {10, 50, 70, 80, 60, 20, 40, 30};

    printArray(values, 8);
    heapSort(values, 8);
    printArray(values, 8);
    return 0;
}