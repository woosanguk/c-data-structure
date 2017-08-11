//
// Created by sanguk on 11/08/2017.
//

#import <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"


void insertCutomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue) {
    SimCustomer simCustomer = {0,};
    QueueNode node = {0,};
    if (pQueue == NULL) return;
    simCustomer.status = arrival;
    simCustomer.arrivalTime = arrivalTime;
    simCustomer.serviceTime = serviceTime;
    simCustomer.endTime = 0;
    simCustomer.startTime = 0;
    node.data = simCustomer;
    enqueueLQ(pQueue, node);
}

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue) {
    QueueNode *pNode = NULL;
    int isEmpty = 0;
    if (pArrivalQueue == NULL || pWaitQueue == NULL) return;
    isEmpty = isLinkedQueueEmpty(pArrivalQueue);
    while (isEmpty == FALSE) {
        pNode = peekLQ(pArrivalQueue);
        if (pNode->data.arrivalTime == currentTime) {
            pNode = dequeueLQ(pArrivalQueue);
            enqueueLQ(pWaitQueue, *pNode);
            printSimCustomer(currentTime, pNode->data);
            free(pNode);
        } else {
            break;
        }
        isEmpty = isLinkedQueueEmpty(pArrivalQueue);
    }
}

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue) {
    QueueNode *pNode = NULL;
    if (pWaitQueue == NULL) return NULL;
    if (isLinkedQueueEmpty(pWaitQueue) == TRUE) return NULL;
    pNode = dequeueLQ(pWaitQueue);
    if (pNode->data.status == arrival) {
        pNode->data.status = start;
        pNode->data.startTime = currentTime;
        printSimCustomer(currentTime, pNode->data);
    }
    return pNode;
}

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime) {
    int endTime = 0;
    int waitTime = 0;
    QueueNode *pReturn = NULL;

    if (pServiceNode == NULL || pServiceUserCount == NULL
        || pTotalWaitTime == NULL) {
        return NULL;
    }

    endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
    if (endTime <= currentTime) {
        waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;
        (*pServiceUserCount)++;
        (*pTotalWaitTime) += waitTime;

        pServiceNode->data.status = end;
        pServiceNode->data.endTime = currentTime;
        printSimCustomer(currentTime, pServiceNode->data);

        free(pServiceNode);
        pReturn = NULL;
    } else {
        pReturn = pServiceNode;
    }

    return pReturn;

}

void printSimCustomer(int currentTime, SimCustomer customer) {
    printf("[%d],", currentTime);

    switch (customer.status) {
        case arrival:
            printf("도착\n");
            break;
        case start:
            printf("시작 ");
            printf("arrivalTime : %d‚ waitTime : %d\n", customer.arrivalTime,
                   (customer.startTime - customer.arrivalTime));
            break;
        case end:
            printf("종료 ");
            printf("arrivalTime : %d, startTime : %d, waitTime : %d, totalTime : %d\n",
                   customer.arrivalTime, customer.startTime,
                   customer.startTime - customer.arrivalTime,
                   customer.endTime - customer.startTime);
            break;
    }
}

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue) {
    printf("[%d],WaitQueueStatus: %d\n",
           currentTime,
           pWaitQueue->currentElementCount);
}

void printReport(LinkedQueue *pWaitQueue,
                 int serviceUserCount,
                 int totalWaitTime) {
    printf("REPORT\n");
    printf("serviceUserCount : %d\n", serviceUserCount);
    if (serviceUserCount > 0) {
        printf("Avg WaitTime : %f\n",
               ((float) totalWaitTime / (float) serviceUserCount));
    }
    printf("WaitQueueStatus : %d\n",
           pWaitQueue->currentElementCount);
}