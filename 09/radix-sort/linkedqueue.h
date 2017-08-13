//
// Created by Administrator on 2017-08-13.
//

#ifndef RADIX_SORT_LINKEDQUEUE_H
#define RADIX_SORT_LINKEDQUEUE_H

#define FALSE 0
#define TRUE 1

typedef struct QueueNodeType {
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



#endif //RADIX_SORT_LINKEDQUEUE_H
