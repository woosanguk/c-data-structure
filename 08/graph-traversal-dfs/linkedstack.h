//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_TRAVERSAL_LINKEDSTACK_H
#define GRAPH_TRAVERSAL_LINKEDSTACK_H

#define TRUE 1
#define FALSE 0

typedef struct StackNodeType {
    char data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct LinkedStackType {
    int currentElementCount;
    StackNode *pTopElement;
} LinkedStack;

LinkedStack *createLinkedStack();

int pushLS(LinkedStack *pStack, StackNode element);

StackNode *popLS(LinkedStack *pStack);

StackNode *peekLS(LinkedStack *pStack);

void deleteLinkedStack(LinkedStack *pStack);

int isLinkedStackFull(LinkedStack *pStack);

int isLinkedStackEmpty(LinkedStack *pStack);


#endif //GRAPH_TRAVERSAL_LINKEDSTACK_H
