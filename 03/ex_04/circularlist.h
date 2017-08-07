//
// Created by sanguk on 07/08/2017.
//

#ifndef EX_04_CIRCULARLIST_H
#define EX_04_CIRCULARLIST_H

#define TRUE 1
#define FALSE 0

typedef struct ListNodeType {
    int data;
    struct ListNodeType *pLink;
} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;

List *createList();

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

int getListLength(List *pList);

void clearList(List *pList);

void deleteList(List *pList);

void displayList(List *pList);

#endif //EX_04_CIRCULARLIST_H
