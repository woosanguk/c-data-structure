#include <stdio.h>
#include "linkeddeque.h"

int main() {
    DequeNode node = {0,};
    Deque *pDeque = createDeque();

    if (pDeque != NULL){
        node.data = 'a';
        insertFront(pDeque, node);
        node.data = 'b';
        insertFront(pDeque, node);

        node.data = 'x';
        insertRear(pDeque, node);

        node.data = 'y';
        insertRear(pDeque, node);

        printf("%c ", peekFront(pDeque)->data);
        printf("%c ", peekRear(pDeque)->data);

        printf("%c ", peekFront(pDeque)->data);
        printf("%c ", peekRear(pDeque)->data);

        printf("%c ", deleteFront(pDeque)->data);
        printf("%c ", deleteFront(pDeque)->data);
        printf("%c ", deleteFront(pDeque)->data);
        printf("%c ", deleteFront(pDeque)->data);

        node.data = 'a';
        insertFront(pDeque, node);
        node.data = 'b';
        insertFront(pDeque, node);

        node.data = 'x';
        insertRear(pDeque, node);

        node.data = 'y';
        insertRear(pDeque, node);

        printf("%c ", deleteRear(pDeque)->data);
        printf("%c ", deleteRear(pDeque)->data);
        printf("%c ", deleteRear(pDeque)->data);
        printf("%c ", deleteRear(pDeque)->data);


        deleteDeque(pDeque);

    }


    return 0;
}