//
// Created by sanguk on 11/08/2017.
//

#ifndef GRAPH_TRAVERSAL_BFS_LINKEDQUEUE_H
#define GRAPH_TRAVERSAL_BFS_LINKEDQUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct QueueNodeType {
    int data;
    struct QueueNodeType *pLink;
} QueueNode;

typedef struct QueueType {
    int currentElementCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;
} Queue;

Queue *createQueue();

int enqueue(Queue *pQueue, QueueNode node);

QueueNode *dequeue(Queue *pQueue);

QueueNode *peek(Queue *pQueue);

void deleteQueue(Queue *pQueue);


#endif //GRAPH_TRAVERSAL_BFS_LINKEDQUEUE_H
