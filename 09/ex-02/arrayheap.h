//
// Created by sanguk on 14/08/2017.
//

#ifndef EX_02_ARRAYHEAP_H
#define EX_02_ARRAYHEAP_H

#define TRUE 1
#define FALSE 0

typedef struct HeapNodeType {
    int key;
} HeapNode;

typedef struct HeapType {
    int currentElementCount;
    int maxElementCount;
    HeapNode *pElement;
} MaxHeap, MinHeap;

MaxHeap *createMaxHeap(int maxElementCount);

void deleteMaxHeap(MaxHeap *pHeap);

MinHeap *createMinHeap(int maxElementCount);

void deleteMinHeap(MinHeap *pHeap);

int insertMaxHeap(MaxHeap *pHeap, HeapNode node);

HeapNode *deleteMaxHeapAH(MaxHeap *pHeap);

int insertMinHeap(MinHeap *pHeap, HeapNode node);

HeapNode *deleteMinHeapAH(MinHeap *pHeap);

void displayHeap(MinHeap *pHeap);

#endif //EX_02_ARRAYHEAP_H
