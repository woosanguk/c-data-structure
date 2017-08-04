//
// Created by sanguk on 04/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "doublylist.h"


List *createLink(){
    List *pList = (List*)malloc(sizeof(List));
    if (pList == NULL) return NULL;
    memset(pList, 0, sizeof(List));
    pList->currentElementCount = 0;
    pList->headerNode.pLeftLink = &(pList->headerNode);
    pList->headerNode.pRightLink = &(pList->headerNode);
    return pList;
}

int addElement(List *pList, int position, ListNode node){
    if (pList == NULL) return FALSE;
    if (position < 0 || position > getListLength(pList)) return FALSE;
    ListNode *pNewNode, *pPreNode;
    pNewNode = (ListNode *)malloc(sizeof(ListNode));
    if (pNewNode == NULL) return FALSE;
    *pNewNode = node;

    pPreNode = &(pList->headerNode);
    for (int i = 0 ; i < position; i++){
        pPreNode = pPreNode->pRightLink;
    }

    pNewNode->pRightLink = pPreNode->pRightLink;
    pNewNode->pLeftLink = pPreNode;
    pPreNode->pRightLink->pLeftLink = pNewNode;
    pPreNode->pRightLink = pNewNode;

    pList->currentElementCount++;
    return TRUE;
}

int removeElement(List *pList, int position){
    if (pList == NULL) return FALSE;
    if (position < 0 || position >= getListLength(pList)) return FALSE;
    ListNode *pPreNode, *pDelNode;
    pPreNode = &(pList->headerNode);
    for (int i = 0; i < position; i++){
        pPreNode = pPreNode->pRightLink;
    }
    pDelNode = pPreNode->pRightLink;
    pPreNode->pRightLink = pDelNode->pRightLink;
    pDelNode->pLeftLink = pPreNode;
    free(pDelNode);
    pList->currentElementCount--;
    return TRUE;
}

ListNode *getElement(List *pList, int position){
    if (pList == NULL) return FALSE;
    if (position < 0 || position >= getListLength(pList)) return FALSE;
    ListNode *pNode = NULL;
    pNode = &(pList->headerNode);
    for (int i = 0; i <= position; i++){
        pNode = pNode->pRightLink;
    }
    return pNode;
}

int getListLength(List *pList){
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}

void displayList(List *pList){
    printf("displayList\n");
    if (pList == NULL) return;
    ListNode *pNode;
    for (int i = 0; i < getListLength(pList); i++){
        pNode = getElement(pList, i);
        if (pNode != NULL){
            printf("%d ", pNode->data);
        }
    }
    printf("\n");
}

void clearList(List *pList){
    if(pList == NULL) return;
    while(getListLength(pList) != 0){
        removeElement(pList, 0);
    }

}

void deleteList(List *pList){
    if(pList == NULL)return;
    clearList(pList);
    free(pList);
}
