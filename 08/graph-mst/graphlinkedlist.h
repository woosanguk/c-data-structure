//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_MST_GRAPHLINKEDLIST_H
#define GRAPH_MST_GRAPHLINKEDLIST_H

#define TRUE 1
#define FALSE 0

typedef struct GraphNodeType {
    int vertexID;
    int weight;
} GraphNode;

typedef struct ListNodeType {
    GraphNode data;
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

int isListEmpty(List *pList);

void deleteList(List *pList);

#endif //GRAPH_MST_GRAPHLINKEDLIST_H
