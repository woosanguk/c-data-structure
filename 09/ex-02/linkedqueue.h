//
// Created by sanguk on 14/08/2017.
//

#ifndef EX_02_LINKEDQUEUE_H
#define EX_02_LINKEDQUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct QueueNodeType{
    int data;
    struct QueueNodeType *pLink;
}QueueNode;

typedef struct QueueType{
    int currentElementCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;
}Queue;

Queue *createQueue();
void deleteQueue(Queue *pQueue);
int enqueue(Queue *pQueue, QueueNode node);
QueueNode *dequeue(Queue *pQueue);
QueueNode *peek(Queue *pQueue);
int isQueueEmpty(Queue *pQueue);

#endif //EX_02_LINKEDQUEUE_H
