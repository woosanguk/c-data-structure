//
// Created by sanguk on 09/08/2017.
//

#ifndef BIN_TREE_TRAVERSAL_BINTREE_H
#define BIN_TREE_TRAVERSAL_BINTREE_H

#define TRUE 1
#define FALSE 0

typedef struct BinTreeNodeType {
    char data;
    struct BinTreeNodeType *pLeftNode;
    struct BinTreeNodeType *pRightNode;
} BinTreeNode;

typedef struct BinTreeType {
    BinTreeNode *pRootNode;
} BinTree;

BinTree *createBinTree(BinTreeNode node);

BinTreeNode *getRootNode(BinTree *pBinTree);

BinTreeNode *addLeftNode(BinTreeNode *pNode, BinTreeNode node);

BinTreeNode *addRightNode(BinTreeNode *pNode, BinTreeNode node);

BinTreeNode *getLeftNode(BinTreeNode *pNode);

BinTreeNode *getRightNode(BinTreeNode *pNode);

void deleteBinTree(BinTree *pBinTree);

void deleteBinTreeNode(BinTreeNode *pNode);

#endif //BIN_TREE_TRAVERSAL_BINTREE_H
