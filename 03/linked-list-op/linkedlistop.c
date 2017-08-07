//
// Created by sanguk on 07/08/2017.
//

#include <stdio.h>
#include "linkedlist.h"
#include "linkedlistop.h"


void iterateLinkedList(List *pList){
    printf("iterateLinkedList\n");
    if (pList == NULL) return;
    ListNode *pNode;
    int count = 0;
    pNode = pList->headerNode.pLink;
    while (pNode != NULL){
        printf("[%d] - %d ", count, pNode->data);
        pNode = pNode->pLink;
        count ++;
    }
    printf("\n");
}

void concatLinkedList(List *pListA, List *pListB){
    printf("concatLinkedList\n");
    if (pListA == NULL && pListB == NULL) return;
    ListNode *pAEndNode;
    pAEndNode = getElement(pListA, getListLength(pListA) - 1);
    pAEndNode->pLink = pListB->headerNode.pLink;
    pListA->currentElementCount += pListB->currentElementCount;
    pListB->headerNode.pLink = NULL;
    pListB->currentElementCount--;
}

void reverseLinkedList(List *pList){
    printf("reverseLinkedList\n");
    if (pList == NULL) return;
    ListNode *pNode = NULL, *pPrevNode = NULL, *pCurrentNode = NULL;
    pNode = pList->headerNode.pLink;

    while(pNode != NULL){
        pPrevNode = pCurrentNode;
        pCurrentNode = pNode;
        pNode = pNode->pLink;
        pCurrentNode->pLink = pPrevNode;
    }
    pList->headerNode.pLink = pCurrentNode;

}

