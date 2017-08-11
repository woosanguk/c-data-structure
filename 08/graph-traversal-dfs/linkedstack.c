//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"


LinkedStack *createLinkedStack() {
    LinkedStack *pReturn = NULL;
    pReturn = (LinkedStack *) malloc(sizeof(LinkedStack));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedStack));
    pReturn->pTopElement = NULL;
    return pReturn;
}

int pushLS(LinkedStack *pStack, StackNode element) {
    StackNode *pNewNode = NULL;
    if (pStack == NULL) return FALSE;
    pNewNode = (StackNode *) malloc(sizeof(StackNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pNewNode->pLink = NULL;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *popLS(LinkedStack *pStack) {
    StackNode *pReturn = NULL;
    if (pStack == NULL) return NULL;
    if (isLinkedStackEmpty(pStack) == TRUE) return NULL;
    pReturn = pStack->pTopElement;
    pStack->pTopElement = pReturn->pLink;
    pReturn->pLink = NULL;
    pStack->currentElementCount--;
    return pReturn;
}

StackNode *peekLS(LinkedStack *pStack) {
    if (pStack == NULL) return NULL;
    if (isLinkedStackEmpty(pStack) == TRUE) return NULL;
    return pStack->pTopElement;
}

void deleteLinkedStack(LinkedStack *pStack) {
    StackNode *pNode = NULL;
    if (pStack == NULL) return;
    while (isLinkedStackEmpty(pStack) == FALSE) {
        pNode = popLS(pStack);
        if (pNode != NULL) free(pNode);
    }
    free(pStack);
}

int isLinkedStackFull(LinkedStack *pStack) {
    return FALSE;
}

int isLinkedStackEmpty(LinkedStack *pStack) {
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}