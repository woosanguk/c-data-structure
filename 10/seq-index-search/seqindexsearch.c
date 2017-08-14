//
// Created by sanguk on 14/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "seqindexsearch.h"

int sequentialIndexSearch(int value[], int size,
                          IndexTable index[], int indexSize, int key) {
    int ret = FAIL;
    int i = 0, start = 0, end = 0;
    if (key >= value[0] && key <= value[size - 1]) {
        for (i = 0; i < indexSize; i++) {
            if (index[i].key > key) {
                break;
            }
        }
        if (i >= indexSize) {
            start = index[i - 1].position;
            end = size - 1;
        } else {
            start = index[i - 1].position;
            end = index[i].position - 1;
        }
        ret = sequentialRangeSearchAsendingSorted(value, start, end, key);
    }
    return ret;
}

int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key) {
    int ret = FAIL;
    int i = 0;
    for (i = start; i <= end && value[i] < key; i++) {
        // do nothing.
    }

    if (i <= end && value[i] == key) {
        ret = i;
    }

    return ret;
}

IndexTable *createIndexTable(int value[], int size, int indexSize) {
    int ratio = 0;
    IndexTable *pReturn = NULL;
    pReturn = (IndexTable *) malloc(sizeof(IndexTable) * indexSize);
    if (pReturn == NULL) return NULL;
    ratio = size / indexSize;

    for (int i = 0; i < indexSize; i++) {
        pReturn[i].position = i * ratio;
        pReturn[i].key = value[i * ratio];
    };
    return pReturn;
}

void showIndexTable(IndexTable *pIndexTable, int indexSize) {
    printf("showIndexTable\n");
    printf("------------\n");
    for (int i = 0; i < indexSize; i++) {
        printf("[%d] %d\n", pIndexTable[i].position, pIndexTable[i].key);
    }
    return;
}