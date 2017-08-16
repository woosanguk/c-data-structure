//
// Created by sanguk on 16/08/2017.
//

#ifndef STATIC_HASHING_LIST_STATICHASHING_H
#define STATIC_HASHING_LIST_STATICHASHING_H

#define TRUE 1
#define FALSE 0

typedef struct HashTableType {
    int bucketSize;
    int currentElementCount;
    struct LinkedListType **ppElement;
} HashTable;

HashTable *createHashTable(int bucketSize);

int addSHT(HashTable *pHashTable, HashElement element);

int deleteElementHT(HashTable *pHashTable, char *key);

int hashFunction(char *pKey, int bucketSize);

unsigned int stringToInt(char *pKey);

HashElement *searchHT(HashTable *pHashTable, char *key);

LinkedList *searchBucket(HashTable *pHashTable, char *key);

HashElement *searchSlot(LinkedList *pList, char *key, int *pPostion);

void deleteHashTable(HashTable *pHashTable);

void displayHashTable(HashTable *pHashTable);

#endif //STATIC_HASHING_LIST_STATICHASHING_H
