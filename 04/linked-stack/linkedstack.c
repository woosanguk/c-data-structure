//
// Created by sanguk on 07/08/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedstack.h"


Stack *createStack(){
    Stack *pStack = (Stack*)malloc(sizeof(Stack));
    if (pStack == NULL) return NULL;
    memset(pStack, 0, sizeof(Stack));
    return pStack;
}

int push(Stack *pStack, StackNode node){
    if (pStack == NULL) return FALSE;
    StackNode *pNewNode = (StackNode*)malloc(sizeof(StackNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = node;
    pNewNode->pLink = NULL;
    if (isEmptyStack(pStack) == TRUE){
        pStack->pTopElement = pNewNode;
    }else{
        pNewNode->pLink = pStack->pTopElement;
        pStack->pTopElement = pNewNode;
    }
    pStack->currentElementCount++;

    return TRUE;
}

StackNode *pop(Stack *pStack){
    if (pStack == NULL) return NULL;
    if (isEmptyStack(pStack)) return NULL;
    StackNode *pNode = pStack->pTopElement;
    pStack->pTopElement = pNode->pLink;
    pNode->pLink = NULL;
    pStack->currentElementCount--;
    return pNode;
}

StackNode *peek(Stack *pStack){
    if (pStack == NULL) return NULL;
    if (isEmptyStack(pStack)) return NULL;
    return pStack->pTopElement;
}

int isEmptyStack(Stack *pStack){
    if (pStack== NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}

void deleteStack(Stack *pStack){
    if (pStack == NULL) return;
}
