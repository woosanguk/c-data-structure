//
// Created by sanguk on 11/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "linkedstack.h"
#include "graphtraversal.h"

int pushLSForDFS(LinkedStack* pStack, int nodeID)
{
    StackNode node = {0,};
    node.data = nodeID;
    return pushLS(pStack, node);
}

void traversalDFS(LinkedGraph* pGraph, int startVertexID){
    int i = 0, vertextID = 0;
    LinkedStack *pStack = NULL;
    StackNode *pStackNode = NULL;
    ListNode *pListNode = NULL;
    int *pVisited = NULL;
    if (pGraph == NULL) return;
    pStack = createLinkedStack();
    if (pStack == NULL) return;
    pVisited = (int *)malloc(sizeof(int) * getMaxVertexCountLG(pGraph));
    if (pVisited == NULL) return;
    memset(pVisited, FALSE, sizeof(int) * getMaxVertexCountLG(pGraph));

    pVisited[startVertexID] = TRUE;
    pushLSForDFS(pStack, startVertexID);

    while(isLinkedStackEmpty(pStack) == FALSE){
        pStackNode = popLS(pStack);
        if (pStackNode == NULL) break;
        vertextID = pStackNode->data;
        printf("[%d] ", vertextID);
        pListNode = pGraph->ppAdjEdge[vertextID]->headerNode.pLink;
        while(pListNode != NULL){
            int vertexID = pListNode->data.vertexID;
            if (pVisited[vertexID] == FALSE){
                pVisited[vertexID]= TRUE;
                pushLSForDFS(pStack, vertexID);
            }
            pListNode = pListNode->pLink;
        }
    }
    printf("\n");
    free(pVisited);
    deleteLinkedStack(pStack);
}
