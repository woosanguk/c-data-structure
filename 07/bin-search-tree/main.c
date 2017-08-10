#include <stdio.h>
#include "binsearchtree.h"

void displayBinSearchTreeInternal(BinSearchTreeNode *pTreeNode, int level, char type){
    int i = 0;
    for (i = 0; i < level ; i++) {
        printf("    ");
    }
    if (pTreeNode != NULL) {
        printf("-[%i,%c]%i-%c\n", level, type,
               pTreeNode->key, pTreeNode->value);
        displayBinSearchTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
        displayBinSearchTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
    }
    else {
        printf("NULL\n");
    }
}

int main() {
    BinSearchTree *pTree = NULL;
    BinSearchTreeNode *pSearchNode = NULL;
    int key = 0;

    BinSearchTreeNode e1 = {30, 'A'};
    BinSearchTreeNode e2 = {20, 'B'};
    BinSearchTreeNode e3 = {40, 'C'};
    BinSearchTreeNode e4 = {10, 'D'};
    BinSearchTreeNode e5 = {24, 'E'};
    BinSearchTreeNode e6 = {34, 'F'};
    BinSearchTreeNode e7 = {46, 'G'};
    BinSearchTreeNode e8 = {6, 'H'};
    BinSearchTreeNode e9 = {14, 'I'};
    BinSearchTreeNode e10 = {22, 'I'};
    BinSearchTreeNode e11 = {50, 'J'};
    BinSearchTreeNode e12 = {2, 'K'};
    BinSearchTreeNode e13 = {38, 'L'};

    pTree = createBinSearchTree();
    if (pTree != NULL)
    {
        insertElementBST(pTree, e1);
        insertElementBST(pTree, e2);
        insertElementBST(pTree, e3);
        insertElementBST(pTree, e4);
        insertElementBST(pTree, e5);
        insertElementBST(pTree, e6);
        insertElementBST(pTree, e7);
        insertElementBST(pTree, e8);
        insertElementBST(pTree, e9);
        insertElementBST(pTree, e10);
        insertElementBST(pTree, e11);
        insertElementBST(pTree, e12);
        insertElementBST(pTree, e13);
        displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');


        key = 14;
        pSearchNode = searchBST(pTree, key);
        if (pSearchNode != NULL) {
            printf("key : [%d], node : [%c]\n", key, pSearchNode->value);
        }

        key = 14;
        pSearchNode = searchRecursiveBST(pTree, key);
        if (pSearchNode != NULL) {
            printf("key : [%d], node : [%c]\n", key, pSearchNode->value);
        }

        key = 30;
        deleteElementBST(pTree, key);
        displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');

        key = 46;
        deleteElementBST(pTree, key);
        displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');

        key = 40;
        deleteElementBST(pTree, key);
        displayBinSearchTreeInternal(pTree->pRootNode, 0, 'O');
        deleteBinSearchTree(pTree);
    }

    return 0;
}