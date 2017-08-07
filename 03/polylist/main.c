#include <stdio.h>
#include "linkedlist.h"
#include "polylist.h"

int main() {
    List *pListA = createList(), *pListB = createList(), *pListC = NULL;

    if (pListA != NULL && pListB != NULL){
        addPolyNodeLast(pListA, 3, 5);
        addPolyNodeLast(pListA, 2, 3);
        addPolyNodeLast(pListA, 7, 1);
        addPolyNodeLast(pListA, 3, 0);


        displayPolyList(pListA);

        addPolyNodeLast(pListB, 10, 15);
        addPolyNodeLast(pListB, 9, 9);
        addPolyNodeLast(pListB, 7, 5);
        addPolyNodeLast(pListB, 6, 3);
        addPolyNodeLast(pListB, 9, 2);

        displayPolyList(pListB);

        pListC = polyAdd(pListA, pListB);

        displayPolyList(pListC);


    }

    return 0;
}