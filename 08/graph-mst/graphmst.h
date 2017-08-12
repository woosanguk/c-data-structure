//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_MST_GRAPHMST_H
#define GRAPH_MST_GRAPHMST_H

Graph *mstKruskal(Graph* pGraph);

ArrayMinHeap *orderEdges(Graph* pGraph);

int checkCycle(Graph* pGraph, int fromVertexID, int toVertexID);

#endif //GRAPH_MST_GRAPHMST_H
