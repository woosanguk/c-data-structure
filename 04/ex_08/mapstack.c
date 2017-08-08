//
// Created by sanguk on 08/08/2017.
//


#include "mapdef.h"
#include "mapstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack *createStack() {
    Stack *pStack = (Stack *) malloc(sizeof(Stack));
    if (pStack == NULL) return NULL;
    memset(pStack, 0, sizeof(Stack));
    return pStack;
}

int push(Stack *pStack, StackNode node) {
    StackNode *pNode;
    if (pStack == NULL) return FALSE;
    pNode = (StackNode *) malloc(sizeof(StackNode));
    if (pNode == NULL) return FALSE;
    *pNode = node;
    pNode->pLink = pStack->pTomElement;
    pStack->pTomElement = pNode;
    pStack->currentElementCount++;
    return TRUE;
}


StackNode *pop(Stack *pStack) {
    StackNode *pNode;
    if (pStack == NULL) return NULL;
    if (isEmptyStack(pStack) == TRUE) return NULL;
    pNode = pStack->pTomElement;
    pStack->pTomElement = pNode->pLink;
    pNode->pLink = NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode *peek(Stack *pStack) {
    if (pStack == NULL) return NULL;
    if (isEmptyStack(pStack) == TRUE) return NULL;
    return pStack->pTomElement;
}

int isEmptyStack(Stack *pStack) {
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}

void deleteStack(Stack *pStack) {
    StackNode *pNode = NULL;
    if (pStack == NULL) return;
    while (isEmptyStack(pStack) != NULL) {
        pNode = pop(pStack);
        if (pNode != NULL) {
            free(pNode);
        }
    }
    free(pStack);
}