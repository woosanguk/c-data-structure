//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "bintree.h"


BinTree *createBinTree(BinTreeNode node) {
    BinTree *pReturn = NULL;
    pReturn = (BinTree *) malloc(sizeof(BinTree));
    if (pReturn == NULL)return NULL;
    pReturn->pRootNode = (BinTreeNode *) malloc(sizeof(BinTreeNode));
    if (pReturn->pRootNode == NULL) {
        free(pReturn);
        return NULL;
    }
    *(pReturn->pRootNode) = node;
    pReturn->pRootNode->pLeftNode = NULL;
    pReturn->pRootNode->pRightNode = NULL;
    return pReturn;
}

BinTreeNode *getRootNode(BinTree *pBinTree){
    if (pBinTree == NULL) return NULL;
    return pBinTree->pRootNode;
}

BinTreeNode *addLeftNode(BinTreeNode *pNode, BinTreeNode node){
    BinTreeNode *pNewNode = NULL;
    if (pNode == NULL) return NULL;
    if (pNode->pLeftNode != NULL) return NULL;
    pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if (pNewNode == NULL) return NULL;
    *(pNewNode) = node;
    pNewNode->pLeftNode = NULL;
    pNewNode->pRightNode = NULL;
    pNode->pLeftNode = pNewNode;
    return pNewNode;
}

BinTreeNode *addRightNode(BinTreeNode *pNode, BinTreeNode node){
    BinTreeNode *pNewNode = NULL;
    if (pNode == NULL) return NULL;
    if (pNode->pRightNode != NULL) return NULL;
    pNewNode = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    if (pNewNode == NULL) return NULL;
    *(pNewNode) = node;
    pNewNode->pLeftNode = NULL;
    pNewNode->pRightNode = NULL;
    pNode->pRightNode = pNewNode;
    return pNewNode;
}

BinTreeNode *getLeftNode(BinTreeNode *pNode){
    if (pNode == NULL) return NULL;
    return pNode->pLeftNode;
}

BinTreeNode *getRightNode(BinTreeNode *pNode){
    if (pNode == NULL) return NULL;
    return pNode->pRightNode;
}

void deleteBinTree(BinTree *pBinTree){
    if (pBinTree == NULL) return;
    deleteBinTreeNode(pBinTree->pRootNode);
    free(pBinTree);

}

void deleteBinTreeNode(BinTreeNode *pNode){
    deleteBinTreeNode(pNode->pLeftNode);
    deleteBinTreeNode(pNode->pRightNode);
    free(pNode);
}