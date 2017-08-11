#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "graphtraversal.h"

int main() {

    int i = 0;
    Graph *pG1 = NULL;

    // ±◊∑°«¡ ª˝º∫
    pG1 = createGraph(8);
    if (pG1 != NULL)
    {
        for(i = 0; i < 8; i++)
        {
            addVertex(pG1, i);
        }

        addEdge(pG1, 0, 1);
        addEdge(pG1, 0, 2);
        addEdge(pG1, 1, 3);
        addEdge(pG1, 1, 4);
        addEdge(pG1, 2, 5);
        addEdge(pG1, 2, 6);
        addEdge(pG1, 3, 7);
        addEdge(pG1, 4, 5);

        printf("G1:\n");
        displayGraph(pG1);

        printf("\nBFS traversal:\n");
        traversalBFS(pG1, 0);

        deleteGraph(pG1);
    }

    return 0;
}