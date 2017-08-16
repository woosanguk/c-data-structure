//
// Created by sanguk on 16/08/2017.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashingdef.h"
#include "hashinglinkedlist.h"
#include "statichashing.h"

int addLLElementLast(LinkedList *pList, HashElement element) {
    ListNode node = {0,};
    if (pList == NULL) return FALSE;
    node.data = element;
    return addLLElement(pList, getLinkedListLength(pList), node);;
}

HashTable *createHashTable(int bucketSize) {
    HashTable *pReturn = NULL;
    if (bucketSize < 1) return NULL;
    pReturn = (HashTable *) malloc(sizeof(HashTable));
    if (pReturn == NULL) return NULL;
    memset(pReturn, 0, sizeof(HashTable));
    pReturn->bucketSize = bucketSize;
    pReturn->ppElement = (HashElement **) malloc(sizeof(HashElement *) * bucketSize);
    if (pReturn->ppElement == NULL) {
        free(pReturn);
        return NULL;
    }
    for (int i = 0; i < bucketSize; i++) {
        pReturn->ppElement[i] = createLinkedList();
        if (pReturn->ppElement[i] == NULL) {
            for (int j = 0; j < i - 1; j++) {
                if (pReturn->ppElement[j] != NULL) free(pReturn->ppElement[j]);
            }
            if (pReturn->ppElement != NULL) free(pReturn->ppElement);
            if (pReturn != NULL) free(pReturn);
            return NULL;
        }
    }
    return pReturn;
}

int addSHT(HashTable *pHashTable, HashElement element) {
    int ret = FALSE;
    LinkedList *pList = NULL;
    if (pHashTable == NULL) return FALSE;
    pList = searchBucket(pHashTable, element.key);
    if (pList == NULL) return FALSE;
    addLLElementLast(pList, element);
    pHashTable->currentElementCount++;
    return TRUE;
}

int deleteElementHT(HashTable *pHashTable, char *key){
    int ret = FALSE;

    HashElement *pElement = NULL;
    LinkedList* pList = NULL;
    int position = 0;

    pList = searchBucket(pHashTable, key);
    if (pList != NULL) {
        pElement = searchSlot(pList, key, &position);
        if (pElement != NULL) {
            removeLLElement(pList, position);
            pHashTable->currentElementCount--;
            ret = TRUE;
        }
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
    unsigned int ret = 0;
    while (*pKey != '\0') {
        ret = (ret * 31) + (*pKey);
        *pKey++;
    }
    if (ret < 0) {
        ret = ret * (-1);
    }
    return ret;
}

HashElement *searchHT(HashTable *pHashTable, char *key){
    HashElement* pReturn = NULL;
    LinkedList* pList = NULL;
    int position = 0;
    if (pHashTable == NULL) return NULL;
    pList = searchBucket(pHashTable, key);
    if (pList == NULL) return NULL;
    pReturn = searchSlot(pList, key, &position);
    return pReturn;
}

LinkedList *searchBucket(HashTable *pHashTable, char *key) {
    LinkedList *pReturn = NULL;
    int bucketIndex = 0;
    if (pHashTable == NULL) return NULL;
    bucketIndex = hashFunction(key, pHashTable->bucketSize);
    if (bucketIndex >= 0) {
        pReturn = pHashTable->ppElement[bucketIndex];
    }
    return pReturn;
}

HashElement *searchSlot(LinkedList *pList, char *key, int *pPostion){
    HashElement* pReturn = NULL;
    HashElement *pElement = NULL;
    ListNode* pNode = NULL;
    int position = 0;
    if (pList == NULL || pPostion == NULL) return NULL;
    pNode = getLLElement(pList, 0);
    while(pNode != NULL){
        if (strcmp(pNode->data.key, key) == 0){
            pReturn = &(pNode->data);
            *pPostion = position;
            break;
        }
        pNode = pNode->pLink;
        position++;
    }
    return pReturn;
}

void deleteHashTable(HashTable *pHashTable) {
    int i = 0;
    if (pHashTable == NULL) return;
    for (i = 0; i < pHashTable->bucketSize; i++) {
        deleteLinkedList(pHashTable->ppElement[i]);
    }
    free(pHashTable->ppElement);
    free(pHashTable);
}

void displayHashTable(HashTable *pHashTable) {
    int i = 0, j = 0;
    int slotSize = 0;
    LinkedList *pList = NULL;
    ListNode *pNode = NULL;
    HashElement *pElement = NULL;
    if (pHashTable == NULL) return;
    for (i = 0; i < pHashTable->bucketSize; i++) {
        printf("[%d]", i);
        pList = pHashTable->ppElement[i];
        slotSize = getLinkedListLength(pList);
        if (slotSize == 0) {
            printf(",Empty \n");
        } else {
            for (j = 0; j < slotSize; j++) {
                pNode = getLLElement(pList, j);
                if (pNode != NULL) {
                    pElement = &(pNode->data);
                    printf(",(%s, %d) ", pElement->key, pElement->value);
                }
            }
            printf("\n");
        }
    }

}