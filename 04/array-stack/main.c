#include <stdio.h>
#include "arraystack.h"

int main() {
    Stack *pStack = createStack(4);
    StackNode node;

    node.data = 'a';

    push(pStack, node);

    printf("%c ", peek(pStack)->data);

    printf("%c ", pop(pStack)->data);

    node.data = 'b';

    push(pStack, node);
    node.data = 'c';

    push(pStack, node);
    node.data = 'd';

    push(pStack, node);

    printf("%c ", pop(pStack)->data);
    printf("%c ", pop(pStack)->data);
    printf("%c ", pop(pStack)->data);

    deleteStack(pStack);


    return 0;
}