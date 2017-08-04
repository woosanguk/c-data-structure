#include <stdio.h>
#include "circularlist.h"


int main() {
    List *pList = createList();
    ListNode node;
    if (pList!=NULL){
        node.data = 5;
        addElement(pList, 0, node);
        displayList(pList);

        removeElement(pList, 0);

        node.data = 3;
        addElement(pList, 1, node);

        node.data = 7;
        addElement(pList, 0, node);

        node.data = 9;
        addElement(pList, 0, node);

        node.data = 11;
        addElement(pList, 0, node);

        node.data = 13;
        addElement(pList, 0, node);

        displayList(pList);

        node.data = 1;
        addElement(pList, 6, node);

        node.data = 15;
        addElement(pList, 0, node);

        displayList(pList);

        removeElement(pList, 0);

        displayList(pList);

        removeElement(pList, 3);

        displayList(pList);

        clearList(pList);

        displayList(pList);

        deleteList(pList);
    }
    return 0;
}