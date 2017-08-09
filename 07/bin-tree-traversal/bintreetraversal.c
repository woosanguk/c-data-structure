//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreelinkedstack.h"
#include "bintreelinkedqueue.h"
#include "bintreetraversal.h"

int pushLSBinTreeNode(LinkedStack *pStack, BinTreeNode *pNode) {
    StackNode node = {0,};
    node.data = pNode;
    return pushLS(pStack, node);
}

int enqueueLQBinTreeNode(LinkedQueue *pQueue, BinTreeNode *pNode) {
    QueueNode node = {0,};
    node.data = pNode;
    return enqueueLQ(pQueue, node);
}

void preorderTraversalBinTree(BinTree *pBinTree) {
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftNode = NULL, *pRightNode = NULL;
    int isEmpty = FALSE;

    if (pBinTree == NULL) return;
    pStack = createLinkedStack();
    if (pStack == NULL) return;
    pushLSBinTreeNode(pStack, getRootNodeBT(pBinTree));

    while (isEmpty == FALSE) {
        pStackNode = popLS(pStack);
        pRootNode = pStackNode->data;
        printf("%c ", pRootNode->data);
        pLeftNode = getLeftChildNodeBT(pRootNode);
        pRightNode = getRightChildNodeBT(pRootNode);
        if (pRightNode != NULL) {
            pushLSBinTreeNode(pStack, pRightNode);
        }
        if (pLeftNode != NULL) {
            pushLSBinTreeNode(pStack, pLeftNode);
        }
        free(pStackNode);
        isEmpty = isLinkedStackEmpty(pStack);
    }
    deleteLinkedStack(pStack);
}

void inorderTraversalBinTree(BinTree *pBinTree) {
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    BinTreeNode *pNode = NULL;
    if (pBinTree == NULL) return;
    pStack = createLinkedStack();
    if (pStack == NULL) return;
    pNode = getRootNodeBT(pBinTree);
    while (1) {
        for (; pNode != NULL; pNode = getLeftChildNodeBT(pNode)) {
            pushLSBinTreeNode(pStack, pNode);
        }
        if (isLinkedStackEmpty(pStack) == TRUE) {
            break;
        } else {
            pStackNode = popLS(pStack);
            if (pStackNode != NULL) {
                pNode = pStackNode->data;
                printf("%c ", pNode->data);
                pNode = getRightChildNodeBT(pNode);
                free(pStackNode);
            }
        }
    }
    deleteLinkedStack(pStack);
}

void postorderTraversalBinTree(BinTree *pBinTree) {
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;
    int isEmpty = FALSE;
    if (pBinTree == NULL) return;
    pStack = createLinkedStack();
    if (pStack == NULL) return;
    pushLSBinTreeNode(pStack, getRootNodeBT(pBinTree));
    while (isEmpty == FALSE) {
        pStackNode = peekLS(pStack);
        if (pStackNode != NULL) {
            pRootNode = pStackNode->data;
            pLeftChildNode = getLeftChildNodeBT(pRootNode);
            if (pLeftChildNode != NULL && pLeftChildNode->visited == FALSE) {
                pushLSBinTreeNode(pStack, pLeftChildNode);
            } else {
                pRightChildNode = getRightChildNodeBT(pRootNode);
                if (pRightChildNode != NULL && pRightChildNode->visited == FALSE) {
                    pushLSBinTreeNode(pStack, pRightChildNode);
                } else {
                    pRootNode->visited = TRUE;
                    printf("%c ", pRootNode->data);
                    free(popLS(pStack));
                }
            }
        }
        isEmpty = isLinkedStackEmpty(pStack);
    }
    deleteLinkedStack(pStack);
}

void levelOrderTraversalBinTree(BinTree *pBinTree) {
    LinkedQueue *pQueue = NULL;
    QueueNode *pQueueNode = NULL;
    BinTreeNode *pRootNode = NULL, *pLeftChildNode = NULL, *pRightChildNode = NULL;
    int isEmpty = FALSE;

    if (pBinTree == NULL) return;
    pQueue = createLinkedQueue();
    pRootNode = getRootNodeBT(pBinTree);

    enqueueLQBinTreeNode(pQueue, pRootNode);

    while (isEmpty == FALSE) {
        pQueueNode = dequeueLQ(pQueue);
        pRootNode = pQueueNode->data;
        printf("%c ", pRootNode->data);
        pLeftChildNode = getLeftChildNodeBT(pRootNode);
        pRightChildNode = getRightChildNodeBT(pRootNode);
        if (pLeftChildNode != NULL) {
            enqueueLQBinTreeNode(pQueue, pLeftChildNode);
        }
        if (pRightChildNode != NULL) {
            enqueueLQBinTreeNode(pQueue, pRightChildNode);
        }
        free(pQueueNode);
        isEmpty = isLinkedQueueEmpty(pQueue);
    }
    deleteLinkedQueue(pQueue);
}
