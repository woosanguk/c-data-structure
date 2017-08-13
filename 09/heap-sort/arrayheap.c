//
// Created by Administrator on 2017-08-13.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayheap.h"


MaxHeap *createMaxHeap(int maxElementCount) {
    MaxHeap *pReturn = NULL;
    pReturn = (MaxHeap *) malloc(sizeof(MaxHeap));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(MaxHeap));
    pReturn->maxElementCount = maxElementCount;
    pReturn->pElement = (HeapNode *) malloc(sizeof(HeapNode) * maxElementCount + 1);
    if (pReturn->pElement == NULL) {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pElement, 0, sizeof(HeapNode) * maxElementCount + 1);
    return pReturn;
}

void deleteMaxHeap(MaxHeap *pHeap) {
    if (pHeap != NULL) {
        if (pHeap->pElement != NULL) {
            free(pHeap->pElement);
        }
        free(pHeap);
    }
}

MinHeap *createMinHeap(int maxElementCount) {
    return createMaxHeap(maxElementCount);
}

void deleteMinHeap(MinHeap *pHeap) {
    deleteMaxHeap(pHeap);
}

int insertMaxHeap(MaxHeap *pHeap, HeapNode node) {
    int i = 0;
    if (pHeap == NULL) return FALSE;
    if (pHeap->currentElementCount == pHeap->maxElementCount) return FALSE;
    pHeap->currentElementCount++;
    i = pHeap->currentElementCount;
    while ((i != 1) && (node.key > pHeap->pElement[i / 2].key)) {
        pHeap->pElement[i] = pHeap->pElement[i / 2];
        i /= 2;
    }
    pHeap->pElement[i] = node;
    return TRUE;
}

HeapNode *deleteMaxHeapAH(MaxHeap *pHeap) {
    int i = 0, parent = 0, child = 0;
    HeapNode *pReturn = NULL;
    HeapNode *pTemp = NULL;
    if (pHeap == NULL) return NULL;
    if (pHeap->currentElementCount == 0) return NULL;
    pReturn = (HeapNode *) malloc(sizeof(HeapNode));
    if (pReturn == NULL) return NULL;
    *pReturn = pHeap->pElement[1];

    i = pHeap->currentElementCount;
    pTemp = &(pHeap->pElement[i]);
    pHeap->currentElementCount--;
    parent = 1;
    child = 2;
    while (child <= pHeap->currentElementCount) {
        if ((child < pHeap->currentElementCount) && pHeap->pElement[child].key < pHeap->pElement[child + 1].key) {
            child++;
        }
        if (pTemp->key >= pHeap->pElement[child].key) {
            break;
        }
        pHeap->pElement[parent] = pHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pHeap->pElement[parent] = *pTemp;
    return pReturn;
}

int insertMinHeap(MinHeap *pHeap, HeapNode node) {
    int i = 0;
    if (pHeap == NULL) return FALSE;
    if (pHeap->currentElementCount == pHeap->maxElementCount)return FALSE;
    pHeap->currentElementCount++;
    i = pHeap->currentElementCount;
    while ((i != 1) && (node.key < pHeap->pElement[i / 2].key)) {
        pHeap->pElement[i] = pHeap->pElement[i / 2];
        i /= 2;
    }
    pHeap->pElement[i] = node;
    return TRUE;
}

HeapNode *deleteMinHeapAH(MinHeap *pHeap) {
    int i = 0, parent = 0, child = 0;
    HeapNode *pReturn = NULL;
    HeapNode *pTemp = NULL;
    if (pHeap == NULL) return NULL;
    if (pHeap->currentElementCount == 0) return NULL;
    pReturn = (HeapNode *) malloc(sizeof(HeapNode));
    if (pReturn == NULL) return NULL;
    *pReturn = pHeap->pElement[1];
    i = pHeap->currentElementCount;
    pTemp = &(pHeap->pElement[i]);
    pHeap->currentElementCount--;

    parent = 1;
    child = 2;
    while (child <= pHeap->currentElementCount) {
        if ((child < pHeap->currentElementCount) && (pHeap->pElement[child].key > pHeap->pElement[child + 1].key)) {
            child += 1;
        }
        if (pTemp->key <= pHeap->pElement[child].key) {
            break;
        }
        pHeap->pElement[parent] = pHeap->pElement[child];
        parent = child;
        child *= 2;
    }
    pHeap->pElement[parent] = *pTemp;
    return pReturn;
}

void displayHeap(MinHeap *pHeap) {
    int i = 0;
    if (pHeap != NULL) {
        for (i = 1; i <= pHeap->currentElementCount; i++) {
            printf("[%d],%d\n", i, pHeap->pElement[i]);
        }
    }
}