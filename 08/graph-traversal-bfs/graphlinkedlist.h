//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_TRAVERSAL_BFS_GRAPHLINKEDLIST_H
#define GRAPH_TRAVERSAL_BFS_GRAPHLINKEDLIST_H

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

typedef struct ListType {
    int currentElementCount;
    ListNode headerNode;
} List;

List *createList();

int addElement(List *pList, int position, ListNode node);

int removeElement(List *pList, int position);

ListNode *getElement(List *pList, int position);

void deleteList(List *pList);

#endif //GRAPH_TRAVERSAL_BFS_GRAPHLINKEDLIST_H
