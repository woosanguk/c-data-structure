#include <stdio.h>
#include <stdlib.h>
#include "arrayheap.h"

void displayArrayHeap(ArrayMaxHeap *pHeap) {
    int i = 0;
    if (pHeap != NULL) {
        for (i = 1; i <= pHeap->currentElementCount; i++) {
            printf("[%d],%d\n", i, pHeap->pElement[i]);
        }
    }
}

int main() {
    int maxHeapSize = 20;

    ArrayMaxHeap *pHeap1 = NULL;

    HeapNode *pNode = NULL;
    HeapNode e1 = {10};
    HeapNode e2 = {40};
    HeapNode e3 = {30};
    HeapNode e4 = {20};
    HeapNode e5 = {50};

    pHeap1 = createArrayMaxHeap(maxHeapSize);
    if (pHeap1 != NULL) {
        insertMaxHeapAH(pHeap1, e1);
        insertMaxHeapAH(pHeap1, e2);
        insertMaxHeapAH(pHeap1, e3);
        insertMaxHeapAH(pHeap1, e4);
        insertMaxHeapAH(pHeap1, e5);

        printf("Max Heap:\n");
        displayArrayHeap(pHeap1);

        pNode = deleteMaxHeapAH(pHeap1);
        if (pNode != NULL) {
            printf("deleteMaxHeapAH()-[%d]\n", pNode->key);
            free(pNode);
        }

        printf("Max Heap:\n");
        displayArrayHeap(pHeap1);

        deleteArrayMaxHeap(pHeap1);
    }

    return 0;
}