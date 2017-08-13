#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"


void printArray(int a[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
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
        for (bucket = 0; bucket < radix; bucket++){
            while(isQueueEmpty(ppQueue[bucket]) == FALSE){
                QueueNode *pNode = dequeue(ppQueue[bucket]);
                if (pNode != NULL){
                    a[i] = pNode->data;
                    i++;
                    free(pNode);
                }
            }
        }
        factor = factor * radix;
    }
    for (bucket = 0; bucket < radix; bucket++){
        deleteQueue(ppQueue[bucket]);
    };
    free(ppQueue);
}

int main() {
    int a[] = {42, 60, 75, 81, 10, 23, 12, 18};
    printArray(a, 8);
    radixSort(a, 8, 10, 2);
    printArray(a, 8);

    return 0;
}