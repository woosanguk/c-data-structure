//
// Created by sanguk on 10/08/2017.
//

#ifndef ARRAY_GRAPH_ARRAYGRAPH_H
#define ARRAY_GRAPH_ARRAYGRAPH_H

typedef struct ArrayGraphType {
    int maxVertexCount;
    int currentVertexCount;
    int graphType;
    int **ppAdjEdge;
    int *pVertex;
} ArrayGraph;

ArrayGraph *createArrayGraph(int maxVertexCount);

ArrayGraph *createArrayDirectedGraph(int maxVertexCount);

void deleteArrayGraph(ArrayGraph *pGraph);

int isEmptyAG(ArrayGraph *pGraph);

int addVertexAG(ArrayGraph *pGraph, int vertexID);

int addEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);

int addEdgeWithWeightAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(ArrayGraph *pGraph, int vertexID);

int removeVertexAG(ArrayGraph *pGraph, int vertexID);

int removeEdgeAG(ArrayGraph *pGraph, int fromVertexID, int toVertexID);

void displayArrayGraph(ArrayGraph *pGraph);

#endif //ARRAY_GRAPH_ARRAYGRAPH_H

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED 1
#define NOT_USED 0

#define SUCCESS 1
#define FAIL 0

#define TRUE 1
#define FALSE 0

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2
#endif