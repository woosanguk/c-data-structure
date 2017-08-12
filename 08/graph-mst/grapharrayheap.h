//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_MST_GRAPHARRAYHEAP_H
#define GRAPH_MST_GRAPHARRAYHEAP_H

#define TRUE 1
#define FALSE 0

typedef struct HeapElementType
{
    int key;
    int fromVertexID;
    int toVertexID;
} HeapNode;

typedef struct ArrayHeapType
{
    int maxElementCount;
    int currentElementCount;
    HeapNode *pElement;
} ArrayMaxHeap, ArrayMinHeap;

ArrayMaxHeap* createArrayMaxHeap(int maxElementCount);

void deleteArrayMaxHeap(ArrayMaxHeap* pArrayHeap);

ArrayMinHeap* createArrayMinHeap(int maxElementCount);

void deleteArrayMinHeap(ArrayMinHeap* pArrayHeap);

void insertMaxHeapAH(ArrayMaxHeap* pArrayHeap, HeapNode element);

HeapNode* deleteMaxHeapAH(ArrayMaxHeap* pArrayHeap);

void insertMinHeapAH(ArrayMinHeap* pArrayHeap, HeapNode element);

HeapNode* deleteMinHeapAH(ArrayMinHeap* pArrayHeap);

void displayArrayHeap(ArrayMaxHeap* pList);

#endif //GRAPH_MST_GRAPHARRAYHEAP_H
