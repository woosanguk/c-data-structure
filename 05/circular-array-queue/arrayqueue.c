//
// Created by sanguk on 08/08/2017.
//

#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *createQueue(int maxElementCount) {
    Queue *pReturn = NULL;
    if (maxElementCount < 1) return NULL;
    pReturn = (Queue *) malloc(sizeof(Queue));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(Queue));
    pReturn->pElement = (QueueNode *) malloc(sizeof(QueueNode) * maxElementCount);
    if (pReturn->pElement == NULL) {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pElement, 0, sizeof(QueueNode) * maxElementCount);
    pReturn->maxElementCount = maxElementCount;
    pReturn->front = -1;
    pReturn->rear = -1;
    return pReturn;
}

int enqueue(Queue *pQueue, QueueNode element) {
    if (pQueue == NULL) return FALSE;
    if (isQueueFull(pQueue) == TRUE) return FALSE;
    pQueue->rear = (pQueue->rear + 1) % pQueue->maxElementCount;
    pQueue->pElement[pQueue->rear] = element;
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode *dequeue(Queue *pQueue) {
    QueueNode *pNode = NULL;
    if (pQueue == NULL) return FALSE;
    if (isQueueEmpty(pQueue) == TRUE) return FALSE;
    pNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (pNode == NULL) return FALSE;
    pQueue->front = (pQueue->front + 1) % pQueue->maxElementCount;
    *pNode = pQueue->pElement[pQueue->front];
    pQueue->currentElementCount--;
    return pNode;
}

QueueNode *peek(Queue *pQueue) {
    if (pQueue == NULL) return FALSE;
    if (isQueueEmpty(pQueue) == TRUE) return FALSE;
    return &(pQueue->pElement[(pQueue->front + 1) % pQueue->maxElementCount]);
}

void deleteQueue(Queue *pQueue) {
    if (pQueue == NULL) return;
    if (pQueue->pElement != NULL) {
        free(pQueue->pElement);
    }
    free(pQueue);
}

int isQueueFull(Queue *pQueue) {
    if (pQueue == NULL) return FALSE;
    if (pQueue->currentElementCount == pQueue->maxElementCount) return TRUE;
    return FALSE;
}

int isQueueEmpty(Queue *pQueue) {
    if (pQueue == NULL) return FALSE;
    if (pQueue->currentElementCount == 0) return TRUE;
    return FALSE;
}
