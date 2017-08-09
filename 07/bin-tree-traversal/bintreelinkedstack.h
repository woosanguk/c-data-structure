//
// Created by sanguk on 09/08/2017.
//

#ifndef BIN_TREE_TRAVERSAL_BINTREELINKEDSTACK_H
#define BIN_TREE_TRAVERSAL_BINTREELINKEDSTACK_H

typedef struct StackNodeType {
    BinTreeNode *data;
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

#endif //BIN_TREE_TRAVERSAL_BINTREELINKEDSTACK_H

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE        1
#define FALSE        0

#endif



