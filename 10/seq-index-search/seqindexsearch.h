//
// Created by sanguk on 14/08/2017.
//

#ifndef SEQ_INDEX_SEARCH_SEQINDEXSEARCH_H
#define SEQ_INDEX_SEARCH_SEQINDEXSEARCH_H

#define TRUE        1
#define FALSE        0
#define FAIL        -1

typedef struct IndexTableType {
    int position;
    int key;
} IndexTable;

int sequentialIndexSearch(int value[], int size,
                          IndexTable index[], int indexSize, int key);

int sequentialRangeSearchAsendingSorted(int value[], int start, int end, int key);

IndexTable *createIndexTable(int value[], int size, int indexSize);

void showIndexTable(IndexTable *pIndexTable, int indexSize);

#endif //SEQ_INDEX_SEARCH_SEQINDEXSEARCH_H
