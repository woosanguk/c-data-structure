//
// Created by sanguk on 11/08/2017.
//

#ifndef SIM_QUEUE_SIMLINKEDQUEUE_H
#define SIM_QUEUE_SIMLINKEDQUEUE_H

#define TRUE 1
#define FALSE 0

typedef struct QueueNodeType {
    SimCustomer data;
    struct QueueNodeType *pLink;
} QueueNode;

typedef struct LinkedQueueType {
    int currentElementCount;
    QueueNode *pFrontNode;
    QueueNode *pRearNode;
} LinkedQueue;

LinkedQueue *createLinkedQueue();

int enqueueLQ(LinkedQueue *pQueue, QueueNode element);

QueueNode *dequeueLQ(LinkedQueue *pQueue);

QueueNode *peekLQ(LinkedQueue *pQueue);

void deleteLinkedQueue(LinkedQueue *pQueue);

int isLinkedQueueFull(LinkedQueue *pQueue);

int isLinkedQueueEmpty(LinkedQueue *pQueue);

#endif //SIM_QUEUE_SIMLINKEDQUEUE_H
