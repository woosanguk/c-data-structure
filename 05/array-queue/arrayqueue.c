//
// Created by sanguk on 08/08/2017.
//

#include "arrayqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *createQueue(int maxElementCount){
    Queue *pQueue = NULL;
    if (maxElementCount < 1) return NULL;
    pQueue = (Queue *)malloc(sizeof(Queue));
    if (pQueue == NULL) return NULL;
    memset(pQueue, 0, sizeof(Queue));
    pQueue->pElement = (QueueNode*)malloc(sizeof(QueueNode) * maxElementCount);
    if (pQueue->pElement == NULL){
        free(pQueue);
        return NULL;
    }
    pQueue->maxElementCount = maxElementCount;
    pQueue->front = -1;
    pQueue->rear = -1;
    return pQueue;
}

int enqueue(Queue *pQueue, QueueNode node){
    if (pQueue == NULL) return FALSE;
    if (isQueueFull(pQueue) == TRUE) return FALSE;
    pQueue->rear++;
    pQueue->pElement[pQueue->rear] = node;
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode *dequeue(Queue *pQueue){
    QueueNode *pNode = NULL;
    if (pQueue == NULL) return NULL;
    if (isQueueEmpty(pQueue) == TRUE) return NULL;
    pNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (pNode == NULL) return NULL;
    pQueue->front++;
    pNode->data = pQueue->pElement[pQueue->front].data;
    pQueue->currentElementCount--;
    return pNode;
}

QueueNode *peek(Queue *pQueue){
    if (pQueue == NULL) return NULL;
    if (isQueueEmpty(pQueue) == TRUE) return NULL;
    return &(pQueue->pElement[pQueue->front + 1]);

}

void deleteQueue(Queue *pQueue){
    QueueNode *pNode;
    if (pQueue == NULL) return;
    if (pQueue->pElement != NULL){
        free(pQueue->pElement);
    }
    free(pQueue);
}

int isQueueFull(Queue *pQueue){
    if (pQueue == NULL) return FALSE;
    if (pQueue->maxElementCount == pQueue->currentElementCount || pQueue->rear == pQueue->maxElementCount - 1) return TRUE;
    return FALSE;
}

int isQueueEmpty(Queue *pQueue){
    if (pQueue == NULL) return FALSE;
    if (pQueue->currentElementCount == 0) return TRUE;
    return FALSE;
}