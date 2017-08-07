//
// Created by sanguk on 07/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraystack.h"


Stack *createStack(int maxElementCount) {
    Stack *pStack = NULL;
    if (maxElementCount < 1) return NULL;
    pStack = (Stack *) malloc(sizeof(Stack));
    if (pStack == NULL) return NULL;
    pStack->currentElementCount = 0;
    pStack->maxElementCount = maxElementCount;
    pStack->pElement = (StackNode *) malloc(sizeof(StackNode) * maxElementCount);
    if (pStack->pElement == NULL) {
        free(pStack);
        return NULL;
    }
    memset(pStack->pElement, 0, sizeof(StackNode) * maxElementCount);
    return pStack;
}

int push(Stack *pStack, StackNode element) {
    if (pStack == NULL) return FALSE;
    if (isStackFull(pStack)) return FALSE;
    pStack->pElement[pStack->currentElementCount] = element;
    pStack->currentElementCount++;
    return TRUE;
}

StackNode *pop(Stack *pStack) {
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack)) return NULL;
    StackNode *pStackNode = (StackNode *) malloc(sizeof(StackNode));
    *pStackNode = pStack->pElement[pStack->currentElementCount - 1];
    pStack->currentElementCount--;
    return pStackNode;
}

StackNode *peek(Stack *pStack) {
    if (pStack == NULL) return NULL;
    if (isStackEmpty(pStack)) return NULL;
    return &(pStack->pElement[pStack->currentElementCount - 1]);
}

void deleteStack(Stack *pStack) {
    if (pStack == NULL) return;
    if (pStack->pElement != NULL) {
        free(pStack->pElement);
    }
    free(pStack);
}

int isStackFull(Stack *pStack) {
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == pStack->maxElementCount) return TRUE;
    return FALSE;
}

int isStackEmpty(Stack *pStack) {
    if (pStack == NULL) return FALSE;
    if (pStack->currentElementCount == 0) return TRUE;
    return FALSE;
}
