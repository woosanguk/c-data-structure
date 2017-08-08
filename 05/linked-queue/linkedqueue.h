//
// Created by sanguk on 08/08/2017.
//

#ifndef LINKED_QUEUE_LINKEDQUEUE_H
#define LINKED_QUEUE_LINKEDQUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct QueueNodeType {
    char data;
    struct QueueNodeType *pLink;
} QueueNode;

typedef struct QueueType {
    int currentQueueCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;

} Queue;

Queue *createQueue();

int enqueue(Queue *pQueue, QueueNode element);

QueueNode *dequeue(Queue *pQueue);

QueueNode *peek(Queue *pQueue);

void deleteQueue(Queue *pQueue);

int isQueueEmpty(Queue *pQueue);

#endif //LINKED_QUEUE_LINKEDQUEUE_H
