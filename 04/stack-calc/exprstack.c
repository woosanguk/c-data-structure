//
// Created by sanguk on 08/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exprdef.h"
#include "exprstack.h"


Stack *createStack(){
    Stack *pResult = (Stack *)malloc(sizeof(Stack));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(Stack));
    return pResult;
}

int push(Stack *pStack, StackNode element){
    if (pStack == NULL) return FALSE;
    StackNode *pNewNode = (Stack*)malloc(sizeof(Stack));
    memset(pNewNode, 0, sizeof(StackNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pNewNode->pLink = pStack->pTopElement;
    pStack->pTopElement = pNewNode;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *pop(Stack *pStack){
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack) == TRUE) return NULL;
    StackNode *pNode = pStack->pTopElement;
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
    if (pStack==NULL) return;
    StackNode *pNode = NULL;
    while(isStackEmpty(pStack) != TRUE){
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