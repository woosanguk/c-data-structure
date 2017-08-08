//
// Created by sanguk on 08/08/2017.
//

#include "mapdef.h"
#include "mapstack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Stack *createStack(){
    Stack *pStack = (Stack *)malloc(sizeof(Stack));
    if (pStack == NULL) return NULL;
    memset(pStack, 0, sizeof(Stack));
    return pStack;
}

int push(Stack *pStack, StackNode element){
    if (pStack == NULL) return FALSE;
    StackNode *pNode = (StackNode*)malloc(sizeof(StackNode));
    if (pNode == NULL) return FALSE;
    *pNode = element;
    pNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNode;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *pop(Stack *pStack){
    StackNode *pNode = NULL;
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack) == TRUE) return NULL;
    pNode = pStack->pTopElement;
    pStack->pTopElement = pNode->pLink;
    pNode->pLink = NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode *peek(Stack *pStack){
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack) == TRUE) return NULL;
    return pStack->pTopElement;
}

void deleteStack(Stack *pStack){
    StackNode *pNode;
    if (pStack == NULL) return;
    while (isStackEmpty(pStack) != NULL){
        pNode = pop(pStack);
        free(pNode);
    }
    free(pStack);
}

int isStackEmpty(Stack *pStack){
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}