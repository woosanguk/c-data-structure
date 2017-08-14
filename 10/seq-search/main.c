#include <stdio.h>
#include <stdlib.h>
#include "seqsearch.h"

int main() {
    int index = 0;
    int key = 0;
    int notSortedArray[] = {80, 50, 70, 10, 60, 20};
    int ascSortedArray[] = {10, 20, 50, 60, 70, 80};

    showArray(notSortedArray, 6);

    key = 70;
    index = sequentialSearchNotSorted(notSortedArray, 6, key);
    if (index >= 0) {
        printf("key = %d, index = %d\n", key, index);
    }

    key = 25;
    index = sequentialSearchNotSorted(notSortedArray, 6, key);
    if (index < 0) {
        printf("key = %d, not!!!\n", key);
    }

    showArray(ascSortedArray, 6);

    key = 70;
    index = sequentialSearchAsendingSorted(ascSortedArray, 6, key);
    if (index >= 0) {
        printf("key = %d, index = %d\n", key, index);
    }

    key = 25;
    index = sequentialSearchAsendingSorted(ascSortedArray, 6, key);
    if (index < 0) {
        printf("key = %d, not!!!\n", key);
    }

    return 0;
}
