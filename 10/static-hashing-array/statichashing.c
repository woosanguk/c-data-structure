//
// Created by sanguk on 16/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "statichashing.h"

HashTable *createHashTable(int bucketSize) {
    HashTable *pReturn = NULL;
    if (bucketSize < 1) return NULL;
    pReturn = (HashTable *) malloc(sizeof(HashTable));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(HashTable));
    pReturn->bucketSize = bucketSize;
    pReturn->pElement = (HashElement *) malloc(sizeof(HashElement) * bucketSize);
    if (pReturn->pElement == NULL) {
        free(pReturn);
        return NULL;
    }
    memset(pReturn->pElement, 0, sizeof(HashElement) * bucketSize);
    return pReturn;
}

int addElementSHT(HashTable *pHashTable, HashElement element) {
    int bucketIndex = 0, tempIndex = 0, inc = 1;
    HashElement *pElement = NULL;
    if (pHashTable == NULL) return FALSE;
    bucketIndex = hashFunction(element.key, pHashTable->bucketSize);
    if (bucketIndex < 0 || bucketIndex >= pHashTable->bucketSize) return FALSE;
    tempIndex = bucketIndex;
    do {
        pElement = &(pHashTable->pElement[tempIndex]);
        if (isEmptyOrDeletedBucket(pElement) == TRUE) {
            pHashTable->pElement[tempIndex] = element;
            pHashTable->pElement[tempIndex].status = USED;
            pHashTable->currentElementCount++;
            break;
        } else {
            if (strcmp(pElement->key, element.key) == 0) {
                return FALSE;
            } else {
                tempIndex = (tempIndex + inc) % pHashTable->bucketSize;
                if (tempIndex == bucketIndex) return FALSE;
            }
        }

    } while (tempIndex != bucketIndex);

    return TRUE;
}

int deleteElementHT(HashTable *pHashTable, char *key){
    int ret = FALSE;
    HashElement *pElement = NULL;
    if (pHashTable == NULL) return ret;

    pElement = searchHT(pHashTable, key);
    if (pElement != NULL) {
        pElement->status = DELETED;
        pElement->key[0] = '\0';
        pElement->value = 0;
        pHashTable->currentElementCount--;
        ret = TRUE;
    }

    return ret;
}

int hashFunction(char *pKey, int bucketSize) {
    int ret = -1;
    unsigned int temp_key = 0;
    if (pKey == NULL) return ret;
    temp_key = stringToInt(pKey);
    if (bucketSize > 0) {
        ret = temp_key % bucketSize;
    }
    return ret;
}

unsigned int stringToInt(char *pKey) {
    int ret = 0;
    while (*pKey != '\0') {
        ret = (ret * 31) + (*pKey);
        *pKey++;
    }
    if (ret < 0) {
        ret = ret * (-1);
    }
    return ret;
}

int isEmptyBucket(HashElement *pElement){
    if (pElement == NULL) return FALSE;
    if (pElement->status == EMPTY) return TRUE;
    return FALSE;
}

int isEmptyOrDeletedBucket(HashElement *pElement) {
    if (pElement == NULL) return FALSE;
    if (pElement->status == EMPTY || pElement->status == DELETED) return TRUE;
    return FALSE;
}

HashElement *searchHT(HashTable *pHashTable, char *key) {
    HashElement *pReturn = NULL;
    HashElement *pElement = NULL;
    int bucketIndex = 0;
    int tempIndex = 0;
    int inc = 1;
    if (pHashTable == NULL) return NULL;
    bucketIndex = hashFunction(key, pHashTable->bucketSize);
    if (bucketIndex < 0) return NULL;
    tempIndex = bucketIndex;
    do {
        pElement = &(pHashTable->pElement[tempIndex]);
        if (isEmptyBucket(pElement) == TRUE) return NULL;
        else {
            if (pElement->status == USED
                && strcmp(pElement->key, key) == 0) {
                pReturn = pElement;
                break;
            } else {
                tempIndex = (tempIndex + inc) % pHashTable->bucketSize;
                if (tempIndex == bucketIndex) {
                    return NULL;
                }
            }
        }
    } while (tempIndex != bucketIndex);
    return pReturn;
}

void displayHashTable(HashTable *pHashTable) {
    int i = 0, j = 0;
    int bucketIndex = 0;

    HashElement *pElement = NULL;
    if (pHashTable == NULL) return;

    printf("-----------------------------------------\n");

    for (i = 0; i < pHashTable->bucketSize; i++) {
        printf("[%d],", i);
        pElement = &(pHashTable->pElement[i]);
        if (pElement->key[0] != '\0') {
            bucketIndex = hashFunction(pElement->key, pHashTable->bucketSize);
            printf("%s, (%d->%d), [%d]\n", pElement->key,
                   bucketIndex, i,
                   pElement->value);
        } else {
            printf("Empty\n");
        }
    }
    printf("-----------------------------------------\n");

}

int getElementCountHT(HashTable *pHashTable);

void deleteHashTable(HashTable *pHashTable) {
    if (pHashTable == NULL) return;
    if (pHashTable->pElement != NULL) free(pHashTable->pElement);
    free(pHashTable);
}