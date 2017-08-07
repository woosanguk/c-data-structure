#include <stdio.h>
#include "linkedstack.h"
#include "stackutil.h"

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
        node.data = 'e';
        push(pStack, node);

        printf("%c ", peek(pStack)->data);
        printf("%c ", pop(pStack)->data);
        printf("%c ", peek(pStack)->data);

        deleteStack(pStack);

        printf("\n");

        char testString[] = "woo sanguk";
        char *pReverseStr = reverseString(testString);
        printf("%s \n", pReverseStr);
        printf("result = %d \n", checkBracketMatching("()"));
        printf("result = %d \n", checkBracketMatching("(}"));
        printf("result = %d \n", checkBracketMatching("(({([()])}))"));
        printf("result = %d \n", checkBracketMatching("(({([()])})}"));
        printf("result = %d \n", checkBracketMatching("(({([()])}))]"));

    }

    return 0;
}