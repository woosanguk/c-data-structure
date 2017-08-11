#include <stdio.h>
#include <stdlib.h>
#include "graphlinkedlist.h"
#include "linkedgraph.h"
#include "graphtraversal.h"

int main() {
    int i = 0;
    LinkedGraph *pG1 = NULL;

    pG1 = createLinkedGraph(8);
    if (pG1 != NULL)
    {
        for(i = 0; i < 8; i++)
        {
            addVertexLG(pG1, i);
        }

        addEdgeLG(pG1, 0, 1);
        addEdgeLG(pG1, 0, 2);
        addEdgeLG(pG1, 1, 3);
        addEdgeLG(pG1, 1, 4);
        addEdgeLG(pG1, 2, 5);
        addEdgeLG(pG1, 2, 6);
        addEdgeLG(pG1, 3, 7);
        addEdgeLG(pG1, 4, 5);

        printf("G1:\n");
        displayLinkedGraph(pG1);


        printf("\nDFS traversal:\n");
        traversalDFS(pG1, 0);

        deleteLinkedGraph(pG1);
    }

    return 0;
}