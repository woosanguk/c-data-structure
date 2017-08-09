//
// Created by sanguk on 08/08/2017.
//

#include "linkeddeque.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Deque *createDeque() {
    Deque *pDeque = (Deque *) malloc(sizeof(Deque));
    if (pDeque == NULL) return NULL;
    memset(pDeque, 0, sizeof(Deque));
    return pDeque;
}

int insertFront(Deque *pDeque, DequeNode element) {
    DequeNode *pNode = NULL;
    if (pDeque == NULL) return FALSE;
    pNode = (DequeNode *) malloc(sizeof(DequeNode));
    if (pNode == NULL) return FALSE;
    *pNode = element;
    pNode->pLLink = NULL;
    pNode->pRLink = NULL;
    if (isDequeEmpty(pDeque) == TRUE) {
        pDeque->pRearNode = pNode;
        pDeque->pFrontNode = pNode;
    } else {
        pNode->pRLink = pDeque->pFrontNode;
        pDeque->pFrontNode->pLLink = pNode;
        pDeque->pFrontNode = pNode;
    }
    pDeque->currentElementCount++;
    return TRUE;
}

int insertRear(Deque *pDeque, DequeNode element) {
    DequeNode *pNode = NULL;
    if (pDeque == NULL) return FALSE;
    pNode = (DequeNode *) malloc(sizeof(DequeNode));
    if (pNode == NULL) return FALSE;
    *pNode = element;
    pNode->pLLink = NULL;
    pNode->pRLink = NULL;
    if (isDequeEmpty(pDeque) == TRUE) {
        pDeque->pRearNode = pNode;
        pDeque->pFrontNode = pNode;
    } else {
        pNode->pLLink = pDeque->pRearNode;
        pDeque->pRearNode->pRLink = pNode;
        pDeque->pRearNode = pNode;
    }
    pDeque->currentElementCount++;
    return TRUE;
}

DequeNode *deleteFront(Deque *pDeque){
    DequeNode *pReturn = NULL;
    if (pDeque == NULL) return NULL;
    if (isDequeEmpty(pDeque) == TRUE) return NULL;
    pReturn = pDeque->pFrontNode;
    pDeque->pFrontNode = pReturn->pRLink;
    pReturn->pRLink = NULL;
    pDeque->currentElementCount--;
    if (isDequeEmpty(pDeque) == TRUE){
        pDeque->pRearNode = NULL;
    } else {
        pDeque->pFrontNode->pLLink = NULL;
    }
    return pReturn;
}

DequeNode *deleteRear(Deque *pDeque){
    DequeNode *pReturn = NULL;
    if (pDeque == NULL) return NULL;
    if (isDequeEmpty(pDeque) == TRUE) return NULL;
    pReturn = pDeque->pRearNode;
    pDeque->pRearNode = pReturn->pLLink;
    pReturn->pLLink = NULL;
    pDeque->currentElementCount--;
    if (isDequeEmpty(pDeque) == TRUE){
        pDeque->pFrontNode = NULL;
    } else {
        pDeque->pRearNode->pRLink = NULL;
    }
    return pReturn;
}

DequeNode *peekFront(Deque *pDeque){
    if (pDeque == NULL) return NULL;
    if (isDequeEmpty(pDeque) == TRUE) return NULL;
    return pDeque->pFrontNode;
}

DequeNode *peekRear(Deque *pDeque){
    if (pDeque == NULL) return NULL;
    if (isDequeEmpty(pDeque) == TRUE) return NULL;
    return pDeque->pRearNode;
}

void deleteDeque(Deque *pDeque){
    DequeNode *pNode = NULL;
    DequeNode *pDelNode = NULL;

    if (pDeque != NULL) {
        pNode = pDeque->pFrontNode;
        while(pNode != NULL) {
            pDelNode = pNode;
            pNode = pNode->pRLink;
            free(pDelNode);
        }
        free(pDeque);
    }
}

int isDequeEmpty(Deque *pDeque) {
    int ret = FALSE;
    if (pDeque == NULL) return ret;
    if (pDeque->currentElementCount == 0) ret = TRUE;
    return ret;
}