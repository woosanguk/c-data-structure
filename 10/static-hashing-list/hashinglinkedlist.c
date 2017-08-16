//
// Created by sanguk on 16/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashingdef.h"
#include "hashinglinkedlist.h"

LinkedList *createLinkedList(){
    LinkedList *pReturn = NULL;
    pReturn = (LinkedList *)malloc(sizeof(LinkedList));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedList));
    return pReturn;
}

int addLLElement(LinkedList *pList, int position, ListNode element){
    int i = 0;
    ListNode *pNewNode = NULL, *pPreNode = NULL;
    if (pList == NULL) return FALSE;
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
    int i = 0;
    ListNode *pDelNode = NULL, *pPreNode = NULL;
    if (pList == NULL) return FALSE;
    if (getLinkedListLength(pList) == 0) return FALSE;
    pPreNode = &(pList->headerNode);
    for (i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    pDelNode->pLink = NULL;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

ListNode *getLLElement(LinkedList *pList, int position){
    int i = 0;
    ListNode *pNode = NULL;
    if (pList == NULL) return NULL;
    if (getLinkedListLength(pList) == 0) return NULL;
    pNode = &(pList->headerNode);
    for (i = 0; i <= position; i++){
        pNode = pNode->pLink;
    }
    return pNode;
}

void clearLinkedList(LinkedList *pList){
    if (pList == NULL) return;
    while(getLinkedListLength(pList) != 0){
        removeLLElement(pList, 0);
    }
}

int getLinkedListLength(LinkedList *pList){
    if (pList == FALSE) return 0;
    return pList->currentElementCount;
}

void deleteLinkedList(LinkedList *pList){
    if (pList == NULL) return;
    clearLinkedList(pList);
    free(pList);

}
