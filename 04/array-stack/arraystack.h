//
// Created by sanguk on 07/08/2017.
//

#ifndef ARRAY_STACK_ARRAYSTACK_H
#define ARRAY_STACK_ARRAYSTACK_H

#define TRUE        1
#define FALSE        0

typedef struct StackNodeType {
    char data;
} StackNode;

typedef struct StackType {
    int maxElementCount;
    int currentElementCount;
    StackNode *pElement;
} Stack;

Stack *createStack(int maxElementCount);

int push(Stack *pStack, StackNode element);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

void deleteStack(Stack *pStack);

int isStackFull(Stack *pStack);

int isStackEmpty(Stack *pStack);


#endif //ARRAY_STACK_ARRAYSTACK_H
