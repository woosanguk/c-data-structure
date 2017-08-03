//
// Created by Administrator on 2017-08-03.
//

#ifndef ARRAY_LIST_ARRAYLIST_H
#define ARRAY_LIST_ARRAYLIST_H

#define TRUE 1
#define FALSE 0

typedef struct ListNodeType {
    int data;
} ListNode;

typedef struct ListType {
    int maxElementCount;
    int currentElementCount;
    ListNode *pElement;
} List;

List *createList(int maxElementCount);

void deleteList(List *pList);

int isFull(List *pList);

int addElement(List *pList, int position, ListNode element);

int removeElement(List *pList, int position);

ListNode* getElement(List *pList, int position);

void displayList(List *pList);

void clearList(List *pList);

int getListLength(List *pList);

#endif //ARRAY_LIST_ARRAYLIST_H
