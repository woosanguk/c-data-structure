#include <stdio.h>
#include "bintree.h"
#include "bintreetraversalrec.h"


BinTree *createExampleBinTree() {
    BinTree* pReturn = NULL;
    BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
    BinTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
    BinTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL;
    BinTreeNode *pNodeM = NULL;
    BinTreeNode node = {0,};

    node.data = 'A';
    pReturn = createBinTree(node);
    if (pReturn != NULL) {
        pNodeA = getRootNode(pReturn);
        node.data = 'B';
        pNodeB = addLeftNode(pNodeA, node);
        node.data = 'C';
        pNodeC = addRightNode(pNodeA, node);
        if (pNodeB != NULL) {
            node.data = 'D';
            pNodeD = addLeftNode(pNodeB, node);
            node.data = 'E';
            pNodeE = addRightNode(pNodeB, node);
        }
        if (pNodeC != NULL) {
            node.data = 'F';
            pNodeF = addLeftNode(pNodeC, node);
            node.data = 'G';
            pNodeG = addRightNode(pNodeC, node);
        }
        if (pNodeD != NULL) {
            node.data = 'H';
            pNodeH = addLeftNode(pNodeD, node);
            node.data = 'I';
            pNodeI = addRightNode(pNodeD, node);
        }
        if (pNodeE != NULL) {
            node.data = 'J';
            pNodeJ = addLeftNode(pNodeE, node);
        }
        if (pNodeF != NULL) {
            node.data = 'K';
            pNodeK = addRightNode(pNodeF, node);
        }
        if (pNodeG != NULL) {
            node.data = 'L';
            pNodeL = addLeftNode(pNodeG, node);
            node.data = 'M';
            pNodeM = addRightNode(pNodeG, node);
        }
    }

    return pReturn;
}


int main() {
    BinTree *pBinTree = NULL;
    pBinTree = createExampleBinTree();

    if (pBinTree != NULL) {
        printf("Preorder Recursive Traversal\n");
        preorderTraversalRecursiveBinTree(pBinTree);

        printf("\nInorder Recursive Traversal\n");
        inorderTraversalRecursiveBinTree(pBinTree);

        printf("\nPostorder Recursive Traversal\n");
        postorderTraversalRecursiveBinTree(pBinTree);
        printf("\n");
        deleteBinTree(pBinTree);
    }
    return 0;
}

