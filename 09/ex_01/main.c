#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct NodeType {
    int key;
    char secondKey;
} Node;

Node createNode(int key, char secondKey) {
    Node node = {0,};
    node.key = key;
    node.secondKey = secondKey;
    return node;
}

Node *createArray(int arrayCount) {
    Node *pReturn = NULL;
    pReturn = (Node *) malloc(sizeof(Node) * arrayCount);
    if (pReturn == NULL) return NULL;

    pReturn[0] = createNode(70, ' ');
    pReturn[1] = createNode(50, ' ');
    pReturn[2] = createNode(80, ' ');
    pReturn[3] = createNode(60, 'a');
    pReturn[4] = createNode(30, ' ');
    pReturn[5] = createNode(90, ' ');
    pReturn[6] = createNode(60, 'b');
    pReturn[7] = createNode(40, ' ');

    return pReturn;
}

void printArray(Node *pNode, int arrayCount) {
    for (int i = 0; i < arrayCount; i++) {
        printf("key = %d, secondKey = %c ", pNode[i].key, pNode[i].secondKey);
    }
    printf("\n");
}

int compare(Node nodeA, Node nodeB) {
    if (nodeA.key > nodeB.key) return TRUE;
    else if (nodeA.key == nodeB.key) {
        if (nodeA.secondKey > nodeB.secondKey) return TRUE;
    }
    return FALSE;
}

void swap(Node *nodeA, Node *nodeB) {
    Node temp = *nodeB;
    *nodeB = *nodeA;
    *nodeA = temp;
}

void insertionSort(Node *pNode, int arrayCount) {
    int i = 0, j = 0;
    for (i = 1; i < arrayCount; i++) {
        Node temp = pNode[i];
        j = i;
        while ((j > 0) && compare(pNode[j - 1], temp) == TRUE) {
            pNode[j] = pNode[j - 1];
            j--;
        }
        swap(&(pNode[j]), &(temp));
    };
}

void BubbleSort(Node *pNode, int arrayCount) {
    int i = 0, j = 0;
    for (i = arrayCount - 1; i > 0; i--) {
        for (j = 1; j <= i; j++) {
            if (compare(pNode[j - 1], pNode[j]) == TRUE) {
                swap(&pNode[j - 1], &pNode[j]);
            }
        };
    }
}

void selectionSort(Node *pNode, int arrayCount) {
    for (int i = 0; i < arrayCount; i++) {
        for (int j = i; j < arrayCount; j++) {
            if (compare(pNode[i], pNode[j]) == TRUE) {
                swap(&pNode[i], &pNode[j]);
            }
        }
    }
}


void shellInsertion(Node *pNode, int start, int end, int interval) {
    int i = 0, index = 0;
    Node item;
    for (i = start + interval; i <= end; i = i + interval) {
        item = pNode[i];
        index = i - interval;
        while ((index >= start) && compare(pNode[index], item) == TRUE) {
            pNode[index + interval] = pNode[index];
            index = index - interval;
        }
        pNode[index + interval] = item;
    }
}

void ShellSort(Node *pNode, int arrayCount) {
    int i = 0, interval = 0;
    interval = arrayCount / 2;
    while (interval >= 1) {
        for (i = 0; i < interval; i++) {
            shellInsertion(pNode, i, arrayCount - i, interval);
        }
        interval = interval / 2;
    }
}


void testSelectionSort(int arrayCount) {
    printf("===testSelectionSort===\n");
    Node *pNode = NULL;
    pNode = createArray(arrayCount);
    if (pNode == NULL) return;
    printArray(pNode, arrayCount);
    selectionSort(pNode, arrayCount);
    printArray(pNode, arrayCount);
    free(pNode);
}

void testBubbleSort(int arrayCount) {
    printf("===testBubbleSort===\n");
    Node *pNode = NULL;
    pNode = createArray(arrayCount);
    if (pNode == NULL) return;
    printArray(pNode, arrayCount);
    BubbleSort(pNode, arrayCount);
    printArray(pNode, arrayCount);
    free(pNode);
}

void testInsertionSort(int arrayCount) {
    printf("===testInsertionSort===\n");
    Node *pNode = NULL;
    pNode = createArray(arrayCount);
    if (pNode == NULL) return;
    printArray(pNode, arrayCount);
    insertionSort(pNode, arrayCount);
    printArray(pNode, arrayCount);
    free(pNode);
}

void testShellSort(int arrayCount) {
    printf("===testShellSort===\n");
    Node *pNode = NULL;
    pNode = createArray(arrayCount);
    if (pNode == NULL) return;
    printArray(pNode, arrayCount);
    ShellSort(pNode, arrayCount);
    printArray(pNode, arrayCount);
    free(pNode);
}

int main() {
    int arrayCount = 8;
    testInsertionSort(arrayCount);
    testBubbleSort(arrayCount);
    testSelectionSort(arrayCount);
    testShellSort(arrayCount);
    return 0;
}