#include <stdio.h>
#include "bintree.h"
#include "bintreeop.h"

BinTree *createExampleBinTree() {
    BinTree *pReturn = NULL;
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
        pNodeB = addLeftChild(pNodeA, node);
        node.data = 'C';
        pNodeC = addRightChild(pNodeA, node);
        if (pNodeB != NULL) {
            node.data = 'D';
            pNodeD = addLeftChild(pNodeB, node);
            node.data = 'E';
            pNodeE = addRightChild(pNodeB, node);
        }
        if (pNodeC != NULL) {
            node.data = 'F';
            pNodeF = addLeftChild(pNodeC, node);
            node.data = 'G';
            pNodeG = addRightChild(pNodeC, node);
        }
        if (pNodeD != NULL) {
            node.data = 'H';
            pNodeH = addLeftChild(pNodeD, node);
            node.data = 'I';
            pNodeI = addRightChild(pNodeD, node);
        }
        if (pNodeE != NULL) {
            node.data = 'J';
            pNodeJ = addLeftChild(pNodeE, node);
        }
        if (pNodeF != NULL) {
            node.data = 'K';
            pNodeK = addRightChild(pNodeF, node);
        }
        if (pNodeG != NULL) {
            node.data = 'L';
            pNodeL = addLeftChild(pNodeG, node);
        }
    }

    return pReturn;
}

BinTree *createExampleBinTree2() {
    BinTree *pReturn = NULL;
    BinTreeNode *pNodeA = NULL, *pNodeB = NULL, *pNodeC = NULL;
    BinTreeNode *pNodeD = NULL, *pNodeE = NULL, *pNodeF = NULL;
    BinTreeNode *pNodeG = NULL, *pNodeH = NULL, *pNodeI = NULL;
    BinTreeNode *pNodeJ = NULL, *pNodeK = NULL, *pNodeL = NULL;
    BinTreeNode *pNodeM = NULL, *pNodeN = NULL, *pNodeO = NULL;
    BinTreeNode node = {0,};

    node.data = 'A';
    pReturn = createBinTree(node);
    if (pReturn != NULL) {
        pNodeA = getRootNode(pReturn);
        node.data = 'B';
        pNodeB = addLeftChild(pNodeA, node);
        node.data = 'C';
        pNodeC = addRightChild(pNodeA, node);
        if (pNodeB != NULL) {
            node.data = 'D';
            pNodeD = addLeftChild(pNodeB, node);
            node.data = 'E';
            pNodeE = addRightChild(pNodeB, node);
        }
        if (pNodeC != NULL) {
            node.data = 'F';
            pNodeF = addLeftChild(pNodeC, node);
            node.data = 'G';
            pNodeG = addRightChild(pNodeC, node);
        }
        if (pNodeD != NULL) {
            node.data = 'H';
            pNodeH = addLeftChild(pNodeD, node);
            node.data = 'I';
            pNodeI = addRightChild(pNodeD, node);
        }
        if (pNodeE != NULL) {
            node.data = 'J';
            pNodeJ = addLeftChild(pNodeE, node);
        }
        if (pNodeF != NULL) {
            node.data = 'K';
            pNodeK = addRightChild(pNodeF, node);
        }
        if (pNodeG != NULL) {
            node.data = 'W';
            pNodeL = addLeftChild(pNodeG, node);
            node.data = 'M';
            pNodeM = addRightChild(pNodeG, node);
        }
        if (pNodeM != NULL) {
            node.data = "n";
            pNodeN = addRightChild(pNodeM, node);
        }
        if (pNodeN != NULL) {
            node.data = "q";
            pNodeO = addLeftChild(pNodeN, node);
        }
    }

    return pReturn;
}

int main() {
    int compareResult = FALSE;
    int count = 0;
    BinTree *pBinTree = NULL, *pBinTree2 = NULL, *pCopyBinTree = NULL;

    pBinTree = createExampleBinTree();
    pBinTree2 = createExampleBinTree2();
    displayBinTree(pBinTree);
    displayBinTree(pBinTree2);

    pCopyBinTree = copyBinTree(pBinTree);
    displayBinTree(pCopyBinTree);

    compareResult = equalBinTree(pBinTree, pCopyBinTree);
    printf("\ncompareResult : (%d)\n", compareResult);

    compareResult = equalBinTree(pBinTree, pBinTree2);
    printf("\ncompareResult : (%d)\n", compareResult);

    count = getNodeCountBT(pBinTree);
    printf("\nnodeCount : (%d)\n", count);

    count = getNodeCountBT(pBinTree2);
    printf("\nnodeCount : (%d)\n", count);

    count = getLeafNodeCountBT(pBinTree);
    printf("\nleafNodeCount : (%d)\n", count);

    count = getLeafNodeCountBT(pBinTree2);
    printf("\nleafNodeCount : (%d)\n", count);

    count = getHeightBT(pBinTree);
    printf("\nheightCount : (%d)\n", count);

    count = getHeightBT(pBinTree2);
    printf("\nheightCount : (%d)\n", count);

    deleteBinTree(pBinTree);
    deleteBinTree(pBinTree2);
    deleteBinTree(pCopyBinTree);
    return 0;
}