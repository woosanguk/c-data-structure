//
// Created by sanguk on 09/08/2017.
//

#include <stdio.h>
#include "bintree.h"
#include "bintreetraversalrec.h"

void preorderTraversalRecursiveBinTree(BinTree *pBinTree) {
    preorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void preorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode) {
    if (pRootNode == NULL) return;
    printf("%c ", pRootNode->data);
    preorderTraversalRecursiveBinTreeNode(pRootNode->pLeftNode);
    preorderTraversalRecursiveBinTreeNode(pRootNode->pRightNode);
}

void inorderTraversalRecursiveBinTree(BinTree *pBinTree) {
    inorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void inorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode) {
    if (pRootNode == NULL) return;
    inorderTraversalRecursiveBinTreeNode(pRootNode->pLeftNode);
    printf("%c ", pRootNode->data);
    inorderTraversalRecursiveBinTreeNode(pRootNode->pRightNode);
}

void postorderTraversalRecursiveBinTree(BinTree *pBinTree) {
    postorderTraversalRecursiveBinTreeNode(pBinTree->pRootNode);
}

void postorderTraversalRecursiveBinTreeNode(BinTreeNode *pRootNode) {
    if (pRootNode == NULL) return;
    postorderTraversalRecursiveBinTreeNode(pRootNode->pLeftNode);
    postorderTraversalRecursiveBinTreeNode(pRootNode->pRightNode);
    printf("%c ", pRootNode->data);
}
