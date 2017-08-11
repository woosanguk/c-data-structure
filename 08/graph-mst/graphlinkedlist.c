//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"

List *createList() {
    List *pResult = NULL;
    pResult = (List *) malloc(sizeof(List));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(List));
    return pResult;
}

int addElement(List *pList, int position, ListNode node) {
    int i = 0;
    ListNode *pNewNode = NULL, *pPreNode = NULL;
    if (pList == NULL) return FALSE;
    if (position < 0 || position > pList->currentElementCount) return FALSE;
    pNewNode = (ListNode *) malloc(sizeof(ListNode));
    if (pNewNode == NULL) return FALSE;
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
    int i = 0;
    ListNode *pDelNode = NULL, *pPreNode = NULL;
    if (pList == NULL) return FALSE;
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
    int i = 0;
    ListNode *pNode = NULL;
    if (pList == NULL) return NULL;
    if (position < 0 || position >= pList->currentElementCount) return NULL;
    pNode = &(pList->headerNode);
    for (i = 0; i <= position; i++) {
        pNode = pNode->pLink;
    }
    return pNode;
}

int isListEmpty(List *pList) {
    if (pList == NULL) return FALSE;
    if (pList->currentElementCount == 0) return TRUE;
    return FALSE;
}

void deleteList(List *pList) {
    if (pList == NULL) return;
    while (isListEmpty(pList) == FALSE) {
        removeElement(pList, 0);
    }
    free(pList);
}