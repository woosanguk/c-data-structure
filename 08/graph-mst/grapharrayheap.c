//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grapharrayheap.h"

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount){
    ArrayMaxHeap *pReturn = NULL;
    pReturn = (ArrayMaxHeap *)malloc(sizeof(ArrayMaxHeap));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(ArrayMaxHeap));
    pReturn->maxElementCount = maxElementCount;
    pReturn->pElement = (HeapNode *)malloc(sizeof(HeapNode) * maxElementCount + 1);
    if (pReturn->pElement == NULL) {
        free(pReturn);
        return NULL;
    }
    return pReturn;
}

void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap){
    if (pArrayHeap == NULL) return;
    if (pArrayHeap->pElement != NULL) return free(pArrayHeap->pElement);
    free(pArrayHeap);
}

ArrayMinHeap* createArrayMinHeap(int maxElementCount){
    return createArrayMaxHeap(maxElementCount);
}

void deleteArrayMinHeap(ArrayMinHeap* pArrayHeap){
    deleteMaxHeapAH(pArrayHeap);
}

void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element){
    int i = 0;
    if (pArrayHeap == NULL) return;
    if (pArrayHeap->currentElementCount == pArrayHeap->maxElementCount) return;
    pArrayHeap->currentElementCount++;
    i = pArrayHeap->currentElementCount;
    while((i != 1) && (element.key > pArrayHeap->pElement[i/2].key)){
        pArrayHeap->pElement[i] = pArrayHeap->pElement[i/2];
        i /= 2;
    }
    pArrayHeap->pElement[i] = element;

}

HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap){
    HeapNode* pReturn = NULL;
    HeapNode* pTemp = NULL;

    int i = 0;
    int parent =0, child = 0;
    if (pArrayHeap == NULL) return NULL;
    if (pArrayHeap->currentElementCount == 0) return NULL;
    pReturn = (HeapNode *)malloc(sizeof(HeapNode));
    if (pReturn == NULL) return NULL;
    *pReturn = pArrayHeap->pElement[1];

    i = pArrayHeap->currentElementCount;

    pTemp = &(pArrayHeap->pElement[i]);
    pArrayHeap->currentElementCount--;

    parent = 1;
    child = 2;
    while(child <= pArrayHeap->currentElementCount){
        if((child < pArrayHeap->currentElementCount) && pArrayHeap->pElement[child].key < pArrayHeap->pElement[child+ 1].key){
            child++;
        }
        if (pTemp->key >= pArrayHeap->pElement[child].key){
            break;
        }
        pArrayHeap->pElement[parent] = pArrayHeap->pElement[child];
        parent = child;
        child *=2;

    }
    pArrayHeap->pElement[parent] = *pTemp;
    return pReturn;
}

void insertMinHeapAH(ArrayMinHeap* pArrayHeap, HeapNode element){
    int i = 0;
    if (pArrayHeap == NULL) return;
    if (pArrayHeap->currentElementCount == pArrayHeap->maxElementCount) return;
    pArrayHeap->currentElementCount++;
    i = pArrayHeap->currentElementCount;
    while ((i != 1) && (element.key < pArrayHeap->pElement[i/2].key)) {
        pArrayHeap->pElement[i] = pArrayHeap->pElement[i/2];
        i /= 2;
    }
    pArrayHeap->pElement[i] = element;
}

HeapNode* deleteMinHeapAH(ArrayMinHeap* pHeap){
    HeapNode* pReturn = NULL;
    HeapNode* pTemp = NULL;

    int i = 0;
    int parent =0, child = 0;

    if (pHeap != NULL && pHeap->currentElementCount >  0) {
        pReturn = (HeapNode*)malloc(sizeof(HeapNode));
        if (pReturn == NULL) {
            printf("Error, malloc() in deleteMinHeapAH()\n");
            return NULL;
        }
        *pReturn = pHeap->pElement[ 1 ];

        i =  pHeap->currentElementCount;
        pTemp = &(pHeap->pElement[ i ]);
        pHeap->currentElementCount--;

        parent = 1;
        child = 2;
        while(child <= pHeap->currentElementCount) {
            if ((child < pHeap->currentElementCount)
                && pHeap->pElement[ child ].key > pHeap->pElement[ child+1 ].key) {
                child++;
            }
            if (pTemp->key <= pHeap->pElement[ child ].key) {
                break;
            }

            pHeap->pElement[ parent ] = pHeap->pElement[ child ];
            parent = child;
            child *= 2;
        }
        pHeap->pElement[ parent ] = *pTemp;
    }

    return pReturn;
}

void displayArrayHeap(ArrayMaxHeap* pHeap){
    int i = 0;
    if (pHeap != NULL) {
        for(i = 1; i <= pHeap->currentElementCount; i++) {
            printf("[%d],%d\n", i, pHeap->pElement[i]);
        }
    }
}