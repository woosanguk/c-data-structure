#include <stdio.h>
#include <stdlib.h>
#include "avldef.h"
#include "avllinkedstack.h"
#include "avltree.h"


int main() {
    AVLTree *pTree = NULL;

    AVLTreeNodeData eB = {9, "key = 9"};
    AVLTreeNodeData eG = {3, "key = 3"};
    AVLTreeNodeData eE = {1, "key = 1"};
    AVLTreeNodeData eC = {10, "key = 10"};
    AVLTreeNodeData eL = {12, "key = 12"};
    AVLTreeNodeData eH = {6, "key = 6"};
    AVLTreeNodeData eI = {4, "key = 4"};
    AVLTreeNodeData eF = {5, "key = 5"};

    pTree = createAVLTree();
    if (pTree != NULL) {
        printf("1)\n");
        insertNodeAVL(pTree, eB);
        displayAVLTree(pTree);

        printf("\n2)\n");
        insertNodeAVL(pTree, eG);
        displayAVLTree(pTree);

        printf("\n3) LL\n");
        insertNodeAVL(pTree, eE);
        displayAVLTree(pTree);

        printf("\n4)\n");
        insertNodeAVL(pTree, eC);
        displayAVLTree(pTree);

        printf("\n5) RR˝\n");
        insertNodeAVL(pTree, eL);
        displayAVLTree(pTree);

        printf("\n6) RL˝\n");
        insertNodeAVL(pTree, eH);
        displayAVLTree(pTree);

        printf("\n7)\n");
        insertNodeAVL(pTree, eI);
        displayAVLTree(pTree);

        printf("\n8) LR˝\n");
        insertNodeAVL(pTree, eF);
        displayAVLTree(pTree);

        printf("\n9)˝\n");
        deleteNodeAVL(pTree, 5);
        displayAVLTree(pTree);

        deleteAVLTree(pTree);
    }
    return 0;
}