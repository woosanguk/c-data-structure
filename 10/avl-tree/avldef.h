//
// Created by sanguk on 17/08/2017.
//

#ifndef AVL_TREE_AVLDEF_H
#define AVL_TREE_AVLDEF_H

#define VALUE_SIZE 100

typedef struct AVLTreeNodeDataType {
    int key;
    char value[VALUE_SIZE + 1];
} AVLTreeNodeData;

typedef struct AVLTreeNodeType {
    AVLTreeNodeData data;
    int balance;
    int height;
    struct AVLTreeNodeType *pLeftChild;
    struct AVLTreeNodeType *pRightChild;
} AVLTreeNode;

#endif //AVL_TREE_AVLDEF_H
