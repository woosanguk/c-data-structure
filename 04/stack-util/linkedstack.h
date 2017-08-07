//
// Created by sanguk on 07/08/2017.
//

#ifndef STACK_UTIL_LINKEDSTACK_H
#define STACK_UTIL_LINKEDSTACK_H

#define TRUE 1
#define FALSE 0

typedef struct StackNodeType {
    char data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct StackType {
    int currentElementCount;
    StackNode *pTopNode;
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode node);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

int isEmptyStack(Stack *pStack);

void deleteStack(Stack *pStack);

#endif //STACK_UTIL_LINKEDSTACK_H
