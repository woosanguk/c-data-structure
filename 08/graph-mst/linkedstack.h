//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_MST_LINKEDSTACK_H
#define GRAPH_MST_LINKEDSTACK_H

#define TRUE 1
#define FALSE 0

typedef struct StackNodeType {
    int data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct StackType {
    int currentElementCount;
    StackNode *pTopElement;
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode node);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

int isStackEmpty(Stack *pStack);

void deleteStack(Stack *pStack);


#endif //GRAPH_MST_LINKEDSTACK_H
