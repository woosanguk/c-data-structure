//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"
#include "bintreeop.h"

BinTree *copyBinTree(BinTree *pSource) {
    BinTree *pReturn = NULL;
    if (pSource == NULL) return NULL;
    pReturn = (BinTree *) malloc(sizeof(BinTree));
    pReturn->pRootNode = copyBinTreeNode(pSource->pRootNode);
    return pReturn;
}

BinTreeNode *copyBinTreeNode(BinTreeNode *pSourceNode) {
    BinTreeNode *pReturn = NULL;
    if (pSourceNode != NULL) {
        pReturn = (BinTreeNode *) malloc(sizeof(BinTreeNode));
        if (pReturn != NULL) {
            pReturn = pSourceNode;
            pReturn->pLeftChild = copyBinTreeNode(getLeftChild(pSourceNode));
            pReturn->pRightChild = copyBinTreeNode(getRightChild(pSourceNode));
        }
    }
    return pReturn;
}

int equalBinTree(BinTree *pFirst, BinTree *pSecond) {
    int ret = FALSE;
    if (pFirst == NULL && pSecond == NULL) {
        ret = TRUE;
    } else if (pFirst != NULL && pSecond != NULL && equalBinTreeNode(pFirst->pRootNode, pSecond->pRootNode) == TRUE) {
        ret = TRUE;
    }
    return ret;
}

int equalBinTreeNode(BinTreeNode *pFirst, BinTreeNode *pSecond) {
    int ret = FALSE;
    if (pFirst == NULL && pSecond == NULL) {
        ret = TRUE;
    } else if (pFirst != NULL && pSecond != NULL
               && pFirst->data == pSecond->data
               && equalBinTreeNode(pFirst->pLeftChild, pSecond->pLeftChild) == TRUE
               && equalBinTreeNode(pFirst->pRightChild, pSecond->pRightChild) == TRUE) {
        ret = TRUE;
    }
    return ret;
}

int getNodeCountBT(BinTree *pSource) {
    int ret = 0;
    if (pSource == NULL) return ret;
    ret = getNodeCountBTNode(pSource->pRootNode);
    return ret;
}

int getNodeCountBTNode(BinTreeNode *pSource) {
    int ret = 0;
    if (pSource == NULL) return ret;
    ret = getNodeCountBTNode(pSource->pLeftChild) + getNodeCountBTNode(pSource->pRightChild) + 1;
    return ret;
}

int getLeafNodeCountBT(BinTree *pSource) {
    int ret = 0;
    if (pSource == NULL) return ret;
    ret = getLeafNodeCountBTNode(pSource->pRootNode);
    return ret;
}

int getLeafNodeCountBTNode(BinTreeNode *pSource) {
    int ret = 0;
    if (pSource == NULL) return ret;
    if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL) {
        ret = 1;
    } else {
        ret = getLeafNodeCountBTNode(pSource->pLeftChild) + getLeafNodeCountBTNode(pSource->pRightChild);
    }
    return ret;
}

int getHeightBT(BinTree *pSource) {
    int ret = 0;
    if (pSource == NULL) return ret;
    ret = getHeightBTNode(pSource->pRootNode);
    return ret;
}

int getHeightBTNode(BinTreeNode *pSource) {
    int ret = 0;
    if (pSource == NULL) return ret;
    if (pSource->pLeftChild == NULL && pSource->pRightChild == NULL) {
        ret = 1;
    } else {
        int leftChildHeight = getHeightBTNode(pSource->pLeftChild);
        int rightChildHeight = getHeightBTNode(pSource->pRightChild);
        ret = rightChildHeight + 1;
        if (leftChildHeight >= rightChildHeight) {
            ret = leftChildHeight + 1;
        }
    }
    return ret;
}

void displayBinTree(BinTree *pTree) {
    if (pTree == NULL) return;
    displayBinTreeNode(pTree->pRootNode, 0, 'O');
}

void displayBinTreeNode(BinTreeNode *pNode, int level, char type) {
    int i = 0;
    if (pNode == NULL) return;
    for (i = 0; i < level; i++) {
        printf("  ");
    }
    printf("-[%i,%c]%c\n", level, type, pNode->data);
    displayBinTreeNode(pNode->pLeftChild, level + 1, 'L');
    displayBinTreeNode(pNode->pRightChild, level + 1, 'R');
}