//
// Created by sanguk on 08/08/2017.
//

#ifndef STACK_CALC_EXPRLINKEDSTACK_H
#define STACK_CALC_EXPRLINKEDSTACK_H

#define TRUE 1
#define FALSE 0

typedef struct StackNodeType {
    ExprToken data;
    struct StackNodeType *pLink;
} StackNode;

typedef struct StackType {
    int currentElementCount;
    StackNode *pTopElement;
} Stack;

Stack *createStack();

int push(Stack *pStack, StackNode element);

StackNode *pop(Stack *pStack);

StackNode *peek(Stack *pStack);

void deleteStack(Stack *pStack);

int isStackEmpty(Stack *pStack);


#endif //STACK_CALC_EXPRLINKEDSTACK_H
