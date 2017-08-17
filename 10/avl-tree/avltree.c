//
// Created by sanguk on 17/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avldef.h"
#include "avllinkedstack.h"
#include "avltree.h"

AVLTree *createAVLTree() {
    AVLTree *pReturn = NULL;
    pReturn = (AVLTree *) malloc(sizeof(AVLTree));
    memset(pReturn, 0, sizeof(AVLTree));
    return pReturn;
}

void deleteAVLTree(AVLTree *pAVLTree){
    if (pAVLTree == NULL) return;
    deleteAVLTreeNode(pAVLTree->pRootNode);
    free(pAVLTree);
}

void deleteAVLTreeNode(AVLTreeNode *pAVLTreeNode){
    if (pAVLTreeNode == NULL) return;
    deleteAVLTreeNode(pAVLTreeNode->pLeftChild);
    deleteAVLTreeNode(pAVLTreeNode->pRightChild);
    free(pAVLTreeNode);
}

int insertNodeAVL(AVLTree *pAVLTree, AVLTreeNodeData data) {
    AVLTreeNode *pParentNode = NULL, *pNewNode = NULL;
    LinkedStack *pStack = NULL;
    if (pAVLTree == NULL) return FALSE;
    pStack = createLinkedStack();
    if (pStack == NULL) return FALSE;
    pParentNode = pAVLTree->pRootNode;

    while (pParentNode != NULL) {
        pushAVLTreeNode(pStack, pParentNode);
        if (data.key == pParentNode->data.key) {
            deleteLinkedStack(pStack);
            return FALSE;
        } else if (data.key < pParentNode->data.key) {
            if (pParentNode->pLeftChild == NULL) {
                break;
            } else {
                pParentNode = pParentNode->pLeftChild;
            }
        } else {
            if (pParentNode->pRightChild == NULL) {
                break;
            } else {
                pParentNode = pParentNode->pRightChild;
            }
        }
    }

    pNewNode = (AVLTreeNode *) malloc(sizeof(AVLTreeNode));
    if (pNewNode == NULL) {
        deleteLinkedStack(pStack);
        return FALSE;
    }
    pNewNode->data = data;
    pNewNode->height = 1;

    if (pParentNode == NULL) {
        pAVLTree->pRootNode = pNewNode;
    } else {
        if (pNewNode->data.key < pParentNode->data.key) {
            pParentNode->pLeftChild = pNewNode;
        } else {
            pParentNode->pRightChild = pNewNode;
        }
    }

    balanceAVLTree(pAVLTree, pStack);
    deleteLinkedStack(pStack);
    return TRUE;
}

int deleteNodeAVL(AVLTree *pAVLTree, int key) {
    AVLTreeNode *pDelNode = NULL, *pParentNode = NULL, *pPredecessor = NULL, *pSuccessor = NULL, *pChild = NULL;
    LinkedStack *pStackMain = NULL, *pStackSub = NULL;
    if (pAVLTree == NULL) return FALSE;
    pStackMain = createLinkedStack();
    pStackSub = createLinkedStack();
    if (pStackMain == NULL || pStackSub == NULL) return FALSE;
    pDelNode = pAVLTree->pRootNode;
    while (pDelNode != NULL) {
        if (key == pDelNode->data.key) {
            break;
        }
        pParentNode = pDelNode;
        pushAVLTreeNode(pStackMain, pParentNode);
        if (key < pDelNode->data.key) {
            pDelNode = pDelNode->pLeftChild;
        } else {
            pDelNode = pDelNode->pRightChild;
        }
    }
    if (pDelNode == NULL) {
        deleteLinkedStack(pStackMain);
        deleteLinkedStack(pStackSub);
        return FALSE;
    }
    if (pDelNode->pLeftChild == NULL && pDelNode->pRightChild == NULL) {
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = NULL;
            } else {
                pParentNode->pRightChild = NULL;
            }
        } else {
            pAVLTree->pRootNode = NULL;
        }
    } else if (pDelNode->pLeftChild != NULL && pDelNode->pRightChild != NULL) {
        pPredecessor = NULL;
        pSuccessor = pDelNode->pLeftChild;
        pushAVLTreeNode(pStackSub, pSuccessor);

        while (pSuccessor->pRightChild != NULL) {
            pPredecessor = pSuccessor;
            pSuccessor = pSuccessor->pRightChild;
            pushAVLTreeNode(pStackSub, pSuccessor);
        }
        pushAVLTreeNode(pStackMain, popAVLTreeNode(pStackSub));
        if (pPredecessor != NULL) {
            pPredecessor->pRightChild = pSuccessor->pLeftChild;
            pSuccessor->pLeftChild = pDelNode->pLeftChild;
            pushAVLTreeNode(pStackSub, pPredecessor->pRightChild);
        }
        pSuccessor->pRightChild = pDelNode->pRightChild;
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pSuccessor;
            } else {
                pParentNode->pRightChild = pSuccessor;
            }
        } else {
            pAVLTree->pRootNode = pSuccessor;
        }
    } else {
        if (pDelNode->pLeftChild != NULL) {
            pChild = pDelNode->pLeftChild;
        } else {
            pChild = pDelNode->pRightChild;
        }
        if (pParentNode != NULL) {
            if (pParentNode->pLeftChild == pDelNode) {
                pParentNode->pLeftChild = pChild;
            } else {
                pParentNode->pRightChild = pChild;
            }
        } else {
            pAVLTree->pRootNode = pChild;
        }
    }
    free(pDelNode);

    balanceAVLTree(pAVLTree, pStackSub);
    balanceAVLTree(pAVLTree, pStackMain);
    deleteLinkedStack(pStackMain);
    deleteLinkedStack(pStackSub);

    return TRUE;
}

void balanceAVLTree(AVLTree *pAVLTree, LinkedStack *pStack) {
    AVLTreeNode *pParentNode = NULL, *pNode = NULL, *pChildNode = NULL, *pNewNode = NULL;
    if (pAVLTree == NULL || pStack == NULL) return;
    while (isLinkedStackEmpty(pStack) == FALSE) {
        pNode = popAVLTreeNode(pStack);
        if (pNode != NULL) {
            updateHeightAndBalanceAVL(pNode);
            if (pNode->balance >= -1 && pNode->balance <= 1) {
                continue;
            }
            if (pNode->balance > 1) {
                pChildNode = pNode->pLeftChild;
                if (pChildNode->balance > 0) {
                    pNewNode = rotateLLAVLTree(pNode);
                } else {
                    pNewNode = rotateLRAVLTree(pNode);
                }
            } else if (pNode->balance < -1) {
                pChildNode = pNode->pRightChild;
                if (pChildNode->balance < 0) {
                    pNewNode = rotateRRAVLTree(pNode);
                } else {
                    pNewNode = rotateRLAVLTree(pNode);
                }
            }
            pParentNode = peekAVLTreeNode(pStack);
            if (pParentNode != NULL) {
                if (pParentNode->pLeftChild == pNode) {
                    pParentNode->pLeftChild = pNewNode;
                } else {
                    pParentNode->pRightChild = pNewNode;
                }
            } else {
                pAVLTree->pRootNode = pNewNode;
            }
        }
    }
}

int pushAVLTreeNode(LinkedStack *pStack, AVLTreeNode *data) {
    StackNode node = {0,};
    node.data = data;
    return pushLS(pStack, node);
}

AVLTreeNode *popAVLTreeNode(LinkedStack *pStack) {
    StackNode *pNode = popLS(pStack);
    if (pNode == NULL) return NULL;
    return pNode->data;
}

AVLTreeNode *peekAVLTreeNode(LinkedStack *pStack) {
    StackNode *pNode = peekLS(pStack);
    if (pNode == NULL) return NULL;
    return pNode->data;
}

AVLTreeNode *rotateLLAVLTree(AVLTreeNode *pParentNode) {
    AVLTreeNode *pLeftNode = NULL;
    if (pParentNode == NULL) return NULL;
    pLeftNode = pParentNode->pLeftChild;
    pParentNode->pLeftChild = pLeftNode->pRightChild;
    pLeftNode->pRightChild = pParentNode;
    updateHeightAndBalanceAVL(pParentNode);
    updateHeightAndBalanceAVL(pLeftNode);
    return pLeftNode;
}

AVLTreeNode *rotateLRAVLTree(AVLTreeNode *pParentNode) {
    AVLTreeNode *pReturn = NULL, *pLeftNode = NULL;
    if (pParentNode == NULL) return NULL;
    pLeftNode = pParentNode->pLeftChild;
    pParentNode->pLeftChild = rotateRRAVLTree(pLeftNode);
    pReturn = rotateLLAVLTree(pParentNode);
    return pReturn;
}

AVLTreeNode *rotateRRAVLTree(AVLTreeNode *pParentNode) {
    AVLTreeNode *pRightNode = NULL;
    if (pParentNode == NULL) return NULL;
    pRightNode = pParentNode->pRightChild;
    pParentNode->pRightChild = pRightNode->pLeftChild;
    pRightNode->pLeftChild = pParentNode;
    updateHeightAndBalanceAVL(pParentNode);
    updateHeightAndBalanceAVL(pRightNode);
    return pRightNode;
}

AVLTreeNode *rotateRLAVLTree(AVLTreeNode *pParentNode) {
    AVLTreeNode *pReturn = NULL, *pRightNode = NULL;
    if (pParentNode == NULL) return NULL;
    pRightNode = pParentNode->pRightChild;
    pParentNode->pRightChild = rotateLLAVLTree(pRightNode);
    pReturn = rotateRRAVLTree(pParentNode);
    return pReturn;
}

void updateHeightAndBalanceAVL(AVLTreeNode *pNode) {
    int leftHeight = 0;
    int rightHeight = 0;
    if (pNode == NULL) return;
    if (pNode->pLeftChild != NULL) {
        leftHeight = pNode->pLeftChild->height;
    }
    if (pNode->pRightChild != NULL) {
        rightHeight = pNode->pRightChild->height;
    }
    if (leftHeight > rightHeight) {
        pNode->height = leftHeight + 1;
    } else {
        pNode->height = rightHeight + 1;
    }
    pNode->balance = leftHeight - rightHeight;
}

AVLTreeNode *searchAVL(AVLTree *pAVLTree, int key) {
    AVLTreeNode *pReturn = NULL, *pNode = NULL;
    if (pAVLTree == NULL) return NULL;
    pNode = pAVLTree->pRootNode;
    if (pNode == NULL) return NULL;
    while (pNode != NULL) {
        if (key == pNode->data.key) {
            pReturn = pNode;
        } else if (key < pNode->data.key) {
            pNode = pNode->pLeftChild;
        } else {
            pNode = pNode->pRightChild;
        }
    }
    return pReturn;
}

void displayAVLTree(AVLTree *pTree){
    displayAVLTreeInternal(pTree->pRootNode, 0, ' ');
}

void displayAVLTreeInternal(AVLTreeNode *pTreeNode, int level, char type){
    int i = 0;
    for (i = 0; i < level ; i++) {
        printf("    ");
    }
    if (pTreeNode != NULL) {
        printf("-[%i,%i,%c],%i-%s\n", pTreeNode->height, pTreeNode->balance, type,
               pTreeNode->data.key, pTreeNode->data.value);
        displayAVLTreeInternal(pTreeNode->pLeftChild, level + 1, 'L');
        displayAVLTreeInternal(pTreeNode->pRightChild, level + 1, 'R');
    }
    else {
        printf("NULL\n");
    }
}

