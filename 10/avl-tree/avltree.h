//
// Created by sanguk on 17/08/2017.
//

#ifndef AVL_TREE_AVLTREE_H
#define AVL_TREE_AVLTREE_H

typedef struct AVLTreeType {
    AVLTreeNode *pRootNode;
} AVLTree;

AVLTree *createAVLTree();

void deleteAVLTree(AVLTree *pAVLTree);

void deleteAVLTreeNode(AVLTreeNode *pAVLTreeNode);

int insertNodeAVL(AVLTree *pAVLTree, AVLTreeNodeData data);

int deleteNodeAVL(AVLTree *pAVLTree, int key);

void balanceAVLTree(AVLTree *pAVLTree, LinkedStack *pStack);

int pushAVLTreeNode(LinkedStack *pStack, AVLTreeNode *data);

AVLTreeNode *popAVLTreeNode(LinkedStack *pStack);

AVLTreeNode *peekAVLTreeNode(LinkedStack *pStack);

AVLTreeNode *rotateLLAVLTree(AVLTreeNode *pParentNode);

AVLTreeNode *rotateLRAVLTree(AVLTreeNode *pParentNode);

AVLTreeNode *rotateRRAVLTree(AVLTreeNode *pParentNode);

AVLTreeNode *rotateRLAVLTree(AVLTreeNode *pParentNode);

void updateHeightAndBalanceAVL(AVLTreeNode *pNode);

AVLTreeNode *searchAVL(AVLTree *pAVLTree, int key);

void displayAVLTree(AVLTree *pTree);

void displayAVLTreeInternal(AVLTreeNode *pTreeNode, int level, char type);

#endif //AVL_TREE_AVLTREE_H
