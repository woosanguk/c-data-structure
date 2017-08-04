//
// Created by Administrator on 2017-08-03.
//

#ifndef LINKED_LIST_LINKEDLIST_H
#define LINKED_LIST_LINKEDLIST_H

#define FALSE 0
#define TRUE 1

typedef struct ListNodeType {
    int data;
    struct ListNodeType *pLink;
} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;

List *createList();

void deleteList(List *pList);

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

void clearList(List *pList);

int getListLength(List *pList);

void displayList(List *pList);

#endif //LINKED_LIST_LINKEDLIST_H
