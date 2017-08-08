//
// Created by sanguk on 07/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circularlist.h"


List *createList() {
    List *pList = (List *) malloc(sizeof(List));
    if (pList == NULL) return NULL;
    memset(pList, 0, sizeof(pList));
    return pList;
}

int addElement(List *pList, int position, ListNode node) {
    ListNode *pPreNode = NULL, *pNewNode = NULL, *pLastNode = NULL;
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getListLength(pList)) return FALSE;
    pNewNode = (ListNode *) malloc(sizeof(ListNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = node;
    pNewNode->pLink = NULL;
    if (position == 0) {
        if (getListLength(pList) == 0) {
            pList->headerNode.pLink = pNewNode;
            pNewNode->pLink = pNewNode;
        } else {
            pPreNode = &(pList->headerNode);
            for (int i = 0; i < getListLength(pList); i++) {
                pPreNode = pPreNode->pLink;
            }
            pNewNode->pLink = pList->headerNode.pLink;
            pList->headerNode.pLink = pNewNode;
            pPreNode->pLink = pNewNode;
        }
    } else {
        pPreNode = &(pList->headerNode);
        for (int i = 0; i < position; i++) {
            pPreNode = pPreNode->pLink;
        }
        pNewNode->pLink = pPreNode->pLink;
        pPreNode->pLink = pNewNode;
    };

    pList->currentElementCount++;

    return TRUE;
}

int removeElement(List *pList, int position) {
    ListNode *pPreNode = NULL, *pDelNode = NULL;
    if (pList == NULL) return FALSE;
    if (position < 0 || position >= getListLength(pList)) return FALSE;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    pList->currentElementCount--;
    if (position == 0) {
        pPreNode = &(pList->headerNode);
        for (int i = 0; i < getListLength(pList); i++) {
            pPreNode = pPreNode->pLink;
        }
        pPreNode->pLink = pList->headerNode.pLink;
    }
    return TRUE;
}

ListNode *getElement(List *pList, int position) {
    ListNode *pNode = NULL;
    if (pList == NULL) return NULL;
    if (position < 0 || position >= getListLength(pList)) return FALSE;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++) {
        pNode = pNode->pLink;
    }
    return pNode;
}

int getListLength(List *pList) {
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

void clearList(List *pList) {
    if (pList == NULL) return;
    while (getListLength(pList) != 0) {
        removeElement(pList, 0);
    }
}

void deleteList(List *pList) {
    if (pList == NULL) return;
    clearList(pList);
    free(pList);
}

void displayList(List *pList) {
    printf("displayList\n");
    if (pList == NULL) return;
    ListNode *pNode = NULL;
    pNode = pList->headerNode.pLink;
    for (int i = 0; i < getListLength(pList); i++) {
        pNode = getElement(pList, i);
        if (pNode != NULL) {
            printf("%d ", pNode->data);
        }
    }
    printf("first node data : %d \n", pNode->pLink->data);
}