#include <stdio.h>
#include <stdlib.h>
#include "hashingdef.h"
#include "hashinglinkedlist.h"
#include "statichashing.h"

int main() {
    HashTable *pHashTable = NULL;
    HashElement element1 = {"january", 1};
    HashElement element2 = {"february", 2};
    HashElement element3 = {"march", 3};
    HashElement element4 = {"april", 4};
    HashElement element5 = {"may", 5};
    HashElement element6 = {"june", 6};
    HashElement element7 = {"july", 7};
    HashElement element8 = {"august", 8};
    HashElement element9 = {"september", 9};
    HashElement element10 = {"october", 10};
    HashElement element11 = {"november", 11};
    HashElement element12 = {"december", 12};
    HashElement element13 = {"may", 13};
    HashElement *pElement = NULL;
    HashElement *pElement2 = NULL;

    pHashTable = createHashTable(13);
    if (pHashTable != NULL) {
        addSHT(pHashTable, element1);
        addSHT(pHashTable, element2);
        addSHT(pHashTable, element3);
        addSHT(pHashTable, element4);
        addSHT(pHashTable, element5);
        addSHT(pHashTable, element6);
        addSHT(pHashTable, element7);
        addSHT(pHashTable, element8);
        addSHT(pHashTable, element9);
        addSHT(pHashTable, element10);
        addSHT(pHashTable, element11);
        addSHT(pHashTable, element12);
        addSHT(pHashTable, element13);

        displayHashTable(pHashTable);

        pElement = searchHT(pHashTable, "april");
        if (pElement != NULL) {
            printf("key = %s, value = %d\n", pElement->key, pElement->value);
            deleteElementHT(pHashTable, "april");
            displayHashTable(pHashTable);

            pElement2 = searchHT(pHashTable, "june");
            if (pElement2 != NULL) {
                printf("key = %s, value = %d\n", pElement->key, pElement->value);
            }
        }

        deleteHashTable(pHashTable);
    }
    return 0;
}