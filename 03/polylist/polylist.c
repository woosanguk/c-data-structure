//
// Created by sanguk on 07/08/2017.
//

#include "linkedlist.h"
#include "polylist.h"
#include <stdio.h>

int addPolyNodeLast(List *pList, float coef, int degree) {
    ListNode node;
    node.coef = coef;
    node.degree = degree;
    addElement(pList, getListLength(pList), node);
    return FALSE;
}

List *polyAdd(List *pListA, List *pListB) {
    if (pListA == NULL || pListB == NULL) return NULL;
    List *pList = createList();
    if (pList == NULL) return NULL;
    ListNode *pListANode, *pListBNode;
    pListANode = pListA->headerNode.pLink;
    pListBNode = pListB->headerNode.pLink;
    while (pListANode != NULL && pListBNode != NULL) {
        if (pListANode->degree == pListBNode->degree) {
            addPolyNodeLast(pList, pListANode->coef + pListBNode->coef, pListANode->degree);
            pListANode = pListANode->pLink;
            pListBNode = pListBNode->pLink;
        } else if (pListANode->degree > pListBNode->degree) {
            addPolyNodeLast(pList, pListANode->coef, pListANode->degree);
            pListANode = pListANode->pLink;
        } else {
            addPolyNodeLast(pList, pListBNode->coef, pListBNode->degree);
            pListBNode = pListBNode->pLink;
        }
    }

    while (pListBNode != NULL) {
        addPolyNodeLast(pList, pListBNode->coef, pListBNode->degree);
        pListBNode = pListBNode->pLink;
    }

    while (pListANode != NULL) {
        addPolyNodeLast(pList, pListANode->coef, pListANode->degree);
        pListANode = pListANode->pLink;
    }


    return pList;
}

void displayPolyList(List *pList) {
    printf("displayPolyList\n");
    if (pList == NULL) return;
    ListNode *pNode;
    for (int i = 0; i < getListLength(pList); i++) {
        pNode = getElement(pList, i);
        if (pNode != NULL) {
            printf("%5.1fx^%d", pNode->coef, pNode->degree);
        }
    }
    printf("\n");


}
