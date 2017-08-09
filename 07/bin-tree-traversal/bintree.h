//
// Created by sanguk on 09/08/2017.
//

#ifndef BIN_TREE_TRAVERSAL_BINTREE_H
#define BIN_TREE_TRAVERSAL_BINTREE_H

typedef struct BinTreeNodeType {
    char data;
    int visited;

    struct BinTreeNodeType *pLeftChild;
    struct BinTreeNodeType *pRightChild;
} BinTreeNode;

typedef struct BinTreeType {
    struct BinTreeNodeType *pRootNode;
} BinTree;

BinTree *makeBinTree(BinTreeNode rootNode);

BinTreeNode *getRootNodeBT(BinTree *pBinTree);

BinTreeNode *insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element);

BinTreeNode *insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element);

BinTreeNode *getLeftChildNodeBT(BinTreeNode *pNode);

BinTreeNode *getRightChildNodeBT(BinTreeNode *pNode);

void deleteBinTree(BinTree *pBinTree);

void deleteBinTreeNode(BinTreeNode *pNode);

#endif //BIN_TREE_TRAVERSAL_BINTREE_H


#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE        1
#define FALSE        0

#endif
