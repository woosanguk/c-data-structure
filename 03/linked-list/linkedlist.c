//
// Created by Administrator on 2017-08-03.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linkedlist.h"

List *createList(){
    List *pList = NULL;
    pList = (List*)malloc(sizeof(List));
    if (pList == NULL) return NULL;
    memset(pList, 0 , sizeof(List));
    pList->currentElementCount = 0;
    return pList;
}

void deleteList(List *pList){
    if (pList == NULL) return;
    clearList(pList);
    free(pList);
}

int addElement(List *pList, int position, ListNode node){
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getListLength(pList)){
        return FALSE;
    }
    ListNode *pNode = NULL, *pPreNode;
    pNode = (ListNode*)malloc(sizeof(ListNode));
    if (pNode == NULL) return FALSE;
    pNode->data = node.data;
    pNode->pLink = NULL;
    pPreNode = &(pList->headerNode);

    for (int i = 0; i <position; i++){
        pPreNode = pPreNode->pLink;
    }
    pNode->pLink = pPreNode->pLink;
    pPreNode->pLink = pNode;
    pList->currentElementCount++;
    return TRUE;
}

int removeElement(List *pList, int position){
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getListLength(pList)){
        return FALSE;
    }
    ListNode *pPreNode, *pDelNode;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pLink;
    }
    pDelNode = pPreNode->pLink;
    pPreNode->pLink = pDelNode->pLink;
    pDelNode->pLink = NULL;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

ListNode *getElement(List *pList, int position){
    ListNode *pNode = NULL;
    pNode = &(pList->headerNode);
    for (int i =0; i <= position; i++){
        pNode = pNode->pLink;
    }
    return pNode;
}

void clearList(List *pList){
    while (getListLength(pList) > 0){
        removeElement(pList, 0);
    }
}

int getListLength(List *pList){
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

void displayList(List *pList){
    printf("displayList\n");
    ListNode *pNode;
    for (int i =0; i < getListLength(pList); i++){
        pNode = getElement(pList, i);
        if (pNode != NULL){
            printf("%d ", pNode->data);
        }
    }
    printf("\n");
}