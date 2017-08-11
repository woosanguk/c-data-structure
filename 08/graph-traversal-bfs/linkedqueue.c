//
// Created by sanguk on 11/08/2017.
//

#import <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedqueue.h"


Queue *createQueue() {
    Queue *pResult = NULL;
    pResult = (Queue *) malloc(sizeof(Queue));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(Queue));
    return pResult;
}

int enqueue(Queue *pQueue, QueueNode node) {
    QueueNode *pNewNode = NULL;
    if (pQueue == NULL) return FALSE;
    pNewNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = node;
    pNewNode->pLink = NULL;

    if (pQueue->currentElementCount == 0) {
        pQueue->pFrontNode = pNewNode;
        pQueue->pRearNode = pNewNode;
    } else {
        pQueue->pRearNode->pLink = pNewNode;
        pQueue->pRearNode = pNewNode;
    }
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode *dequeue(Queue *pQueue) {
    QueueNode *pReturn = NULL;
    if (pQueue == NULL) return NULL;
    if (pQueue->currentElementCount == 0) return NULL;
    pReturn = pQueue->pFrontNode;
    pQueue->pFrontNode = pReturn->pLink;
    pReturn->pLink = NULL;
    if (pQueue->currentElementCount == 1) {
        pQueue->pRearNode = NULL;
    }
    pQueue->currentElementCount--;
    return pReturn;
}

QueueNode *peek(Queue *pQueue) {
    if (pQueue == NULL) return NULL;
    if (pQueue->currentElementCount == 0) return NULL;
    return pQueue->pFrontNode;
}

void deleteQueue(Queue *pQueue) {
    QueueNode *pNode = NULL;
    if (pQueue == NULL) return;
    while (pQueue->currentElementCount > 0) {
        pNode = dequeue(pQueue);
        if (pNode != NULL) free(pNode);
    }
    free(pQueue);
}