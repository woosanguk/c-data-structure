//
// Created by sanguk on 10/08/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"

LinkedList *createLinkedList(){
    LinkedList *pResult = NULL;
    pResult = (LinkedList *)malloc(sizeof(LinkedList));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(LinkedList));
    return pResult;
}

int addLLElement(LinkedList *pList, int position, ListNode element){
    ListNode *pNewNode = NULL, *pPreNode = NULL;
    int i = 0;
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getLinkedListLength(pList)) return FALSE;
    pNewNode = (ListNode *)malloc(sizeof(ListNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = element;
    pNewNode->pLink = NULL;
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pNewNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNewNode;
    pList->currentElementCount++;
    return TRUE;
}

int removeLLElement(LinkedList *pList, int position){
    ListNode *pDelNode = NULL, *pPreNode = NULL;
    int i = 0;
    if (pList == NULL) return FALSE;
    if (position < 0 || position >= getLinkedListLength(pList)) return FALSE;
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

ListNode *getLLElement(LinkedList *pList, int position){
    ListNode *pNode = NULL;
    int i = 0;
    if (pList == NULL) return FALSE;
    if (position < 0 || position >= getLinkedListLength(pList)) return FALSE;
    pNode = &(pList->headerNode);
    for (i = 0; i <= position; i++){
        pNode = pNode->pLink;
    }
    return pNode;
}

int getLinkedListLength(LinkedList *pList){
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

void clearLinkedList(LinkedList *pList){
    if (pList == NULL) return;
    while (getLinkedListLength(pList) != 0){
        removeLLElement(pList, 0);
    }
    return;
}

void deleteLinkedList(LinkedList *pList){
    if (pList == NULL) return;
    clearLinkedList(pList);
    free(pList);
}