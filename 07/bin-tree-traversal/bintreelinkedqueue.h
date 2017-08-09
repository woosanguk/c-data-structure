//
// Created by sanguk on 09/08/2017.
//

#ifndef BIN_TREE_TRAVERSAL_BINTREELINKEDQUEUE_H
#define BIN_TREE_TRAVERSAL_BINTREELINKEDQUEUE_H


typedef struct QueueNodeType {
    BinTreeNode *data;
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


#endif //BIN_TREE_TRAVERSAL_BINTREELINKEDQUEUE_H

#ifndef _COMMON_QUEUE_DEF_
#define _COMMON_QUEUE_DEF_

#define TRUE        1
#define FALSE        0

#endif


