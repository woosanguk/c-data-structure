//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bintree.h"


BinTree *makeBinTree(BinTreeNode rootNode) {
    BinTree *pReturn = (BinTree *) malloc(sizeof(BinTree));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(BinTree));
    pReturn->pRootNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pReturn->pRootNode == NULL) {
        free(pReturn);
        return NULL;
    }
    *pReturn->pRootNode = rootNode;
    pReturn->pRootNode->pLeftChild = NULL;
    pReturn->pRootNode->pRightChild = NULL;
    return pReturn;
}

BinTreeNode *getRootNodeBT(BinTree *pBinTree) {
    if (pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element) {
    BinTreeNode *pNewNode = NULL;
    if (pParentNode == NULL) return NULL;
    if (pParentNode->pLeftChild != NULL) return NULL;
    pNewNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pNewNode == NULL) return NULL;
    *pNewNode = element;
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;
    pParentNode->pLeftChild = pNewNode;
    return pNewNode;
}

BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element) {
    BinTreeNode *pNewNode = NULL;
    if (pParentNode == NULL) return NULL;
    if (pParentNode->pRightChild != NULL) return NULL;
    pNewNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pNewNode == NULL) return NULL;
    *pNewNode = element;
    pNewNode->pLeftChild = NULL;
    pNewNode->pRightChild = NULL;
    pParentNode->pRightChild = pNewNode;
    return pNewNode;
}

BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode) {
    if (pNode == NULL) return NULL;
    if (pNode->pLeftChild == NULL) return NULL;
    return pNode->pLeftChild;
}

BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode) {
    if (pNode == NULL) return NULL;
    if (pNode->pRightChild == NULL) return NULL;
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