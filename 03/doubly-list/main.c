#include <stdio.h>
#include "doublylist.h"

int main() {
    List *pList = createLink();
    ListNode node;
    if (pList != NULL) {
        node.data = 100;
        addElement(pList, 0, node);
        displayList(pList);

        node.data = 200;
        addElement(pList, 1, node);

        node.data = 300;
        addElement(pList, 2, node);

        node.data = 400;
        addElement(pList, 3, node);

        node.data = 500;
        addElement(pList, 4, node);

        node.data = 50;
        addElement(pList, 0, node);

        node.data = 150;
        addElement(pList, 2, node);

        displayList(pList);

        removeElement(pList, 0);

        displayList(pList);

        removeElement(pList, 5);

        displayList(pList);

        removeElement(pList, 3);

        displayList(pList);

        clearList(pList);

        displayList(pList);

        deleteList(pList);
    }
    return 0;
}