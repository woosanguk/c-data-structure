//
// Created by sanguk on 07/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"

Stack *createStack(){
    Stack *pReturn = (Stack *)malloc(sizeof(Stack));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(Stack));
    return pReturn;
}

int push(Stack *pStack, StackNode node){
    if (pStack == NULL) return FALSE;
    StackNode *pNewNode = (StackNode *)malloc(sizeof(StackNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = node;
    pNewNode->pLink = NULL;
    pNewNode->pLink=pStack->pTopNode;
    pStack->pTopNode = pNewNode;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *pop(Stack *pStack){
    if (pStack == NULL) return NULL;
    if (isEmptyStack(pStack) == TRUE) return NULL;
    StackNode *pReturn = NULL;
    pReturn = pStack->pTopNode;
    pStack->pTopNode = pReturn->pLink;
    pReturn->pLink = NULL;
    pStack->currentElementCount--;
    return pReturn;
}

StackNode *peek(Stack *pStack){
    if (pStack == NULL) return NULL;
    if (isEmptyStack(pStack) == TRUE) return NULL;
    return pStack->pTopNode;
}

int isEmptyStack(Stack *pStack){
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}

void deleteStack(Stack *pStack){
    if (pStack == NULL) return;
    StackNode *pNode = NULL;
    while (isEmptyStack(pStack) != TRUE){
        pNode = pop(pStack);
        if (pNode != NULL){
            free(pNode);
        }
    }
    free(pStack);
}
