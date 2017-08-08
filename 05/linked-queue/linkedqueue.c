//
// Created by sanguk on 08/08/2017.
//

#include "linkedqueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Queue *createQueue() {
    Queue *pResult = (Queue *) malloc(sizeof(Queue));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(Queue));
    return pResult;
}

int enqueue(Queue *pQueue, QueueNode element) {
    QueueNode *pNewNode = NULL;
    if (pQueue == NULL) return FALSE;
    pNewNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pNewNode->pLink = NULL;

    if (isQueueEmpty(pQueue) == TRUE) {
        pQueue->pFrontNode = pNewNode;
        pQueue->pRearNode = pNewNode;
    } else {
        pQueue->pRearNode->pLink = pNewNode;
        pQueue->pRearNode = pNewNode;
    }
    pQueue->currentQueueCount++;
    return TRUE;
}

QueueNode *dequeue(Queue *pQueue){
    QueueNode *pNode;
    if (pQueue == NULL) return NULL;
    if (isQueueEmpty(pQueue) == TRUE) return NULL;
    pNode = pQueue->pFrontNode;
    pQueue->pFrontNode = pNode->pLink;
    pNode->pLink = NULL;
    pQueue->currentQueueCount--;
    if (isQueueEmpty(pQueue) == NULL){
        pQueue->pRearNode = NULL;
    }
    return pNode;
}

QueueNode *peek(Queue *pQueue){
    if (pQueue == NULL) return NULL;
    if (isQueueEmpty(pQueue) == TRUE) return NULL;
    return pQueue->pFrontNode;
}

void deleteQueue(Queue *pQueue){
    QueueNode *pNode;
    if (pQueue == NULL) return;
    while(isQueueEmpty(pQueue) != NULL){
        pNode = dequeue(pQueue);
        if (pNode != NULL){
            free(pNode);
        }
    }
    free(pQueue);
}

int isQueueEmpty(Queue *pQueue) {
    if (pQueue == NULL) return FALSE;
    if (pQueue->currentQueueCount == 0) return TRUE;
    return FALSE;
}