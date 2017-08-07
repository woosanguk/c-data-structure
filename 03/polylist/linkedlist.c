//
// Created by sanguk on 07/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"


List *createList() {
    List *pList = (List *) malloc(sizeof(List));
    if (pList == NULL) return NULL;
    memset(pList, 0, sizeof(List));
    return pList;
}

int addElement(List *pList, int position, ListNode element){
    if (pList == NULL) return FALSE;
    if (position  < 0 || position > getListLength(pList)) return FALSE;
    ListNode *pPreNode = NULL;
    ListNode *pNewNode = (ListNode *)malloc(sizeof(ListNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
}

int removeElement(List *pList, int position){
    if (pList == NULL) return FALSE;
    if (position  < 0 || position >= getListLength(pList)) return FALSE;
    ListNode *pPreNode = NULL, *pDelNode;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    free(pDelNode);
    pList->currentElementCount--;
}

ListNode *getElement(List *pList, int position){
    if (pList == NULL) return FALSE;
    if (position  < 0 || position >= getListLength(pList)) return FALSE;
    ListNode *pNode = NULL;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++){
        pNode = pNode->pLink;
    }
    return pNode;
}

void clearList(List *pList){
    if (pList == NULL) return;
    while(getListLength(pList) != 0){
        removeElement(pList, 0);
    }
}

int getListLength(List *pList){
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

void deleteList(List *pList){
    if (pList == NULL) return;
    clearList(pList);
    free(pList);
}