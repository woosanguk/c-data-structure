//
// Created by sanguk on 14/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedqueue.h"

Queue *createQueue(){
    Queue *pReturn = NULL;
    pReturn = (Queue *)malloc(sizeof(Queue));
    memset(pReturn, 0, sizeof(Queue));
    return pReturn;
}

void deleteQueue(Queue *pQueue){
    QueueNode *pNode = NULL;
    if (pQueue == NULL) return;
    while(isQueueEmpty(pQueue) == FALSE){
        pNode = dequeue(pQueue);
        if (pNode != NULL) free(pNode);
    }
    free(pQueue);
}

int enqueue(Queue *pQueue, QueueNode node){
    QueueNode *pNewNode = NULL;
    if (pQueue == NULL) return FALSE;
    pNewNode = (Queue*)malloc(sizeof(Queue));
    if (pNewNode == NULL) return NULL;
    *pNewNode = node;
    pNewNode->pLink;

    if (isQueueEmpty(pQueue) == TRUE){
        pQueue->pFrontNode = pNewNode;
        pQueue->pRearNode = pNewNode;
    } else {
        pNewNode->pLink = pQueue->pFrontNode;
        pQueue->pFrontNode = pNewNode;
    }
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode *dequeue(Queue *pQueue){
    QueueNode *pReturn = NULL;
    if (pQueue == NULL) return NULL;
    if (isQueueEmpty(pQueue)== TRUE) return NULL;
    pReturn = pQueue->pFrontNode;
    pQueue->pFrontNode = pReturn->pLink;
    pReturn->pLink = NULL;
    pQueue->currentElementCount--;
    if (isQueueEmpty(pQueue) == TRUE){
        pQueue->pRearNode = NULL;
    }
    return pReturn;
}

QueueNode *peek(Queue *pQueue){
    if (pQueue == NULL) return NULL;
    if (isQueueEmpty(pQueue)== TRUE) return NULL;
    return pQueue->pFrontNode;
}

int isQueueEmpty(Queue *pQueue){
    if (pQueue == NULL) return FALSE;
    if (pQueue->currentElementCount == 0) return TRUE;
    return FALSE;
}