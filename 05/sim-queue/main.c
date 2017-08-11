#include <stdio.h>
#include <stdlib.h>
#include "simdef.h"
#include "simlinkedqueue.h"
#include "simutil.h"

int main() {

    int currentTime = 0;
    int endTime = 10;
    int serviceUserCount = 0;
    int totalWaitTime = 0;

    LinkedQueue *pArrivalQueue = NULL, *pWaitQueue = NULL;
    QueueNode *pServiceNode1 = NULL;

    pArrivalQueue = createLinkedQueue();
    pWaitQueue = createLinkedQueue();
    if (pArrivalQueue == NULL || pWaitQueue == NULL) {
        printf("createLinkedQueue()\n");
        return FALSE;
    }

    insertCutomer(0, 3, pArrivalQueue);
    insertCutomer(1, 1, pArrivalQueue);
    insertCutomer(2, 1, pArrivalQueue);
    insertCutomer(2, 2, pArrivalQueue);
    insertCutomer(3, 2, pArrivalQueue);
    insertCutomer(3, 1, pArrivalQueue);
    insertCutomer(4, 5, pArrivalQueue);
    insertCutomer(5, 1, pArrivalQueue);
    insertCutomer(6, 2, pArrivalQueue);
    insertCutomer(8, 3, pArrivalQueue);

    for (currentTime = 0; currentTime < endTime; currentTime++) {
        processArrival(currentTime, pArrivalQueue, pWaitQueue);

        if (pServiceNode1 != NULL) {
            pServiceNode1 = processServiceNodeEnd(currentTime,
                                                  pServiceNode1, &serviceUserCount, &totalWaitTime);
        }

        if (pServiceNode1 == NULL) {
            pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
        }

        printWaitQueueStatus(currentTime, pWaitQueue);
    }

    printReport(pWaitQueue, serviceUserCount, totalWaitTime);

    if (pServiceNode1 != NULL) {
        free(pServiceNode1);
    }
    deleteLinkedQueue(pArrivalQueue);
    deleteLinkedQueue(pWaitQueue);
}