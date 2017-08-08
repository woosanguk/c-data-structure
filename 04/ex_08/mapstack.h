//
// Created by sanguk on 08/08/2017.
//

#ifndef EX_08_MAPSTACK_H
#define EX_08_MAPSTACK_H

#define FALSE 0
#define TRUE 1

typedef struct StackNodeType {
    MapPosition data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct StackNode {
    int currentElementCount;
    StackNode *pTomElement;
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode node);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

int isEmptyStack(Stack *pStack);

void deleteStack(Stack *pStack);

#endif //EX_08_MAPSTACK_H
