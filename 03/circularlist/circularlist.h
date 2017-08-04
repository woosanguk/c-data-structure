//
// Created by sanguk on 04/08/2017.
//

#ifndef CIRCULARLIST_CIRCULARLIST_H
#define CIRCULARLIST_CIRCULARLIST_H

#define FALSE 0
#define TRUE 1

typedef struct ListNodeType {
    int data;
    struct ListNodeType *pLink;
} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode *pLink;
} List;

List *createList();

void deleteList(List *pList);

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

int getListLength(List *pList);

void displayList(List *pList);

void clearList(List *pList);


#endif //CIRCULARLIST_CIRCULARLIST_H
