#include "arrayqueue.h"
#include <stdio.h>

int main() {
    Queue *pQueue = NULL;
    QueueNode node = {0,};
    pQueue = createQueue(5);

    if (pQueue != NULL) {
        node.data = 'a';
        enqueue(pQueue, node);
        node.data = 'b';
        enqueue(pQueue, node);
        node.data = 'c';
        enqueue(pQueue, node);
        node.data = 'd';
        enqueue(pQueue, node);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

    }
    return 0;
}