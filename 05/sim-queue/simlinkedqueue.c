//
// Created by sanguk on 11/08/2017.
//

#import <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simdef.h"
#include "simlinkedqueue.h"

LinkedQueue *createLinkedQueue() {
    LinkedQueue *pResult = NULL;
    pResult = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(LinkedQueue));
    pResult->pFrontNode = NULL;
    pResult->pRearNode = NULL;
    return pResult;
}

int enqueueLQ(LinkedQueue *pQueue, QueueNode element) {
    QueueNode *pNewNode = NULL;
    if (pQueue == NULL) return FALSE;
    pNewNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pNewNode->pLink = NULL;
    if (isLinkedQueueEmpty(pQueue) == TRUE){
        pQueue->pRearNode = pNewNode;
        pQueue->pFrontNode = pNewNode;
    } else {
        pQueue->pRearNode->pLink = pNewNode;
        pQueue->pRearNode = pNewNode;
    }
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode *dequeueLQ(LinkedQueue *pQueue){
    QueueNode *pReturn = NULL;
    if (pQueue == NULL) return NULL;
    if (isLinkedQueueEmpty(pQueue) == TRUE) return NULL;
    pReturn = pQueue->pFrontNode;
    pQueue->pFrontNode = pReturn->pLink;
    pReturn->pLink = NULL;
    pQueue->currentElementCount--;
    if (isLinkedQueueEmpty(pQueue) == TRUE){
        pQueue->pRearNode = NULL;
    }
    return pReturn;
}

QueueNode *peekLQ(LinkedQueue *pQueue) {
    if (pQueue == NULL) return NULL;
    if (isLinkedQueueEmpty(pQueue) == TRUE) return NULL;
    return pQueue->pFrontNode;
}

void deleteLinkedQueue(LinkedQueue *pQueue) {
    QueueNode *pNode = NULL;
    if (pQueue == NULL) return;
    while (isLinkedQueueEmpty(pQueue) == FALSE) {
        pNode = dequeueLQ(pQueue);
        if (pNode != NULL) free(pNode);
    }
    free(pQueue);
}

int isLinkedQueueFull(LinkedQueue *pQueue) {
    return FALSE;
}

int isLinkedQueueEmpty(LinkedQueue *pQueue) {
    if (pQueue == NULL) return FALSE;
    if (pQueue->currentElementCount == 0) return TRUE;
    return FALSE;
}