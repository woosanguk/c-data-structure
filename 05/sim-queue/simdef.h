//
// Created by sanguk on 11/08/2017.
//

#ifndef SIM_QUEUE_SIMDEF_H
#define SIM_QUEUE_SIMDEF_H

typedef enum SimStatusType { arrival, start, end } SimStatus;

typedef struct SimCustomerType
{
    SimStatus status;
    int arrivalTime;
    int serviceTime;
    int startTime;
    int endTime;
} SimCustomer;

#endif //SIM_QUEUE_SIMDEF_H
