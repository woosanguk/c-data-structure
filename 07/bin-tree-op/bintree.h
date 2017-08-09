//
// Created by sanguk on 09/08/2017.
//

#ifndef BIN_TREE_OP_BINTREE_H
#define BIN_TREE_OP_BINTREE_H

#define TRUE 1
#define FALSE 0

typedef struct BinTreeNodeType {
    char data;
    struct BinTreeNodeType *pLeftChild;
    struct BinTreeNodeType *pRightChild;
} BinTreeNode;

typedef struct BinTreeType {
    BinTreeNode *pRootNode;
} BinTree;

BinTree *createBinTree(BinTreeNode node);

BinTreeNode *getRootNode(BinTree *pBinTree);

BinTreeNode *addLeftChild(BinTreeNode *pParentNode, BinTreeNode node);

BinTreeNode *addRightChild(BinTreeNode *pParentNode, BinTreeNode node);

BinTreeNode *getLeftChild(BinTreeNode *pParentNode);

BinTreeNode *getRightChild(BinTreeNode *pParentNode);

void deleteBinTree(BinTree *pBinTree);

void deleteBinTreeNode(BinTreeNode *pNode);


#endif //BIN_TREE_OP_BINTREE_H
