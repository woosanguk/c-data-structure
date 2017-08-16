//
// Created by sanguk on 16/08/2017.
//

#ifndef STATIC_HASHING_STATICHASHING_H
#define STATIC_HASHING_STATICHASHING_H

#define TRUE 1
#define FALSE 0
#define HASH_KEY_SIZE	30

typedef enum HashElementStatusType { EMPTY = 0, USED, DELETED  } HashElementStatus;

typedef struct HashElementType {
    char key[HASH_KEY_SIZE + 1];
    int value;
    HashElementStatus status;
} HashElement;

typedef struct HashTableType {
    int bucketSize;
    int currentElementCount;
    HashElement *pElement;
} HashTable;

HashTable* createHashTable(int bucketSize);

int addElementSHT(HashTable* pHashTable, HashElement element);

int deleteElementHT(HashTable* pHashTable, char* key);

int hashFunction(char *pKey, int bucketSize);

unsigned int stringToInt(char *pKey);

int isEmptyBucket(HashElement* pElement);

int isEmptyOrDeletedBucket(HashElement* pElement);

HashElement* searchHT(HashTable* pHashTable, char* key);

void displayHashTable(HashTable *pHashTable);

int getElementCountHT(HashTable *pHashTable);

void deleteHashTable(HashTable *pHashTable);

#endif //STATIC_HASHING_STATICHASHING_H
