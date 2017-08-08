#include <stdio.h>
#include "linkedqueue.h"

int main() {
    Queue *pQueue = createQueue();
    QueueNode node = {0,};
    if (pQueue != NULL) {
        node.data = 'a';
        enqueue(pQueue, node);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        node.data = 'a';
        enqueue(pQueue, node);
        node.data = 'b';
        enqueue(pQueue, node);
        node.data = 'c';
        enqueue(pQueue, node);
        node.data = 'd';
        enqueue(pQueue, node);
        node.data = 'e';
        enqueue(pQueue, node);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);

        printf("%c ", peek(pQueue)->data);
        printf("%c ", dequeue(pQueue)->data);
    }
    return 0;
}