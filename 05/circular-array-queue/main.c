#include <stdio.h>
#include "arrayqueue.h"

int main() {
    Queue *pQueue = createQueue(3);
    QueueNode node = {0,};
    if (pQueue != NULL) {
        node.data = 'a';
        enqueue(pQueue, node);
        node.data = 'b';
        enqueue(pQueue, node);
        node.data = 'c';
        enqueue(pQueue, node);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        node.data = 'x';
        enqueue(pQueue, node);
        node.data = 'y';
        enqueue(pQueue, node);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);
    }
    return 0;
}