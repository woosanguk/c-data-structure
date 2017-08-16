//
// Created by sanguk on 16/08/2017.
//

#ifndef STATIC_HASHING_LIST_HASHINGLINKEDLIST_H
#define STATIC_HASHING_LIST_HASHINGLINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef struct ListNodeType {
    HashElement data;
    struct ListNodeType *pLink;
} ListNode;

typedef struct LinkedListType {
    int currentElementCount;
    ListNode headerNode;
} LinkedList;

LinkedList *createLinkedList();

int addLLElement(LinkedList *pList, int position, ListNode element);

int removeLLElement(LinkedList *pList, int position);

ListNode *getLLElement(LinkedList *pList, int position);

void clearLinkedList(LinkedList *pList);

int getLinkedListLength(LinkedList *pList);

void deleteLinkedList(LinkedList *pList);

#endif //STATIC_HASHING_LIST_HASHINGLINKEDLIST_H
