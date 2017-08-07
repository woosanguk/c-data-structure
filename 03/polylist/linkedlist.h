//
// Created by sanguk on 07/08/2017.
//

#ifndef POLYLIST_LINKEDLIST_H
#define POLYLIST_LINKEDLIST_H

#define TRUE        1
#define FALSE       0

typedef struct ListNodeType {
    float coef;
    int degree;
    struct ListNodeType *pLink;
} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;


List *createList();

int addElement(List *pList, int position, ListNode element);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

void clearList(List *pList);

int getListLength(List *pList);

void deleteList(List *pList);

#endif //POLYLIST_LINKEDLIST_H
