//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_TRAVERSAL_GRAPHLINKEDLIST_H
#define GRAPH_TRAVERSAL_GRAPHLINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef struct GraphVertexType {
    int vertexID;
    int weight;
} GraphVertex;

typedef struct ListNodeType {
    GraphVertex data;
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

#endif //GRAPH_TRAVERSAL_GRAPHLINKEDLIST_H
