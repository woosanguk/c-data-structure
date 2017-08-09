//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"
#include "bintreelinkedqueue.h"


LinkedQueue *createLinkedQueue() {
    LinkedQueue *pReturn = (LinkedQueue *) malloc(sizeof(LinkedQueue));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedQueue));
    pReturn->pFrontNode = NULL;
    pReturn->pRearNode = NULL;
    return pReturn;
}

int enqueueLQ(LinkedQueue *pQueue, QueueNode element) {
    QueueNode *pNewNode = NULL;
    if (pQueue == NULL) return FALSE;
    pNewNode = (QueueNode *) malloc(sizeof(QueueNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pNewNode->pLink = NULL;
    if (isLinkedQueueEmpty(pQueue) == TRUE) {
        pQueue->pFrontNode = pNewNode;
        pQueue->pRearNode = pNewNode;
    } else {
        pQueue->pRearNode->pLink = pNewNode;
        pQueue->pRearNode = pNewNode;
    }
    pQueue->currentElementCount++;
    return TRUE;
}

QueueNode *dequeueLQ(LinkedQueue *pQueue) {
    QueueNode *pNode = NULL;
    if (pQueue == NULL) return NULL;
    if (isLinkedQueueEmpty(pQueue) == TRUE) return NULL;
    pNode = pQueue->pFrontNode;
    pQueue->pFrontNode = pNode->pLink;
    pNode->pLink = NULL;
    pQueue->currentElementCount--;
    if (isLinkedQueueEmpty(pQueue) == TRUE) {
        pQueue->pRearNode = NULL;
    }
    return pNode;
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
        if (pNode != NULL) {
            free(pNode);
        }
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