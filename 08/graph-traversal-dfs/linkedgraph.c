//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"


LinkedGraph *createLinkedGraph(int maxVertexCount) {
    LinkedGraph *pReturn = NULL;
    int i = 0, j = 0;
    if (maxVertexCount < 1) return NULL;
    pReturn = (LinkedGraph *) malloc(sizeof(LinkedGraph));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(LinkedGraph));
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->graphType = GRAPH_UNDIRECTED;
    pReturn->pVertex = (int *) malloc(sizeof(int) * maxVertexCount);
    if (pReturn->pVertex == NULL) {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    pReturn->ppAdjEdge = (LinkedGraph **) malloc(sizeof(LinkedGraph *) * maxVertexCount);
    if (pReturn->ppAdjEdge == NULL) {
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }
    for (i = 0; i < maxVertexCount; i++) {
        pReturn->ppAdjEdge[i] = createLinkedList();
        if (pReturn->ppAdjEdge[i] == NULL) {
            for (j = 0; j < i - 1; j++) {
                free(pReturn->ppAdjEdge[j]);
            }
            free(pReturn->ppAdjEdge);
            free(pReturn->pVertex);
            free(pReturn);
            return NULL;
        }
    }

    return pReturn;
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount) {
    LinkedGraph *pReturn = createLinkedGraph(maxVertexCount);
    pReturn->graphType = GRAPH_DIRECTED;
    return pReturn;
}

void deleteLinkedGraph(LinkedGraph *pGraph) {
    int i = 0;
    if (pGraph == NULL) return;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        deleteLinkedList(pGraph->ppAdjEdge[i]);
    }
    if (pGraph->ppAdjEdge != NULL) free(pGraph->ppAdjEdge);
    if (pGraph->pVertex != NULL) free(pGraph->pVertex);
    free(pGraph);
}

int isEmptyLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return FALSE;
    if (pGraph->currentVertexCount == 0) return TRUE;
    return FALSE;
}

int addVertexLG(LinkedGraph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, vertexID) == SUCCESS) return FAIL;
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return SUCCESS;
}

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID) {
    return addEdgeWithWeightLG(pGraph, fromVertexID, toVertexID, USED);
}

int addLLElementForVertex(LinkedList *pList, int position, GraphVertex vertex) {
    ListNode node = {0,};
    node.data = vertex;
    return addLLElement(pList, position, node);
}

int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight) {
    GraphVertex toNode = {0,};
    int position = 0;
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FAIL) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FAIL) return FAIL;
    toNode.vertexID = toVertexID;
    toNode.weight = weight;
    addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], position, toNode);
    pGraph->currentEdgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        GraphVertex fromNode = {0,};
        fromNode.vertexID = fromVertexID;
        fromNode.weight = weight;
        addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], position, fromNode);
        pGraph->currentEdgeCount++;
    }
    return SUCCESS;
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (vertexID < 0 || vertexID >= pGraph->maxVertexCount) return FAIL;
    if (pGraph->pVertex[vertexID] == USED) return SUCCESS;
    return FAIL;
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID) {
    int i = 0;
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, vertexID) == FAIL) return FAIL;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        removeEdgeLG(pGraph, vertexID, i);
        removeEdgeLG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    pGraph->currentVertexCount--;
    return SUCCESS;
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FAIL) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FAIL) return FAIL;
    deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
    if (getGraphTypeLG(pGraph) == GRAPH_UNDIRECTED) {
        deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
    }
    return SUCCESS;
}

void deleteGraphNode(LinkedList *pList, int delVertexID) {
    ListNode *pNode = NULL;
    int position = 0;
    if (pList == NULL) return;
    position = findGraphNodePosition(pList, delVertexID);
    if (position < 0) return;
    removeLLElement(pList, position);
}

int findGraphNodePosition(LinkedList *pList, int vertexID) {
    int ret = -1, position = 0;
    ListNode *pNode = NULL;
    if (pList == NULL) return ret;
    pNode = pList->headerNode.pLink;
    while (pNode != NULL) {
        if (pNode->data.vertexID == vertexID) {
            return position;
        }
        pNode = pNode->pLink;
        position++;
    }
    return ret;
}

int getEdgeCountLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return 0;
    return pGraph->currentEdgeCount++;
}

int getVertexCountLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return 0;
    return pGraph->currentVertexCount++;
}

int getMaxVertexCountLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return 0;
    return pGraph->maxVertexCount;
}

int getGraphTypeLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return 0;
    return pGraph->graphType;
}

void displayLinkedGraph(LinkedGraph *pGraph) {
    int i = 0;
    int j = 0;
    int position = 0;
    ListNode *pNode = NULL;

    if (pGraph != NULL) {
        for (i = 0; i < pGraph->maxVertexCount; i++) {
            for (j = 0; j < pGraph->maxVertexCount; j++) {
                position = findGraphNodePosition(pGraph->ppAdjEdge[i], j);

                if (position >= 0) {
                    pNode = getLLElement(pGraph->ppAdjEdge[i], position);
                    printf("%d ", pNode->data.weight);
                } else {
                    printf("0 ");
                }
            }
            printf("\n");
        }
    }
}