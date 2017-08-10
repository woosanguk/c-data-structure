//
// Created by sanguk on 10/08/2017.
//

#ifndef BIN_SEARCH_TREE_BINSEARCHTREE_H
#define BIN_SEARCH_TREE_BINSEARCHTREE_H

#define TRUE 1
#define FALSE 0

typedef struct BinSearchTreeNodeType {
    int key;
    char value;

    struct BinSearchTreeNodeType *pLeftChild;
    struct BinSearchTreeNodeType *pRightChild;
} BinSearchTreeNode;

typedef struct BinSearchTreeType {
    BinSearchTreeNode *pRootNode;
} BinSearchTree;

BinSearchTree *createBinSearchTree();

int insertElementBST(BinSearchTree *pBinSearchTree, BinSearchTreeNode element);

int deleteElementBST(BinSearchTree *pBinSearchTree, int key);

BinSearchTreeNode *searchRecursiveBST(BinSearchTree *pBinSearchTree, int key);

BinSearchTreeNode *searchInternalRecursiveBST(BinSearchTreeNode *pTreeNode, int key);

BinSearchTreeNode *searchBST(BinSearchTree *pBinSearchTree, int key);

void deleteBinSearchTree(BinSearchTree *pBinSearchTree);

void deleteBinSearchTreeInternal(BinSearchTreeNode *pTreeNode);

#endif //BIN_SEARCH_TREE_BINSEARCHTREE_H
