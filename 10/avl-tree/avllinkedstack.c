//
// Created by sanguk on 17/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avldef.h"
#include "avllinkedstack.h"


LinkedStack *createLinkedStack(){
    LinkedStack *pReturn = NULL;
    pReturn = (LinkedStack *)malloc(sizeof(LinkedStack));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedStack));
    return pReturn;
}

int pushLS(LinkedStack *pStack, StackNode element){
    StackNode *pNode = NULL;
    if (pStack == NULL) return FALSE;
    pNode = (StackNode *)malloc(sizeof(StackNode));
    if (pNode == NULL) return FALSE;
    *pNode = element;
    pNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNode;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *popLS(LinkedStack *pStack){
    StackNode *pReturn = NULL;
    if (pStack == NULL) return NULL;
    if (isLinkedStackEmpty(pStack) == TRUE) return NULL;
    pReturn = pStack->pTopElement;
    pStack->pTopElement = pReturn->pLink;
    pReturn->pLink = NULL;
    pStack->currentElementCount--;
    return pReturn;
}

StackNode *peekLS(LinkedStack *pStack){
    if (pStack == NULL) return NULL;
    if (isLinkedStackEmpty(pStack) == TRUE) return NULL;
    return pStack->pTopElement;
}

void deleteLinkedStack(LinkedStack *pStack){
    StackNode *pNode = NULL;
    if (pStack == NULL) return;
    while (isLinkedStackEmpty(pStack) == FALSE){
        pNode = popLS(pStack);
        if (pNode != NULL) free(pNode);
    }
    free(pStack);
}

int isLinkedStackFull(LinkedStack *pStack){
    return FALSE;
}

int isLinkedStackEmpty(LinkedStack *pStack){
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}