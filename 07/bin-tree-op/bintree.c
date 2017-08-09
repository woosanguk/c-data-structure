//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


BinTree *createBinTree(BinTreeNode node) {
    BinTree *pReturn = NULL;
    pReturn = (BinTree *) malloc(sizeof(BinTree));
    if (pReturn == NULL) return NULL;
    pReturn->pRootNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pReturn->pRootNode == NULL) {
        free(pReturn);
        return NULL;
    }
    *(pReturn->pRootNode) = node;
    pReturn->pRootNode->pLeftChild = NULL;
    pReturn->pRootNode->pRightChild = NULL;
    return pReturn;
}

BinTreeNode *getRootNode(BinTree *pBinTree) {
    if (pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode *addLeftChild(BinTreeNode *pParentNode, BinTreeNode node) {
    BinTreeNode *pNowNode = NULL;
    if (pParentNode == NULL || pParentNode->pLeftChild != NULL) return NULL;
    pNowNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    *pNowNode = node;
    pNowNode->pLeftChild = NULL;
    pNowNode->pRightChild = NULL;
    pParentNode->pLeftChild = pNowNode;
    return pParentNode->pLeftChild;
}

BinTreeNode *addRightChild(BinTreeNode *pParentNode, BinTreeNode node) {
    BinTreeNode *pNowNode = NULL;
    if (pParentNode == NULL || pParentNode->pRightChild != NULL) return NULL;
    pNowNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    *pNowNode = node;
    pNowNode->pLeftChild = NULL;
    pNowNode->pRightChild = NULL;
    pParentNode->pRightChild = pNowNode;
    return pParentNode->pRightChild;
}

BinTreeNode *getLeftChild(BinTreeNode *pParentNode) {
    if (pParentNode == NULL) return NULL;
    return pParentNode->pLeftChild;
}

BinTreeNode *getRightChild(BinTreeNode *pParentNode) {
    if (pParentNode == NULL) return NULL;
    return pParentNode->pRightChild;
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