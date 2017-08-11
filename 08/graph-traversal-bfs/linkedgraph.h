//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_TRAVERSAL_BFS_LINKEDGRAPH_H
#define GRAPH_TRAVERSAL_BFS_LINKEDGRAPH_H

#define TRUE 1
#define FALSE 0

#define USED 1
#define NOT_USED 0

#define FAIL 0
#define SUCCESS 1

#define GRAPH_UNDIRECTED 1
#define GRAPH_DIRECTED 2

typedef struct GraphType {
    int maxVertexCount;
    int vertexCount;
    int edgeCount;
    int graphType;
    int *pVertex;
    List **ppEdge;
} Graph;

Graph *createGraph(int maxVertexCount);

Graph *createDirectedGraph(int maxVertexCount);

int addVertex(Graph *pGraph, int vertexID);

int checkVertexValid(Graph *pGraph, int vertexID);

int addEdge(Graph *pGraph, int fromVertexID, int toVertexID);

int addDirectedEdge(Graph *pGraph, int fromVertexID, int toVertexID, int weight);

int removeVertex(Graph *pGraph, int vertexID);

int removeEdge(Graph *pGraph, int fromVertexID, int toVertexID);

void deleteGraphNode(List *pList, int delVertexID);

int findGraphNodePosition(List *pList, int vertexID);

void displayGraph(Graph *pGraph);

void deleteGraph(Graph *pGraph);


#endif //GRAPH_TRAVERSAL_BFS_LINKEDGRAPH_H
