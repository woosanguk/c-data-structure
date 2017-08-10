//
// Created by sanguk on 10/08/2017.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"

LinkedGraph *createLinkedGraph(int maxVertexCount) {
    LinkedGraph *pResult = NULL;
    int i = 0, j = 0;
    pResult = (LinkedGraph *) malloc(sizeof(LinkedGraph));
    if (pResult == NULL) return NULL;
    memset(pResult, 0, sizeof(LinkedGraph));
    pResult->maxVertexCount = maxVertexCount;
    pResult->graphType = GRAPH_UNDIRECTED;
    pResult->pVertex = (int *) malloc(sizeof(int) * maxVertexCount);
    if (pResult->pVertex == NULL) {
        free(pResult);
        return NULL;
    }
    memset(pResult->pVertex, NOT_USED, maxVertexCount);
    pResult->ppAdjEdge = (LinkedList **) malloc(sizeof(LinkedList *) * maxVertexCount);
    if (pResult->ppAdjEdge == NULL) {
        free(pResult->pVertex);
        free(pResult);
        return NULL;
    }
    for (i = 0; i < maxVertexCount; i++) {
        pResult->ppAdjEdge[i] = createLinkedList();
        if (pResult->ppAdjEdge[i] == NULL) {
            for (j = 0; j < i - 1; j++) {
                deleteLinkedList(pResult->ppAdjEdge[j]);
            }
            free(pResult->ppAdjEdge);
            free(pResult->pVertex);
            free(pResult);
        }
    }
    return pResult;
}

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount) {
    LinkedGraph *pResult = createLinkedGraph(maxVertexCount);
    if (pResult != NULL) {
        pResult->graphType = GRAPH_DIRECTED;
    }
    return pResult;
}

int isEmptyLG(LinkedGraph *pGraph) {
    return FALSE;
}

int addVertexLG(LinkedGraph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (vertexID >= pGraph->maxVertexCount) return FAIL;
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
    if (pGraph == NULL) return FAIL;
    GraphVertex toNode = {0,};
    if (checkVertexValid(pGraph, fromVertexID) == FAIL) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FAIL) return FAIL;
    toNode.vertexID = toVertexID;
    toNode.weight = weight;
    addLLElementForVertex(pGraph->ppAdjEdge[fromVertexID], 0, toNode);
    pGraph->currentEdgeCount++;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        GraphVertex fromNode = {0,};
        fromNode.vertexID = fromVertexID;
        fromNode.weight = weight;
        addLLElementForVertex(pGraph->ppAdjEdge[toVertexID], 0, fromNode);
        pGraph->currentEdgeCount++;
    }
    return SUCCESS;
}

int checkVertexValid(LinkedGraph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (pGraph->pVertex[vertexID] == USED) return SUCCESS;
    return FAIL;
}

int removeVertexLG(LinkedGraph *pGraph, int vertexID) {
    int i = 0;
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, vertexID) == FAIL) return FAIL;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        removeEdgeLG(pGraph, i, vertexID);
        removeEdgeLG(pGraph, vertexID, i);
    }
    pGraph->pVertex[vertexID] == NOT_USED;
    return SUCCESS;
}

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FAIL) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FAIL) return FAIL;
    deleteGraphNode(pGraph->ppAdjEdge[fromVertexID], toVertexID);
    if (pGraph->graphType == GRAPH_DIRECTED) {
        deleteGraphNode(pGraph->ppAdjEdge[toVertexID], fromVertexID);
    }
    return SUCCESS;
}

void deleteGraphNode(LinkedList *pList, int delVertexID) {
    int position = 0;
    position = findGraphNodePosition(pList, delVertexID);
    if (position >= 0) {
        removeLLElement(pList, position);
    }
}

int findGraphNodePosition(LinkedList *pList, int vertexID) {
    int position = 0;
    ListNode *pNode = NULL;
    pNode = pList->headerNode.pLink;
    while (pNode != NULL) {
        if (pNode->data.vertexID == vertexID) {
            return position;
        }
        pNode = pNode->pLink;
        position++;
    }
    return -1;
}

int getEdgeCountLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return 0;
    return pGraph->currentEdgeCount;
}

int getVertexCountLG(LinkedGraph *pGraph) {
    if (pGraph == NULL) return 0;
    return pGraph->currentVertexCount;
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

void deleteLinkedGraph(LinkedGraph *pGraph) {
    int i = 0;

    if (pGraph != NULL) {
        for (i = 0; i < pGraph->maxVertexCount; i++) {
            deleteLinkedList(pGraph->ppAdjEdge[i]);
        }
        if (pGraph->ppAdjEdge != NULL) free(pGraph->ppAdjEdge);
        if (pGraph->pVertex != NULL) free(pGraph->pVertex);
        free(pGraph);
    }
}