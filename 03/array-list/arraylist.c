//
// Created by Administrator on 2017-08-03.
//

#include "arraylist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List *createList(int maxElementCount){
    List *pList = NULL;
    if (maxElementCount < 1) return NULL;
    pList = (List *)malloc(sizeof(List));
    if (pList == NULL) return NULL;
    pList->maxElementCount = maxElementCount;
    pList->currentElementCount;
    pList->pElement = (ListNode *)malloc(sizeof(ListNode) * maxElementCount);
    if (pList->pElement == NULL) {
        free(pList);
        return NULL;
    }
    memset(pList->pElement, 0, sizeof(ListNode) * maxElementCount);
    return pList;
}

void deleteList(List *pList){
    if (pList != NULL){
        clearList(pList);
        free(pList);
    }

}

int isFull(List *pList){
    if(pList == NULL) return TRUE;
    if(getListLength(pList) == pList->maxElementCount){
        return TRUE;
    }
    return FALSE;
}

int addElement(List *pList, int position, ListNode element){
    if(pList == NULL) return FALSE;
    if (isFull(pList) == TRUE) return FALSE;
    if (position < 0 || position > pList->currentElementCount){
        return FALSE;
    }
    for (int i = getListLength(pList); i >= position; i--){
        pList->pElement[i + 1] = pList->pElement[i];
    }
    pList->pElement[position] = element;
    pList->currentElementCount++;
    return TRUE;
}

int removeElement(List *pList, int position){
    if (pList == NULL) return FALSE;
    if (position < 0 || position >= getListLength(pList)) return FALSE;
    for (int i = position + 1; i < getListLength(pList); i++){
        pList->pElement[i-1] = pList->pElement[i];
    }
    pList->currentElementCount--;

    return TRUE;
}

ListNode* getElement(List *pList, int position){
    ListNode *pNode = NULL;
    if (pList == NULL) return pNode;
    if (position < 0 || position > getListLength(pList)) return pNode;
    pNode = &(pList->pElement[position]);
    return pNode;
}

void displayList(List *pList){
    printf("displayList\n");
    ListNode *pNode;
    for (int i = 0; i < getListLength(pList); i++){
        pNode = getElement(pList, i);
        if (pNode){
            printf("%d ", pNode->data);
        }
    }
    printf("\n");

}

void clearList(List *pList){
    if (pList != NULL){
        free(pList->pElement);
    }
    pList->currentElementCount = 0;
}

int getListLength(List *pList){
    if (pList == NULL) return 0;
    return pList->currentElementCount;
}