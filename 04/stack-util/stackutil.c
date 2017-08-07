//
// Created by sanguk on 07/08/2017.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackutil.h"
#include "linkedstack.h"

char *reverseString(char *pSource) {
    char *pReturn = NULL;
    int size = 0;
    size = strlen(pSource);
    if (size < 1) return NULL;
    pReturn = (char *) malloc(sizeof(char) * (size + 1));
    Stack *pStack = createStack();
    StackNode node;
    if (pStack == NULL) return NULL;
    for (int i = 0; i < size; i++) {
        node.data = pSource[i];
        push(pStack, node);
    }
    StackNode *pNode;
    for (int i = 0; i < size; i++) {
        pNode = pop(pStack);
        pReturn[i] = pNode->data;
        free(pNode);
    }
    deleteStack(pStack);
    return pReturn;
}

int checkBracketMatching(char *pSource) {
    printf("checkBracketMatching\n");
    int size = 0;
    char item;
    size = strlen(pSource);
    if (size < 1) return FALSE;
    Stack *pStack = createStack();
    StackNode node;
    StackNode *pNode;
    for (int i = 0; i < size; i++){
        item = pSource[i];
        if (item == '(' || item == '{' || item == '[') {
            node.data = item;
            push(pStack, node);
        } else {
            if (isEmptyStack(pStack) == TRUE) return FALSE;
            pNode = pop(pStack);
            if (pNode->data == '(' && item == ')'){

            }else if (pNode->data == '{' && item == '}'){

            }else if (pNode->data == '[' && item == ']'){

            } else {
                return FALSE;
            }
        }
    }

    if (isEmptyStack(pStack) == FALSE) return FALSE;

    return TRUE;
}