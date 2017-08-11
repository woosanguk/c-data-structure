//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"


Graph *createGraph(int maxVertexCount) {
    int i = 0, j = 0;
    Graph *pReturn = NULL;
    if (maxVertexCount < 1) return NULL;
    pReturn = (Graph *) malloc(sizeof(Graph));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(Graph));
    pReturn->graphType = GRAPH_UNDIRECTED;
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->pVertex = (int *) malloc(sizeof(int) * maxVertexCount);
    if (pReturn->pVertex == NULL) {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);

    pReturn->ppEdge = (List **) malloc(sizeof(List *) * maxVertexCount);

    if (pReturn->ppEdge == NULL) {
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }

    for (i = 0; i < maxVertexCount; i++) {
        pReturn->ppEdge[i] = createList();
        if (pReturn->ppEdge[i] == NULL) {
            for (j = 0; j < i - 1; j++) {
                free(pReturn->ppEdge[i]);
            }
            free(pReturn->ppEdge);
            free(pReturn->pVertex);
            free(pReturn);
            return NULL;
        }
    }

    return pReturn;
}

Graph *createDirectedGraph(int maxVertexCount) {
    Graph *pReturn = createGraph(maxVertexCount);
    if (pReturn != NULL) {
        pReturn->graphType = GRAPH_DIRECTED;
    }
    return pReturn;
}

int addVertex(Graph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, vertexID) == TRUE) return FAIL;
    pGraph->pVertex[vertexID] = USED;
    pGraph->vertexCount++;
    return SUCCESS;
}

int checkVertexValid(Graph *pGraph, int vertexID) {
    if (pGraph == NULL) return FALSE;
    if (vertexID < 0 || vertexID >= pGraph->maxVertexCount) return FALSE;
    if (pGraph->pVertex[vertexID] == USED) return TRUE;
    return FALSE;
}

int addEdge(Graph *pGraph, int fromVertexID, int toVertexID) {
    return addDirectedEdge(pGraph, fromVertexID, toVertexID, USED);
}

int addElementForVertex(List *pList, int position, GraphVertex vertex) {
    ListNode node = {0,};
    node.data = vertex;
    return addElement(pList, position, node);
}

int addDirectedEdge(Graph *pGraph, int fromVertexID, int toVertexID, int weight) {
    GraphVertex toVertex = {0,};
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FALSE) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FALSE) return FAIL;
    toVertex.vertexID = toVertexID;
    toVertex.weight = weight;
    addElementForVertex(pGraph->ppEdge[fromVertexID], 0, toVertex);
    pGraph->edgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        GraphVertex fromVertex = {0,};
        fromVertex.vertexID = fromVertexID;
        fromVertex.weight = weight;
        addElementForVertex(pGraph->ppEdge[toVertexID], 0, fromVertex);
        pGraph->edgeCount++;
    }
    return SUCCESS;
}

int removeVertex(Graph *pGraph, int vertexID) {
    int i = 0;
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, vertexID) == FALSE) return FAIL;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        removeEdge(pGraph, vertexID, i);
        removeEdge(pGraph, i, vertexID);
    };
    pGraph->pVertex[vertexID] = NOT_USED;
    return SUCCESS;
}

int removeEdge(Graph *pGraph, int fromVertexID, int toVertexID) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FALSE) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FALSE) return FAIL;
    deleteGraphNode(pGraph->ppEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        deleteGraphNode(pGraph->ppEdge[toVertexID], fromVertexID);
    }
    return SUCCESS;
}

void deleteGraphNode(List *pList, int delVertexID) {
    int position = 0;
    if (pList == NULL) return;
    position = findGraphNodePosition(pList, delVertexID);
    if (position < 0) return;
    removeElement(pList, position);
}

int findGraphNodePosition(List *pList, int vertexID) {
    ListNode *pNode = NULL;
    int ret = -1, position = 0;
    if (pList == NULL) return ret;
    pNode = pList->headerNode.pLink;
    while (pNode != NULL) {
        if (pNode->data.vertexID == vertexID) {
            return position;
            break;
        }
        pNode = pNode->pLink;
        position++;
    }
    return ret;
}

void displayGraph(Graph *pGraph) {
    int i = 0, j = 0, position = 0;
    ListNode* pNode = NULL;
    if (pGraph == NULL) return;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        for (j = 0; j < pGraph->maxVertexCount; j++){
            position = findGraphNodePosition(pGraph->ppEdge[i], j);
            if (position >= 0 ){
                pNode = getElement(pGraph->ppEdge[i], position);
                printf("%d ", pNode->data.weight);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void deleteGraph(Graph *pGraph) {
    if (pGraph == NULL) return;
    for (int i = 0; i < pGraph->maxVertexCount; i++) {
        deleteList(pGraph->ppEdge[i]);
    }
    free(pGraph->ppEdge);
    free(pGraph->pVertex);
    free(pGraph);
}
