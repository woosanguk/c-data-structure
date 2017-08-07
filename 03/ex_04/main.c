#include <stdio.h>
#include "circularlist.h"

int main() {
    List *pList = createList();
    ListNode node;
    if (pList != NULL){
        node.data = 100;
        addElement(pList, 0, node);
        node.data = 50;
        addElement(pList, 0, node);
        node.data = 30;
        addElement(pList, 0, node);
        node.data = 10;
        addElement(pList, 0, node);
        displayList(pList);

        node.data = 35;
        addElement(pList, 2, node);
        displayList(pList);

        node.data = 200;
        addElement(pList, 5, node);
        displayList(pList);

        node.data = 5;
        addElement(pList, 0, node);
        displayList(pList);

        removeElement(pList, 3);
        displayList(pList);

        removeElement(pList, 5);
        displayList(pList);

        removeElement(pList, 0);
        displayList(pList);
    }
    return 0;
}