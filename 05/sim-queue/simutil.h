//
// Created by sanguk on 11/08/2017.
//

#ifndef SIM_QUEUE_SIMUTIL_H
#define SIM_QUEUE_SIMUTIL_H

void insertCutomer(int arrivalTime, int processTime, LinkedQueue *pQueue);

void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue);

QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue);

QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode,
                                 int *pServiceUserCount, int *pTotalWaitTime);

void printSimCustomer(int currentTime, SimCustomer customer);

void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue);

void printReport(LinkedQueue *pWaitQueue,
                 int serviceUserCount,
                 int totalWaitTime);

#endif //SIM_QUEUE_SIMUTIL_H
