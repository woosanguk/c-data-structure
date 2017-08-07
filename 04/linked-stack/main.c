#include <stdio.h>
#include "linkedstack.h"

int main() {
    Stack *pStack = createStack();
    StackNode node;
    if (pStack != NULL){
        node.data = 'a';
        push(pStack, node);
        node.data = 'b';
        push(pStack, node);
        node.data = 'c';
        push(pStack, node);
        node.data = 'd';
        push(pStack, node);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        deleteStack(pStack);
    }
    return 0;
}