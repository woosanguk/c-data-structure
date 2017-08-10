//
// Created by sanguk on 10/08/2017.
//

#ifndef LINKED_GRAPH_LINKEDGRAPH_H
#define LINKED_GRAPH_LINKEDGRAPH_H

typedef struct LinkedGraphType {
    int maxVertexCount;
    int currentVertexCount;
    int currentEdgeCount;
    int graphType;
    LinkedList **ppAdjEdge;
    int *pVertex;
} LinkedGraph;

LinkedGraph *createLinkedGraph(int maxVertexCount);

LinkedGraph *createLinkedDirectedGraph(int maxVertexCount);

void deleteLinkedGraph(LinkedGraph *pGraph);

int isEmptyLG(LinkedGraph *pGraph);

int addVertexLG(LinkedGraph *pGraph, int vertexID);

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

int addEdgeWithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(LinkedGraph *pGraph, int vertexID);

int removeVertexLG(LinkedGraph *pGraph, int vertexID);

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

void deleteGraphNode(LinkedList *pList, int delVertexID);

int findGraphNodePosition(LinkedList *pList, int vertexID);

int getEdgeCountLG(LinkedGraph *pGraph);

int getVertexCountLG(LinkedGraph *pGraph);

int getMaxVertexCountLG(LinkedGraph *pGraph);

int getGraphTypeLG(LinkedGraph *pGraph);

void displayLinkedGraph(LinkedGraph *pGraph);

#endif //LINKED_GRAPH_LINKEDGRAPH_H

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define TRUE 1
#define FALSE 0

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

#endif
