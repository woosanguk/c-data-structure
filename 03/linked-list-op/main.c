#include <stdio.h>
#include "linkedlist.h"
#include "linkedlistop.h"

int main() {
    List *pListA, *pListB;
    ListNode node;
    pListA = createList();
    pListB = createList();

    if (pListA != NULL && pListB != NULL){
        node.data = 10;
        addElement(pListA, 0, node);
        node.data = 8;
        addElement(pListA, 0, node);
        node.data = 6;
        addElement(pListA, 0, node);
        node.data = 4;
        addElement(pListA, 0, node);

        node.data = 15;
        addElement(pListB, 0, node);
        node.data = 13;
        addElement(pListB, 0, node);
        node.data = 11;
        addElement(pListB, 0, node);
        node.data = 9;
        addElement(pListB, 0, node);


        displayList(pListA);
        displayList(pListB);


        iterateLinkedList(pListA);
        iterateLinkedList(pListB);

        concatLinkedList(pListA, pListB);

        iterateLinkedList(pListA);
        iterateLinkedList(pListB);

        reverseLinkedList(pListA);

        iterateLinkedList(pListA);
    }

    return 0;
}