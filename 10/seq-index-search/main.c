#include <stdio.h>
#include <stdlib.h>
#include "seqindexsearch.h"

void showArray(int value[], int size) {
    int i = 0;

    printf("showArray\n");
    printf("------------\n");
    for (i = 0; i < size; i++) {
        printf("[%d] %d\n", i, value[i]);
    }
}


int main() {

    IndexTable *pIndexTable = NULL;
    int indexSize = 3;
    int index = 0;
    int key = 0;
    int ascSortedArray[] = {10, 20, 50, 60, 70, 80};
    int arraySize = 6;

    showArray(ascSortedArray, arraySize);
    pIndexTable = createIndexTable(ascSortedArray, arraySize, indexSize);

    if (pIndexTable != NULL) {
        showIndexTable(pIndexTable, indexSize);

        key = 60;
        index = sequentialIndexSearch(ascSortedArray, arraySize, pIndexTable, indexSize, key);
        printf("key = %d, index = %d\n", key, index);

        key = 65;
        index = sequentialIndexSearch(ascSortedArray, arraySize, pIndexTable, indexSize, key);
        printf("key = %d, index = %d\n", key, index);

        free(pIndexTable);
    }

    return 0;
}