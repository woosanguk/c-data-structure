//
// Created by sanguk on 11/08/2017.
//

#import <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"


List *createList() {
    List *pReturn = NULL;
    pReturn = (List *) malloc(sizeof(List));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(List));
    return pReturn;
}

int addElement(List *pList, int position, ListNode node) {
    ListNode *pNewNode = NULL, *pPreNode = NULL;
    int i = 0;
    if (pList == NULL) return FALSE;
    if (position < 0 || position > pList->currentElementCount) return FALSE;
    pNewNode = (ListNode *) malloc(sizeof(ListNode));
    *pNewNode = node;

    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    return TRUE;
}

int removeElement(List *pList, int position) {
    ListNode *pDelNode = NULL, *pPreNode = NULL;
    int i = 0;
    if (pList == NULL) return FALSE;
    if (pList->currentElementCount == 0) return FALSE;
    if (position < 0 || position >= pList->currentElementCount) return FALSE;
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++) {
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    pDelNode->pLink = NULL;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

ListNode *getElement(List *pList, int position) {
    ListNode *pReturn = NULL;
    int i = 0;
    if (pList == NULL) return FALSE;
    if (pList->currentElementCount == 0) return FALSE;
    if (position < 0 || position >= pList->currentElementCount) return FALSE;
    pReturn = &(pList->headerNode);
    for (i = 0; i <= position; i++) {
        pReturn = pReturn->pLink;
    }
    return pReturn;
}

void deleteList(List *pList) {
    if (pList == NULL) return;
    while (pList->currentElementCount > 0) {
        removeElement(pList, 0);
    }
    free(pList);
}