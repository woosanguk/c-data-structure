//
// Created by sanguk on 08/08/2017.
//

#ifndef ARRAY_QUEUE_ARRAYQUEUE_H
#define ARRAY_QUEUE_ARRAYQUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct QueueNodeType {
    char data;
} QueueNode;

typedef struct QueueType {
    int currentElementCount;
    int maxElementCount;
    int front;
    int rear;
    QueueNode *pElement;
} Queue;

Queue *createQueue(int maxElementCount);

int enqueue(Queue *pQueue, QueueNode node);

QueueNode *dequeue(Queue *pQueue);

QueueNode *peek(Queue *pQueue);

void deleteQueue(Queue *pQueue);

int isQueueFull(Queue *pQueue);

int isQueueEmpty(Queue *pQueue);

#endif //ARRAY_QUEUE_ARRAYQUEUE_H
