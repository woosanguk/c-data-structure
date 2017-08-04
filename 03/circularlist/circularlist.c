//
// Created by sanguk on 04/08/2017.
//

#include "circularlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


List *createList() {
    List *pList = NULL;
    pList = (List *) malloc(sizeof(List));
    if (pList == NULL) return NULL;
    memset(pList, 0, sizeof(List));
    pList->currentElementCount = 0;
    pList->pLink = NULL;
    return pList;
}

void deleteList(List *pList) {
    if (pList == NULL) return;
    clearList(pList);
    free(pList);
}

int addElement(List *pList, int position, ListNode node) {
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getListLength(pList)) return FALSE;
    ListNode *pNewNode = NULL, *pPreNode = NULL, *pLastNode;
    pNewNode = (ListNode *) malloc(sizeof(ListNode));
    if (pNewNode == NULL) return FALSE;

    *pNewNode = node;
    pNewNode->pLink = NULL;

    if (position == 0) {
        if (getListLength(pList) == 0) {
            pList->pLink = pNewNode;
            pNewNode->pLink = pNewNode;
        } else {
            pLastNode = pList->pLink;
            while (pLastNode->pLink != pList->pLink) {
                pLastNode = pLastNode->pLink;
            }
            pList->pLink = pNewNode;
            pNewNode->pLink = pLastNode->pLink;
            pLastNode->pLink = pNewNode;
        }
    } else {
        pPreNode = pList->pLink;
        for (int i = 0; i < position - 1; i++) {
            pPreNode = pPreNode->pLink;
        }
        pNewNode->pLink = pPreNode->pLink;
        pPreNode->pLink = pNewNode;
    }
    pList->currentElementCount++;

    return TRUE;
}

int removeElement(List *pList, int position) {
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getListLength(pList)) return FALSE;
    ListNode *pDelNode = NULL;
    if (position == 0) {
        pDelNode = pList->pLink;
        if (getListLength(pList) == 1) {
            free(pDelNode);
            pList->pLink = NULL;
        } else {
            ListNode *pLast = pList->pLink;
            while (pLast->pLink != pList->pLink) {
                pLast = pLast->pLink;
            }
            pLast->pLink = pDelNode->pLink;
            pList->pLink = pDelNode->pLink;
            free(pDelNode);
        }
    } else {
        ListNode *pPreNode = pList->pLink;
        for (int i = 0; i < position - 1; i++) {
            pPreNode = pPreNode->pLink;
        }
        pDelNode = pPreNode->pLink;
        pPreNode->pLink = pDelNode->pLink;
        free(pDelNode);
    }
    pList->currentElementCount--;

    return TRUE;
}

ListNode *getElement(List *pList, int position) {
    ListNode *pNode;
    if (pList == NULL) return NULL;
    if (position < 0 || position > getListLength(pList)) return NULL;
    pNode = pList->pLink;
    for (int i = 0; i < position; i++) {
        pNode = pNode->pLink;
    }
    return pNode;
}

int getListLength(List *pList) {
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

void displayList(List *pList) {
    printf("displayList\n");
    ListNode *pNode;
    for (int i = 0; i < getListLength(pList); i++) {
        pNode = getElement(pList, i);
        if (pNode != NULL) {
            printf("%d ", pNode->data);
        }
    }
    printf(", first node data : %d ", pNode->pLink->data);
    printf("\n");
}

void clearList(List *pList) {
    if (pList == NULL) return;
    while (getListLength(pList) != 0) {
        removeElement(pList, 0);
    }
}