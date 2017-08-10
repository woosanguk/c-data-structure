//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayheap.h"

ArrayMaxHeap *createArrayMaxHeap(int maxElementCount) {
    ArrayMaxHeap *pReturn = NULL;
    if (maxElementCount < 1) return NULL;
    pReturn = (ArrayMaxHeap *) malloc(sizeof(ArrayMaxHeap));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(ArrayMaxHeap));
    pReturn->maxElementCount = maxElementCount;
    pReturn->pElement = (HeapNode *) malloc(sizeof(HeapNode) * (maxElementCount + 1));
    if (pReturn->pElement == NULL) {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pElement, 0, sizeof(HeapNode) * (maxElementCount + 1));
    return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap *pArrayHeap) {
    if (pArrayHeap == NULL) return;
    if (pArrayHeap->pElement != NULL) {
        free(pArrayHeap->pElement);
    }
    free(pArrayHeap);
}

void insertMaxHeapAH(ArrayMaxHeap *pArrayHeap, HeapNode element) {
    int i = 0;
    if (pArrayHeap == NULL) return;
    if (pArrayHeap->maxElementCount == pArrayHeap->currentElementCount) return;
    pArrayHeap->currentElementCount++;
    i = pArrayHeap->currentElementCount;
    while ((i != 1) && (element.key > pArrayHeap->pElement[i / 2].key)) {
        pArrayHeap->pElement[i] = pArrayHeap->pElement[i / 2];
        i /= 2;
    }
    pArrayHeap->pElement[i] = element;
}

HeapNode *deleteMaxHeapAH(ArrayMaxHeap *pArrayHeap) {
    HeapNode *pReturn = NULL;
    HeapNode *pTemp = NULL;
    int i = 0, parent = 0, child = 0;
    if (pArrayHeap == NULL) return NULL;
    if (pArrayHeap->currentElementCount == 0) return NULL;
    pReturn = (HeapNode *) malloc(sizeof(HeapNode));
    if (pReturn == NULL) return NULL;
    *pReturn = pArrayHeap->pElement[1];

    i = pArrayHeap->currentElementCount;
    pTemp = &(pArrayHeap->pElement[i]);
    pArrayHeap->currentElementCount--;
    parent = 1;
    child = 2;
    while (child <= pArrayHeap->currentElementCount) {
        if ((child <= pArrayHeap->currentElementCount) &&
            pArrayHeap->pElement[child].key < pArrayHeap->pElement[child + 1].key) {
            child++;
        }
        if (pTemp->key >= pArrayHeap->pElement[child].key) {
            break;
        }
        pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pArrayHeap->pElement[parent] = *pTemp;

    return pReturn;
}
