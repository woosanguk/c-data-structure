//
// Created by sanguk on 16/08/2017.
//

#ifndef STATIC_HASHING_LIST_HASHINGDEF_H
#define STATIC_HASHING_LIST_HASHINGDEF_H

#define HASH_KEY_SIZE 10

typedef struct HashElementType {
    char key[HASH_KEY_SIZE + 1];
    int value;
} HashElement;

#endif //STATIC_HASHING_LIST_HASHINGDEF_H
