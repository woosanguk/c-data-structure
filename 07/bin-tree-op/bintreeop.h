//
// Created by sanguk on 09/08/2017.
//

#ifndef BIN_TREE_OP_BINTREEOP_H
#define BIN_TREE_OP_BINTREEOP_H

BinTree *copyBinTree(BinTree *pSource);

BinTreeNode *copyBinTreeNode(BinTreeNode *pSourceNode);

int equalBinTree(BinTree *pFirst, BinTree *pSecond);

int equalBinTreeNode(BinTreeNode *pFirst, BinTreeNode *pSecond);

int getNodeCountBT(BinTree *pSource);

int getNodeCountBTNode(BinTreeNode *pSource);

int getLeafNodeCountBT(BinTree *pSource);

int getLeafNodeCountBTNode(BinTreeNode *pSource);

int getHeightBT(BinTree *pSource);

int getHeightBTNode(BinTreeNode *pSource);

void displayBinTree(BinTree *pTree);

void displayBinTreeNode(BinTreeNode *pNode, int level, char type);

#endif //BIN_TREE_OP_BINTREEOP_H
