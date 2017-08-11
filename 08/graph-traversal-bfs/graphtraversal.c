//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "linkedqueue.h"
#include "graphtraversal.h"

int enqueueLQForBFS(Queue *pQueue, int nodeID) {
    QueueNode node = {0,};
    node.data = nodeID;
    return enqueue(pQueue, node);
}

void traversalBFS(Graph *pGraph, int startVertexID) {
    Queue *pQueue = NULL;
    QueueNode *pQueueNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited;
    if (pGraph == NULL) return;
    if (checkVertexValid(pGraph, startVertexID) == FALSE) return;
    pVisited = (int *) malloc(sizeof(int) * pGraph->maxVertexCount);
    if (pVisited == NULL) return;
    memset(pVisited, FALSE, sizeof(int) * pGraph->maxVertexCount);
    pQueue = createQueue();
    pVisited[startVertexID] = TRUE;
    enqueueLQForBFS(pQueue, startVertexID);

    while (pQueue->currentElementCount > 0) {
        pQueueNode = dequeue(pQueue);
        printf("[%d] ", pQueueNode->data);
        pListNode = pGraph->ppEdge[pQueueNode->data]->headerNode.pLink;
        while (pListNode != NULL) {
            if (pVisited[pListNode->data.vertexID] == FALSE) {
                pVisited[pListNode->data.vertexID] = TRUE;
                enqueueLQForBFS(pQueue, pListNode->data.vertexID);
            }
            pListNode = pListNode->pLink;
        }
    }

    free(pVisited);
    deleteQueue(pQueue);
}