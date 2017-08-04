//
// Created by sanguk on 04/08/2017.
//

#ifndef DOUBLY_LIST_DOUBLYLIST_H
#define DOUBLY_LIST_DOUBLYLIST_H

#define FALSE 0
#define TRUE 1

typedef struct ListNodeType {
    int data;
    struct ListNodeType *pRightLink;
    struct ListNodeType *pLeftLink;

} ListNode;

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;

List *createLink();

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

int getListLength(List *pList);

void displayList(List *pList);

void clearList(List *pList);

void deleteList(List *pList);


#endif //DOUBLY_LIST_DOUBLYLIST_H
