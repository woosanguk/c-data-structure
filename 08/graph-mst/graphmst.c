//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedstack.h"
#include "linkedgraph.h"
#include "grapharrayheap.h"
#include "graphmst.h"


Graph *mstKruskal(Graph *pGraph) {
    Graph *pReturn = NULL;
    int i = 0, maxNodeCount = 0, currentNodeCount = 0, edgeCount = 0, isCycle = 0;
    ArrayMinHeap *pMinHeap = NULL;
    HeapNode *pHeapNode = NULL;
    if (pGraph == NULL) return NULL;

    maxNodeCount = pGraph->maxVertexCount;
    currentNodeCount = pGraph->currentVertexCount;
    edgeCount = pGraph->currentEdgeCount;
    pReturn = createGraph(maxNodeCount);
    if (pReturn == NULL) return NULL;
    pMinHeap = orderEdges(pGraph);
    if (pMinHeap == NULL) return NULL;
    for (i = 0; i < edgeCount; i++) {
        pHeapNode = deleteMinHeapAH(pMinHeap);
        if (pHeapNode != NULL) {
            isCycle = checkCycle(pReturn, pHeapNode->fromVertexID,
                                 pHeapNode->toVertexID);
            if (isCycle == FALSE) {
                if (pReturn->pVertex[pHeapNode->fromVertexID] != USED) {
                    addVertex(pReturn, pHeapNode->fromVertexID);
                }
                if (pReturn->pVertex[pHeapNode->toVertexID] != USED) {
                    addVertex(pReturn, pHeapNode->toVertexID);
                }
                addEdgeWithWeight(pReturn, pHeapNode->fromVertexID,
                                    pHeapNode->toVertexID, pHeapNode->key);
                printf("[%d], : (%d,%d)->%d\n",
                       i, pHeapNode->fromVertexID, pHeapNode->toVertexID,
                       pHeapNode->key);
            }
            free(pHeapNode);

            if (pReturn->currentVertexCount == currentNodeCount) {
                break;
            }
        }
    }
    return pReturn;
}

ArrayMinHeap *orderEdges(Graph *pGraph) {
    int i = 0;
    int edgeCount = 0;
    ArrayMinHeap *pReturn = NULL;
    ListNode *pListNode = NULL;
    List *pEdgeList = NULL;
    if (pGraph == NULL) return NULL;
    edgeCount = pGraph->currentEdgeCount;
    pReturn = createArrayMinHeap(edgeCount);
    for (i = 0; i < pGraph->maxVertexCount; i++) {
        if (checkVertexValid(pGraph, i) == TRUE) {
            pEdgeList = pGraph->ppEdge[i];
            pListNode = pEdgeList->headerNode.pLink;
            while (pListNode != NULL) {
                int vertexID = pListNode->data.vertexID;
                int weight = pListNode->data.weight;
                if (pGraph->graphType == GRAPH_DIRECTED || (pGraph->graphType == GRAPH_UNDIRECTED && i < vertexID)) {
                    HeapNode heapNode = {0,};
                    heapNode.fromVertexID = i;
                    heapNode.toVertexID = vertexID;
                    heapNode.key = weight;
                    insertMinHeapAH(pReturn, heapNode);
                }
                pListNode = pListNode->pLink;
            }
        }
    }
    return pReturn;
}

int pushLSForDFS(Stack* pStack, int nodeID)
{
    StackNode node = {0,};
    node.data = nodeID;
    return push(pStack, node);
}

int checkCycle(Graph *pGraph, int fromVertexID, int toVertexID) {
    int pReturn = FALSE;

    int i = 0;
    int vertextID = 0;
    Stack* pStack = NULL;
    StackNode* pStackNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited = NULL;

    if (pGraph == NULL) {
        return pReturn;
    }

    pStack = createStack();
    if (pStack == NULL) {
        return pReturn;
    }

    pVisited = (int*) malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL) {
        printf("Error, malloc() in traversalDFS()\n");
        deleteStack(pStack);
        return pReturn;
    }

    for(i = 0; i < pGraph->maxVertexCount; i++) {
        pVisited[i] = FALSE;
    }

    pVisited[fromVertexID] = TRUE;
    pushLSForDFS(pStack, fromVertexID);

    while(isStackEmpty(pStack) == FALSE) {
        pStackNode = pop(pStack);
        if (pStackNode != NULL) {
            vertextID = pStackNode->data;
            if (vertextID == toVertexID) {
                printf("(%d,%d)-������ ���ΰ� �����մϴ�.\n",
                       fromVertexID, toVertexID);
                pReturn = TRUE;
                break;
            }

            pListNode = pGraph->ppEdge[vertextID]->headerNode.pLink;
            while(pListNode != NULL) {
                int vertexID = pListNode->data.vertexID;
                if (pVisited[vertexID] == FALSE) {
                    pVisited[vertexID] = TRUE;
                    pushLSForDFS(pStack, vertexID);
                }

                pListNode = pListNode->pLink;
            }
        }
    }

    free(pVisited);
    deleteStack(pStack);

    return pReturn;
}