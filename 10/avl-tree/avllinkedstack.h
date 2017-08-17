//
// Created by sanguk on 17/08/2017.
//

#ifndef AVL_TREE_AVLLINKEDSTACK_H
#define AVL_TREE_AVLLINKEDSTACK_H

#define TRUE 1
#define FALSE 0

typedef struct StackNodeType {
    AVLTreeNodeData *data;
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

#endif //AVL_TREE_AVLLINKEDSTACK_H
