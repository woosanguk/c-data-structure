//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"


Stack *createStack() {
    Stack *pReturn = NULL;
    pReturn = (Stack *) malloc(sizeof(Stack));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(Stack));
    return pReturn;
}

int push(Stack *pStack, StackNode node) {
    StackNode *pNewNode;
    if (pStack == NULL) return FALSE;
    pNewNode = (StackNode *) malloc(sizeof(StackNode));
    if (pNewNode == NULL) return FALSE;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *pop(Stack *pStack) {
    StackNode *pReturn = NULL;
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack) == TRUE) return NULL;
    pReturn = pStack->pTopElement;
    pStack->pTopElement = pReturn->pLink;
    pReturn->pLink = NULL;
    pStack->currentElementCount--;
    return pReturn;
}

StackNode *peek(Stack *pStack) {
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack) == TRUE) return NULL;
    return pStack->pTopElement;
}

int isStackEmpty(Stack *pStack) {
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}

void deleteStack(Stack *pStack) {
    StackNode *pNode = NULL;
    if (pStack == NULL) return;
    while (isStackEmpty(pStack) == FALSE) {
        pNode = pop(pStack);
        if (pNode != NULL) free(pNode);
    }
    free(pStack);
}