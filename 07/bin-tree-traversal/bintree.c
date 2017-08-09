//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"

BinTree *makeBinTree(BinTreeNode rootNode) {
    BinTree *pBinTree = (BinTree *) malloc(sizeof(BinTree));
    if (pBinTree == NULL) return NULL;
    pBinTree->pRootNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pBinTree->pRootNode == NULL) {
        free(pBinTree);
        return NULL;
    }
    memset(pBinTree->pRootNode, 0, sizeof(BinTreeNode));
    *(pBinTree->pRootNode) = rootNode;
    pBinTree->pRootNode->pLeftChild = NULL;
    pBinTree->pRootNode->pRightChild = NULL;
    return pBinTree;
}

BinTreeNode *getRootNodeBT(BinTree *pBinTree) {
    if (pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element) {
    if (pParentNode == NULL || pParentNode->pLeftChild != NULL) return NULL;
    pParentNode->pLeftChild = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pParentNode->pLeftChild == NULL) return NULL;
    *(pParentNode->pLeftChild) = element;
    pParentNode->pLeftChild->pLeftChild = NULL;
    pParentNode->pLeftChild->pRightChild = NULL;
    return pParentNode->pLeftChild;
}

BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element) {
    if (pParentNode == NULL || pParentNode->pRightChild != NULL) return NULL;
    pParentNode->pRightChild = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pParentNode->pRightChild == NULL) return NULL;
    *(pParentNode->pRightChild) = element;
    pParentNode->pRightChild->pLeftChild = NULL;
    pParentNode->pRightChild->pRightChild = NULL;
    return pParentNode->pRightChild;
}

BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode) {
    if (pNode == NULL) return NULL;
    return pNode->pLeftChild;
}

BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode) {
    if (pNode == NULL) return NULL;
    return pNode->pRightChild;
}

void deleteBinTree(BinTree *pBinTree) {
    if (pBinTree == NULL) return;
    deleteBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);
}

void deleteBinTreeNode(BinTreeNode *pNode) {
    if (pNode == NULL) return;
    deleteBinTreeNode(pNode->pLeftChild);
    deleteBinTreeNode(pNode->pRightChild);
    free(pNode);
}