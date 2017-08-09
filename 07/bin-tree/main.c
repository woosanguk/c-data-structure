#include <stdio.h>
#include "bintree.h"

int main() {
    BinTree *pBinTree = NULL;
    BinTreeNode node = {0,};
    BinTreeNode *pRootNode = NULL;
    node.data = 'a';
    pBinTree = makeBinTree(node);

    if (pBinTree != NULL){
        pRootNode = getRootNodeBT(pBinTree);
        printf("%c ", pRootNode->data);
        node.data = 'b';
        insertLeftChildNodeBT(pRootNode, node);
        node.data = 'c';
        insertRightChildNodeBT(pRootNode, node);

        printf("%c ", getLeftChildNodeBT(pRootNode)->data);
        printf("%c ", getRightChildNodeBT(pRootNode)->data);

        deleteBinTree(pBinTree);
    }

    return 0;
}