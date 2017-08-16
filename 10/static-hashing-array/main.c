#include <stdio.h>
#include <stdlib.h>
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
    HashElement *pElement = NULL;
    HashElement *pElement2 = NULL;
    pHashTable = createHashTable(13);
    if (pHashTable != NULL) {

        addElementSHT(pHashTable, element1);
        addElementSHT(pHashTable, element2);
        addElementSHT(pHashTable, element3);
        addElementSHT(pHashTable, element4);
        addElementSHT(pHashTable, element5);
        addElementSHT(pHashTable, element6);
        addElementSHT(pHashTable, element7);
        addElementSHT(pHashTable, element8);
        addElementSHT(pHashTable, element9);
        addElementSHT(pHashTable, element10);
        addElementSHT(pHashTable, element11);
        addElementSHT(pHashTable, element12);

        displayHashTable(pHashTable);

        pElement = searchHT(pHashTable, "april");
        if (pElement != NULL) {
            printf("key = %s, value = %d\n", pElement->key, pElement->value);
            deleteElementHT(pHashTable, "april");
            displayHashTable(pHashTable);
        }

        deleteHashTable(pHashTable);
    }
    return 0;
}