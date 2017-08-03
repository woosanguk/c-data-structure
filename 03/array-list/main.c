#include <stdio.h>
#include "arraylist.h"
int main() {
    List *pList;
    ListNode node;

    pList = createList(5);

    if (pList){
        node.data = 100;
        addElement(pList, 0, node);
        node.data = 200;
        addElement(pList, 1, node);
        node.data = 300;
        addElement(pList, 2, node);
        node.data = 50;
        addElement(pList, 0, node);
        node.data = 25;
        addElement(pList, 0, node);
        node.data = 5;
        addElement(pList, 0, node);

        displayList(pList);

        removeElement(pList, 2);
        displayList(pList);

        removeElement(pList, 0);
        displayList(pList);

        removeElement(pList, 2);
        displayList(pList);

        clearList(pList);

        displayList(pList);

        deleteList(pList);

    }
    return 0;
}
