//
// Created by sanguk on 10/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraygraph.h"

ArrayGraph *createArrayGraph(int maxVertexCount) {
    ArrayGraph *pReturn = NULL;
    int i = 0, j = 0;
    if (maxVertexCount < 1) return NULL;
    pReturn = (ArrayGraph *) malloc(sizeof(ArrayGraph));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(ArrayGraph));
    pReturn->graphType = GRAPH_UNDIRECTED;
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->pVertex = (int *) malloc(sizeof(int) * maxVertexCount);
    if (pReturn->pVertex == NULL) {
        free(pReturn);
        return NULL;
    }
    pReturn->ppAdjEdge = (int **) malloc(sizeof(int *) * maxVertexCount);
    if (pReturn->ppAdjEdge == NULL) {
        free(pReturn->pVertex);
        free(pReturn);
        return NULL;
    }
    for (i = 0; i < maxVertexCount; i++) {
        pReturn->ppAdjEdge[i] = (int *) malloc(sizeof(int) * maxVertexCount);
        if (pReturn->ppAdjEdge[i] == NULL) {
            for (j = 0; j < i - 1; j++) {
                if (pReturn->ppAdjEdge[j] != NULL) {
                    free(pReturn->ppAdjEdge[j]);
                }
            }
            free(pReturn->ppAdjEdge);
            free(pReturn->pVertex);
            free(pReturn);
        }
    }
    memset(pReturn->pVertex, NOT_USED, sizeof(int) * maxVertexCount);
    for (i = 0; i < maxVertexCount; i++) {
        memset(pReturn->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
    }
    return pReturn;
}

ArrayGraph *createArrayDirectedGraph(int maxVertexCount) {
    ArrayGraph *pReturn = NULL;
    pReturn = createArrayGraph(maxVertexCount);
    if (pReturn != NULL) {
        pReturn->graphType = GRAPH_DIRECTED;
    }
    return pReturn;
}

void deleteArrayGraph(ArrayGraph *pGraph) {
    int i = 0;
    if (pGraph == NULL) return;
    for (i = 0; i < pGraph->maxVertexCount; i++){
        free(pGraph->ppAdjEdge[i]);
    }
    free(pGraph->ppAdjEdge);
    free(pGraph->pVertex);
    free(pGraph);
}

int isEmptyAG(ArrayGraph *pGraph) {
    if (pGraph == NULL) return FAIL;
    if (pGraph->currentVertexCount == 0) return SUCCESS;
    return FAIL;
}

int addVertexAG(ArrayGraph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (vertexID > pGraph->maxVertexCount) return FAIL;
    if (pGraph->pVertex[vertexID] == USED) return FAIL;
    pGraph->pVertex[vertexID] = USED;
    pGraph->currentVertexCount++;
    return SUCCESS;
}

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID) {
    return addEdgeWithWeightAG(pGraph, fromVertexID, toVertexID, USED);
}

int addEdgeWithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FAIL) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FAIL) return FAIL;
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
    }
    return SUCCESS;
}

int checkVertexValid(ArrayGraph *pGraph, int vertexID) {
    if (pGraph == NULL) return FAIL;
    if (pGraph->pVertex[vertexID] == USED) return SUCCESS;
    return FAIL;
}

int removeVertexAG(ArrayGraph *pGraph, int vertexID) {
    int i = 0;
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, vertexID) == FAIL) return FAIL;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        removeEdgeAG(pGraph, vertexID, i);
        removeEdgeAG(pGraph, i, vertexID);
    }
    pGraph->pVertex[vertexID] = NOT_USED;
    return SUCCESS;
}

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID) {
    if (pGraph == NULL) return FAIL;
    if (checkVertexValid(pGraph, fromVertexID) == FAIL) return FAIL;
    if (checkVertexValid(pGraph, toVertexID) == FAIL) return FAIL;
    pGraph->ppAdjEdge[fromVertexID][toVertexID] = NOT_USED;
    if (pGraph->graphType == GRAPH_UNDIRECTED) {
        pGraph->ppAdjEdge[toVertexID][fromVertexID] = NOT_USED;
    }
    return SUCCESS;
}

void displayArrayGraph(ArrayGraph *pGraph) {
    int i = 0, j = 0;
    if (pGraph == NULL) return;
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        for (j = 0; j < pGraph->maxVertexCount; j++) {
            printf("%d ", pGraph->ppAdjEdge[i][j]);
        }
        printf("\n");
    }
}
