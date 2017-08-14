//
// Created by sanguk on 14/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqsearch.h"

int sequentialSearchNotSorted(int value[], int size, int key) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (value[i] == key) {
            return index;
        }
        index++;
    }
    return -1;
}

int sequentialSearchAsendingSorted(int value[], int size, int key) {
    int index = 0;
    for (int i = 0; i < size; i++) {
        if (value[i] == key) {
            return index;
        }
        if (value[i] > key) {
            break;
        }
        index++;
    }

    return -1;
}

void showArray(int value[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", value[i]);
    }
    printf("\n");
}
